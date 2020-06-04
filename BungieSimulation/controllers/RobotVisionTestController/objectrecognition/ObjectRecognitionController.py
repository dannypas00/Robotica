import numpy as np
import cv2
import math

from ISubject import ISubject
from ObjectRecognitionFactory import ObjectRecognitionFactory
from ObjectRecognitionType import ObjectRecognitionType
from DetectData import QrData

class ObjectRecognitionController(ISubject):
    def __init__(self):
        self.observers = []
        self.qrCodeDetector = cv2.QRCodeDetector()
        self.videoCapture = cv2.VideoCapture(0) # get cameras
        print("[ObjectRecognitionController] init()");

    def update(self):
        print("- update")

    def detect(self, frame):
        # do qr code detection
        qrData = ObjectRecognitionFactory.detectQrCode(frame)
        if qrData is not None:
            self.notifyObservers(ObjectRecognitionType.QR, qrData)

        cardsData = ObjectRecognitionFactory.detectCards(frame)
        if len(cardsData) > 0:
            self.notifyObservers(ObjectRecognitionType.CARD, cardsData)

        return frame

    def detectAll(self):
        print("- detectAll")

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
