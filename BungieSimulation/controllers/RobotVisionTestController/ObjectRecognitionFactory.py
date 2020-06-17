import numpy as np
import math
import cv2

from DetectData import TemperatureType
from DetectData import Vector2
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
            return QrData(ObjectRecognitionType.QR, decodedText, points, ObjectRecognitionFactory.calculateCenterValues(frame, points))
        else:
            return None

    """Detect a temperature by a color range"""
    def detectTemperature(frame):
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        height, width, depth = hsv.shape
        size_w = 50
        size_h = 50
        y = height//2;
        x = width//2;
        tiny_image = hsv[y-size_h:y+size_h, x-size_w:x+size_w]
        center_pixel = tiny_image[25, 25]
        temperature = TemperatureType.KOUD if center_pixel[0] >= 46 else TemperatureType.LAUW if center_pixel[1] < 97 else TemperatureType.WARM if center_pixel[0] >= 25 else TemperatureType.HEET
        return TemperatureData(ObjectRecognitionType.TEMPERATURE, temperature)
        
    def detectShape(ref_contour, contours, _draw=False):
        #print(len(ref_contour))
        current_value = math.inf
        current_contour = []
        for contour in contours:
            match = cv2.matchShapes(ref_contour[0], contour, 1, 0.0)
    
            if cv2.contourArea(contour) < 300 or cv2.contourArea(contour) > 100000:
                continue
    
            #print(match)
            if match <= current_value:
                current_value = match
                current_contour = [contour]
    
        if len(current_contour) != 0:
            return current_contour, current_value
            
        return None, None
            
    def detectCards(frame): # "./img/camera_club.png"
        # generate template contours
        cnt_diamond = ObjectRecognitionImageFactory.generateTemplateContours("./img/card-Ruiten.png")
        cnt_club = ObjectRecognitionImageFactory.generateTemplateContours("./img/card-Klaveren.png", _mode=cv2.THRESH_BINARY_INV)
        cnt_spades = ObjectRecognitionImageFactory.generateTemplateContours("./img/card-Schoppen.png", _mode=cv2.THRESH_BINARY_INV)
        cnt_heart = ObjectRecognitionImageFactory.generateTemplateContours("./img/card-Harten.png")

        # maby array?
        # create scan image and add image processes
        img_shapes = frame
        gsi_shapes = cv2.cvtColor(img_shapes, cv2.COLOR_BGR2GRAY)
        gsi_shapes = cv2.GaussianBlur(gsi_shapes, (13, 13), 0)
        gsi_shapes = cv2.threshold(gsi_shapes, 96, 255, cv2.THRESH_BINARY)[1]
        gsi_shapes = cv2.erode(gsi_shapes, None, iterations=2)
        gsi_shapes = cv2.dilate(gsi_shapes, None, iterations=1)
        # get contours of main image
        cnt_shapes, _ = cv2.findContours(gsi_shapes, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    
        c1, v1 = ObjectRecognitionFactory.detectShape(cnt_diamond, cnt_shapes)
        c2, v2 = ObjectRecognitionFactory.detectShape(cnt_club, cnt_shapes)
        c3, v3 = ObjectRecognitionFactory.detectShape(cnt_spades, cnt_shapes)
        c4, v4 = ObjectRecognitionFactory.detectShape(cnt_heart, cnt_shapes)
        
        match = math.inf
        cnt = None
        type = ObjectRecognitionCardType.NONE
        if v1 < match:
            match = v1
            cnt = c1
            type = ObjectRecognitionCardType.KLAVER
        if v2 < match:
            match = v2
            cnt = c2
            type = ObjectRecognitionCardType.RUITEN
        if v3 < match:
            match = v3
            cnt = c3
            type = ObjectRecognitionCardType.SCHOPPEN
        if v4 < match:
            match = v4
            cnt = c4
            type = ObjectRecognitionCardType.HARTEN
            
        if type == ObjectRecognitionCardType.NONE:
            return None
            
        center = ObjectRecognitionFactory.calculateCenterValues(frame, cnt)
        return CardData(ObjectRecognitionType.CARD, type, cnt, center)
            
        #if b == "CLUB":
        #    contours_poly = cv2.approxPolyDP(c2[0], 3, True)
        #    boundRect = cv2.boundingRect(contours_poly)
        #    x, y, w, h = boundRect
        #    crop_img = img_shapes[y:y+h, x:x+w] #Cropping
        #    crop_img = filterColorRed(crop_img)
        #    crop_img = cv2.cvtColor(crop_img, cv2.COLOR_BGR2GRAY)
        #    cnt_extra, _ = cv2.findContours(crop_img, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
        #    cv2.imshow("crop()->" + fileName, cv2.resize(crop_img, (512, 512)))
    
        #    if len(cnt_extra) > 0:
        #        b = "DIAMOND"
    
        #print("detectCards(" + b + ")->" + fileName + " diamond: " + str(v1) + " club: " + str(v2) + " spades: " + str(v3) + " hearts: " + str(v4))
        

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
        
    def calculateCenterValues(_frame, _points):
        center = ObjectRecognitionFactory.getCenterPoint(_points)
        height, width, channels = _frame.shape
        x = ObjectRecognitionFactory.translate(center.x, 0, width, -1, 1)
        y = ObjectRecognitionFactory.translate(center.y, 0, height, -1, 1)
        return Vector2(x, y)
    
    def getCenterPoint(_points):
        try:
            M = cv2.moments(_points)
            cX = int(M["m10"] / M["m00"])
            cY = int(M["m01"] / M["m00"])
            return Vector2(cX, cY)
        except:
            return Vector2(0.0, 0.0)
    
    def translate(value, leftMin, leftMax, rightMin, rightMax):
        leftSpan = leftMax - leftMin
        rightSpan = rightMax - rightMin
        
        valueScaled = float(value - leftMin) / float(leftSpan)
        
        return rightMin + (valueScaled * rightSpan)
        
