from ObjectRecognitionType import ObjectRecognitionType
from ObjectRecognitionCardType import ObjectRecognitionCardType
from enum import Enum


"""Type's used for temperature state"""
class TemperatureType(Enum):
    KOUD = 1
    LAUW = 2
    WARM = 3
    HEET = 4
    
"""Vector2 class only to store x and y data"""
class Vector2:

    def __init__(self, _x, _y):
        self.x = _x
        self.y = _y

"""Base data class"""
class DetectData:

    def __init__(self, _type):
        self.type = _type;

    """Get type of data"""
    def getType(self):
        return self._type


"""Qr data class"""
class QrData(DetectData):

    def __init__(self, _type, _text, _points, _center):
        DetectData.__init__(self, _type)
        self.text = _text
        self.points = _points
        self.center = _center

    """Get string that was decoded from a QR code"""
    def getText(self):
        return self.text

    """Get points of detected vision object"""
    def getPoints(self):
        return self.points
        
    def getCenter(self):
        return self.center

"""Card data class"""
class CardData(DetectData):

    def __init__(self, _type, _cardType, _points, _center):
        DetectData.__init__(self, _type)
        self.cardType = _cardType
        self.points = _points
        self.center = _center

    """Get type of card detected"""
    def getCardType(self):
        return self.cardType

    """Get points of detected vision object"""
    def getPoints(self):
        return self.points
        
    def getCenter(self):
        return self.center

"""Mineral data class"""
class MineralData(DetectData):

    def __init__(self, _type, _bound, _center, _radius):
        DetectData.__init__(self, _type)
        self.bounds = _bound
        self.center = _center
        self.radius = _radius

    """Get bounds of detected mineral"""
    def getBounds(self):
        return self.bounds

    """Get center of detected mineral"""
    def getCenter(self):
        return self.center

    """Get radius of detected mineral"""
    def getRadius(self):
        return self.radius

"""Temperature data class"""
class TemperatureData(DetectData):

    def __init__(self, _type, _state):
        DetectData.__init__(self, _type)
        self.state = _state

    """Get state of detected temperature"""
    def getState(self):
        return self.state
