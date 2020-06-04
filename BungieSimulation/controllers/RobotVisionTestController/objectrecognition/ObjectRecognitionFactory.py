import numpy as np
import cv2

from DetectData import QrData
from DetectData import CardData
from ObjectRecognitionType import ObjectRecognitionType
from ObjectRecognitionCardType import ObjectRecognitionCardType

class ObjectRecognitionFactory:

    def detectQrCode(frame):
        decodedText, points, _ = cv2.QRCodeDetector().detectAndDecode(frame)
        if points is not None:
            return QrData(ObjectRecognitionType.QR, decodedText, points)
        else:
            return None

    def detectCards(frame):
        # filter red cards
        redFrame = ObjectRecognitionFactory.filterColorRed(frame)
        redFrameProcesed = cv2.cvtColor(redFrame, cv2.COLOR_BGR2GRAY)

        # filter black cards
        blackFrame = ObjectRecognitionFactory.filterColorBlack(frame)
        gray = cv2.cvtColor(blackFrame, cv2.COLOR_BGR2GRAY)
        mask = cv2.compare(gray, 5, cv2.CMP_LT)
        gray[mask > 0] = 255
        blackFrameProcesed = cv2.subtract(255, gray)
        blackFrameProcesed = cv2.blur(blackFrameProcesed, (20,20))

        cards = []
        cards = np.concatenate((cards, ObjectRecognitionFactory.detectCardType(redFrameProcesed, 0)))
        cards = np.concatenate((cards, ObjectRecognitionFactory.detectCardType(blackFrameProcesed, 1)))

        return cards


    def detectCardType(frame, filterMode): # 0 == red, 1 == black
        cards = []
        contours, hierarchy = cv2.findContours(frame, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        for cnt in contours:
            type = ObjectRecognitionCardType.NONE
            peri = cv2.arcLength(cnt, True)
            approx = cv2.approxPolyDP(cnt, 0.04 * peri, True)

            if len(approx) == 4:
                if filterMode == 0: type = ObjectRecognitionCardType.HARTEN
                if filterMode == 1: type = ObjectRecognitionCardType.SCHOPPEN
            if len(approx) == 5:
                if filterMode == 0: type = ObjectRecognitionCardType.RUITEN
                if filterMode == 1: type = ObjectRecognitionCardType.KLAVER

            print(str(type) + " / " + str(peri) + " / " + str(approx))

            cards.append(CardData(ObjectRecognitionType.CARD, type, cnt))
        return cards

    def detectMineral():
        pass

    def filterColorRed(frame):
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        mask_a = cv2.inRange(hsv, np.array([0,50,50]), np.array([10,255,255]))
        mask_b = cv2.inRange(hsv, np.array([170,50,50]), np.array([180,255,255]))
        mask = mask_a | mask_b
        res = cv2.bitwise_and(frame, frame, mask= mask)
        return res

    def filterColorBlack(frame):
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        mask = cv2.inRange(hsv, np.array([0,0,0]), np.array([50,50,100]))
        res = cv2.bitwise_and(frame, frame, mask= mask)
        return res
