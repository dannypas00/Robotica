from ObjectRecognitionType import ObjectRecognitionType
from ObjectRecognitionCardType import ObjectRecognitionCardType
from enum import Enum

"""Type's used for temperature state"""
class TemperatureType(Enum):
    KOUD = 1
    LAUW = 2
    WARM = 3
    HEET = 4

"""Base data class"""
class DetectData:

    def __init__(self, _type):
        self.type = _type;

    """Get type of data"""
    def getType(self):
        return self._type


"""Qr data class"""
class QrData(DetectData):

    def __init__(self, _type, _text, _points):
        DetectData.__init__(self, _type)
        self.text = _text
        self.points = _points

    """Get string that was decoded from a QR code"""
    def getText(self):
        return self.text

    """Get points of detected vision object"""
    def getPoints(self):
        return self.points

"""Card data class"""
class CardData(DetectData):

    def __init__(self, _type, _cardType, _points):
        DetectData.__init__(self, _type)
        self.cardType = _cardType
        self.points = _points

    """Get type of card detected"""
    def getCardType(self):
        return self.cardType

    """Get points of detected vision object"""
    def getPoints(self):
        return self.points

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
