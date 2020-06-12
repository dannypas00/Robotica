import numpy as np
import cv2

"""Image factory class used for image processes"""
class ObjectRecognitionImageFactory:

    """Filter all color but red"""
    def filterColorRed(frame):
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        mask_a = cv2.inRange(hsv, np.array([0,50,50]), np.array([10,255,255]))
        mask_b = cv2.inRange(hsv, np.array([170,50,50]), np.array([180,255,255]))
        mask = mask_a | mask_b
        res = cv2.bitwise_and(frame, frame, mask= mask)
        return res

    """Filter all color but black"""
    def filterColorBlack(frame):
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        mask = cv2.inRange(hsv, np.array([0,0,0]), np.array([180, 255, 30]))
        res = cv2.bitwise_and(frame, frame, mask= mask)
        return res
