import numpy as np
import cv2
import math

from ISubject import ISubject
from ObjectRecognitionFactory import ObjectRecognitionFactory
from ObjectRecognitionType import ObjectRecognitionType
from DetectData import QrData

"""Main object recognition controller"""
class ObjectRecognitionController(ISubject):

    def __init__(self):
        self.observers = []
        self.qrCodeDetector = cv2.QRCodeDetector()
        self.videoCapture = cv2.VideoCapture(0) # get cameras
        print("[ObjectRecognitionController] init()");

    """Main detection loop, detects all object and calls the used observers"""
    def detect(self, frame):
        # do qr code detection
        qrData = ObjectRecognitionFactory.detectQrCode(frame)
        if qrData is not None:
            self.notifyObservers(ObjectRecognitionType.QR, qrData)

        cardsData = ObjectRecognitionFactory.detectCards(frame)
        if len(cardsData) > 0:
            self.notifyObservers(ObjectRecognitionType.CARD, cardsData)

        mineralData = ObjectRecognitionFactory.detectMineral(frame)
        if mineralData is not None:
            self.notifyObservers(ObjectRecognitionType.MINERAL, mineralData)

        temperatureData = ObjectRecognitionFactory.detectTemperature(frame)
        if temperatureData is not None:
            self.notifyObservers(ObjectRecognitionType.TEMPERATURE, temperatureData)

        return frame

    """Remove all observer from the subject"""
    def removeAllObservers():
        self.observers = []

    def registerObserver(self, _observer):
        self.observers.append(_observer);
        pass

    def removeObserver(self, _observer):
        for i in len(self.observers):
            if self.observers[i] == _observer:
                self.observers.remove(_observer)
                return
        pass

    def notifyObservers(self, _type, _data):
        for observer in self.observers:
            if observer.type == _type:
                observer.update(_data);
