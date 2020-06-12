import numpy as np
import cv2

from DetectData import TemperatureType
from DetectData import QrData
from DetectData import CardData
from DetectData import MineralData
from DetectData import TemperatureData
from ObjectRecognitionImageFactory import ObjectRecognitionImageFactory
from ObjectRecognitionType import ObjectRecognitionType
from ObjectRecognitionCardType import ObjectRecognitionCardType

"""A factory for  handeling all the recognition calculations"""
class ObjectRecognitionFactory:

    """Detect a QR code"""
    def detectQrCode(frame):
        decodedText, points, _ = cv2.QRCodeDetector().detectAndDecode(frame)
        if points is not None:
            return QrData(ObjectRecognitionType.QR, decodedText, points)
        else:
            return None

    """Detect a temperature by a color range"""
    def detectTemperature(frame):
        hls = cv2.cvtColor(frame, cv2.COLOR_BGR2HLS)
        height, width, depth = hls.shape

        size_w = 50
        size_h = 50
        y = height//2;
        x = width//2;
        tiny_image = hls[y-size_h:y+size_h, x-size_w:x+size_w]

        temp = tiny_image
        for i in range(0, size_h*2):             #looping at python speed...
         for j in range(0, (size_w*2)):     #...
             for k in range(1,depth):       #...
                 temp[i,j,k] = 0
                 #if k == 1 and i == 1:
                     #print(temp[i,j*4,0])

        koud = ObjectRecognitionFactory.checkTemperature(tiny_image, cv2.inRange(temp, np.array([50,0,0]), np.array([120, 0, 0])))#KOUD !
        lauw = ObjectRecognitionFactory.checkTemperature(tiny_image, cv2.inRange(temp, np.array([32,0,0]), np.array([45, 0, 0]))) #LAUW
        warm = ObjectRecognitionFactory.checkTemperature(tiny_image, cv2.inRange(temp, np.array([23,0,0]), np.array([30, 0, 0]))) #LAUW
        heet = ObjectRecognitionFactory.checkTemperature(tiny_image, cv2.inRange(temp, np.array([0,0,0]), np.array([23, 0, 0]))) #HEET !

        #print("koud: " + str(koud) + " lauw: " + str(lauw) + " warm: " + str(warm) + " heet: " + str(heet))

        if koud:
            return TemperatureData(ObjectRecognitionType.TEMPERATURE, TemperatureType.KOUD)
        if lauw:
            return TemperatureData(ObjectRecognitionType.TEMPERATURE, TemperatureType.LAUW)
        if warm:
            return TemperatureData(ObjectRecognitionType.TEMPERATURE, TemperatureType.WARM)
        if heet:
            return TemperatureData(ObjectRecognitionType.TEMPERATURE, TemperatureType.HEET)

        return None;

    """Check the temperature based on the avarage color in cropt frame"""
    def checkTemperature(frame, mask):
        res = cv2.bitwise_and(frame, frame, mask= mask)
        avg_color_per_row = np.average(res, axis=0)
        avg_color = np.average(avg_color_per_row, axis=0)
        return avg_color[0] != 0

    """Detect cards using color"""
    def detectCards(frame):
        # filter red cards
        redFrame = ObjectRecognitionImageFactory.filterColorRed(frame)
        redFrameProcesed = cv2.cvtColor(redFrame, cv2.COLOR_BGR2GRAY)

        # filter black cards
        blackFrame = ObjectRecognitionImageFactory.filterColorBlack(frame)
        blackFrameBlur = cv2.medianBlur(frame,5)
        ret, th1 = cv2.threshold(blackFrameBlur, 200, 255, cv2.THRESH_BINARY)
        blackFrameProcesed = cv2.cvtColor(th1, cv2.COLOR_BGR2GRAY)

        cards = []
        cards = np.concatenate((cards, ObjectRecognitionFactory.detectCardType(redFrameProcesed, 0)))
        cards = np.concatenate((cards, ObjectRecognitionFactory.detectCardType(blackFrameProcesed, 1)))

        return cards

    """Detect card type using color/size/lines"""
    def detectCardType(frame, filterMode): # 0 == red, 1 == black
        cards = []
        contours, hierarchy = cv2.findContours(frame, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        for cnt in contours:
            area = cv2.contourArea(cnt)
            if area < 5000 or area > 15000:
                continue
            #print(str(area) + "\n")
            type = ObjectRecognitionCardType.NONE
            peri = cv2.arcLength(cnt, True)
            approx = cv2.approxPolyDP(cnt, 0.04 * peri, True)

            if len(approx) == 4:
                if filterMode == 0: type = ObjectRecognitionCardType.RUITEN
                if filterMode == 1: type = ObjectRecognitionCardType.SCHOPPEN
            if len(approx) == 5:
                if filterMode == 0: type = ObjectRecognitionCardType.HARTEN
                if filterMode == 1: type = ObjectRecognitionCardType.KLAVER
            if len(approx) == 6:
                if filterMode == 0: type = ObjectRecognitionCardType.HARTEN
                if filterMode == 1: type = ObjectRecognitionCardType.KLAVER

            print(str(type) + " / " + str(peri) + " / " + str(approx))

            cards.append(CardData(ObjectRecognitionType.CARD, type, cnt))
        return cards

    """Detect minerals"""
    def detectMineral(frame):
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        blur = cv2.medianBlur(gray,17)
        ret, th1 = cv2.threshold(blur, 130, 255, cv2.THRESH_BINARY)
        edges = cv2.Canny(blur,50,170)

        rect_kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (5, 30))
        edges = cv2.morphologyEx(edges, cv2.MORPH_CLOSE, rect_kernel)

        contours, hierarchy = cv2.findContours(edges, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)
        contours_poly = [None]*len(contours)
        boundRect = [None]*len(contours)
        centers = [None]*len(contours)
        radius = [None]*len(contours)
        mineral = None
        for i, c in enumerate(contours):
            area = cv2.contourArea(c)
            if area < 1000 or area > 30000:
                continue
            contours_poly[i] = cv2.approxPolyDP(c, 3, True)
            boundRect[i] = cv2.boundingRect(contours_poly[i])
            centers[i], radius[i] = cv2.minEnclosingCircle(contours_poly[i])
            #cv2.rectangle(frame, (int(boundRect[i][0]), int(boundRect[i][1])), (int(boundRect[i][0]+boundRect[i][2]), int(boundRect[i][1]+boundRect[i][3])), (0,0,255), 2)
            mineral = MineralData(ObjectRecognitionType.MINERAL, boundRect[i], centers[i], radius[i])

        return mineral
