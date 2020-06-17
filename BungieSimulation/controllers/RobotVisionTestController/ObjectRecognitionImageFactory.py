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
    
    """Crop a image by the contours with a margin"""
    def cropImage(image, cnt, margin):
        contours_poly = cv2.approxPolyDP(cnt[0], 3, True)
        boundRect = cv2.boundingRect(contours_poly)
        x, y, w, h = boundRect
        
        crop_img = image[y-margin:y+h+margin, x-margin:x+w+margin] #Cropping
        return crop_img
    
    """Generate a contour template by a file"""
    def generateTemplateContours(fileName, _mode=cv2.THRESH_BINARY):
        img = cv2.imread(fileName)
        _, gsi = cv2.threshold(cv2.cvtColor(img, cv2.COLOR_BGR2GRAY), 0, 255, _mode)
        
        cnt, _ = cv2.findContours(gsi, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
        
        return cnt
