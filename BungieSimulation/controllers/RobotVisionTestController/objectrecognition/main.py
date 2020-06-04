import numpy as np
import cv2
import time

from ObjectRecognitionController import ObjectRecognitionController
from ObjectRecognitionObserver import ObjectRecognitionObserver
from ObjectRecognitionType import ObjectRecognitionType
from DetectData import QrData
from DetectData import CardData

frame = None

def getQrCode(_data):
    print(_data.getText())

def getCards(_data):
    #print(_data)
    for card in _data:
        cv2.drawContours(frame, [card.getPoints()], -1, (0,255,255), 3)
        M = cv2.moments(card.getPoints())
        cX = int((M["m10"] / M["m00"]) * 1)
        cY = int((M["m01"] / M["m00"]) * 1)
        cv2.putText(frame, str(card.getCardType()).split('.')[1], (cX, cY), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (127, 137, 137), 2)


objRec = ObjectRecognitionController()
objObserverA = ObjectRecognitionObserver(ObjectRecognitionType.QR, getQrCode)
#objObserverB = ObjectRecognitionObserver(ObjectRecognitionType.CARD, getCards)

objRec.registerObserver(objObserverA)
#objRec.registerObserver(objObserverB)

cap = cv2.VideoCapture(0)

print("start detecting")
while True:
    #ret, frame = cap.read()
    frame = cv2.imread('qr_code.png')

    frame = objRec.detect(frame)

    cv2.imshow('frame', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

exit()
