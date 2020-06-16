import numpy as np
import cv2
import time

from ObjectRecognitionController import ObjectRecognitionController
from ObjectRecognitionObserver import ObjectRecognitionObserver
from ObjectRecognitionType import ObjectRecognitionType
from DetectData import QrData
from DetectData import CardData

frame = None

"""Qr code IObserver callback"""
def getQrCode(_data):
    print(_data.getText())

    points = _data.getPoints()
    nrOfPoints = len(points)

    for i in range(nrOfPoints):
        nextPointIndex = (i+1) % nrOfPoints
        cv2.line(frame, tuple(points[i][0]), tuple(points[nextPointIndex][0]), (255,0,0), 5)

"""Card code IObserver callback"""
def getCard(_data):
    #print(_data)
    for card in _data:
        cv2.drawContours(frame, [card.getPoints()], -1, (0,255,255), 3)
        M = cv2.moments(card.getPoints())
        cX = int((M["m10"] / M["m00"]) * 1)
        cY = int((M["m01"] / M["m00"]) * 1)
        cv2.putText(frame, str(card.getCardType()).split('.')[1], (cX, cY), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (127, 137, 137), 2)

"""Mineral code IObserver callback"""
def getMineral(_data):
    boundRect = _data.getBounds()
    if boundRect == None:
        return
    cv2.rectangle(frame, (int(boundRect[0]), int(boundRect[1])), (int(boundRect[0]+boundRect[2]), int(boundRect[1]+boundRect[3])), (0,0,255), 2)

"""Temperature code IObserver callback"""
def getTemperature(_data):
    print("Temperature: " + str(_data.getState()))

# Create ObjectRecognitionController
objRec = ObjectRecognitionController()

# Set IObservers
objObserverA = ObjectRecognitionObserver(ObjectRecognitionType.QR, getQrCode)
objObserverB = ObjectRecognitionObserver(ObjectRecognitionType.CARD, getCard)
objObserverC = ObjectRecognitionObserver(ObjectRecognitionType.MINERAL, getMineral)
objObserverD = ObjectRecognitionObserver(ObjectRecognitionType.TEMPERATURE, getTemperature)

# Regist all IObservers
objRec.registerObserver(objObserverA)
objRec.registerObserver(objObserverB)
objRec.registerObserver(objObserverC)
objRec.registerObserver(objObserverD)

print("start detecting")
index = 0
images = ['card_screenshot_webots_1.png', 'qr_screenshot_webots.png', 'mineraal_screenshot_webots_1.png', 'mineraal_screenshot_webots_2.png', 'water_screenshot_webots_1.png', 'water_screenshot_webots_2.png', 'water_screenshot_webots_3.png', 'water_screenshot_webots_4.png']
while True:
    frame = cv2.imread("img/" + images[index])
    frame = objRec.detect(frame)
    cv2.imshow('frame', frame)

    key = cv2.waitKey(0)
    if key == ord('q'):
        break

    if key == ord('w'):
        index += 1
        if index >= len(images):
            index = 0

    if key == ord('s'):
        index -= 1
        if index < 0:
            index = len(images) - 1

exit()
