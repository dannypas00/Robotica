from ObjectRecognitionType import ObjectRecognitionType
from ObjectRecognitionCardType import ObjectRecognitionCardType

class DetectData:

    def __init__(self, _type):
        self.type = _type;

    def getType(self):
        return self._type

class QrData(DetectData):

    def __init__(self, _type, _text, _points):
        DetectData.__init__(self, _type)
        self.text = _text
        self.points = _points

    def getText(self):
        return self.text

    def getPoints(self):
        return self.points

class CardData(DetectData):

    def __init__(self, _type, _cardType, _points):
        DetectData.__init__(self, _type)
        self.cardType = _cardType
        self.points = _points

    def getCardType(self):
        return self.cardType

    def getPoints(self):
        return self.points
