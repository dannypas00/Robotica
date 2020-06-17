import numpy as np
import cv2

from ObjectRecognitionFactory import ObjectRecognitionFactory

def init(): # test python function
    print("Python is working correctly!")
    
def rereturn(): # test return function
    a = "Python return is working!"
    return a.encode("utf-8")

def convertImage(_imageData): # convert image to numpy array
    w = int(_imageData[0])
    h = int(_imageData[1])
    print(str(w) + "/" + str(h) + " -> " + str(len(_imageData)))
    
    image = []
    
    i = 2
    for y in range(0, h):
        row = []
        for x in range(0, w):
            col = [int(_imageData[i+2]), int(_imageData[i+1]), int(_imageData[i])]
            row.append(col)
            i = i + 3
        image.append(row)
        
    return np.array(image, dtype=np.uint8)

def detectAll(_imageData):
    frame = convertImage(_imageData.decode("utf-8").split(","))
    output = "";
    try:
        #cv2.imshow("frame", np.array(image, dtype=np.uint8))
        #cv2.imwrite("created_image.jpg", frame) 
        
        sep = ";"
        sep_obj = ":"
        sep_obj_arg = "/"
        
        qrData = ObjectRecognitionFactory.detectQrCode(frame)
        if qrData is not None:
            c = qrData.getCenter()
            output += qrData.getText() + sep_obj_arg + str(c.x) + sep_obj_arg + str(c.y)
            
        output += sep
        cardsData = None # ObjectRecognitionFactory.detectCards(frame)
        if cardsData != None:
            #c = cardsData[i].getCenter()
            output += str(cardsData.getCardType())# + sep_obj_arg + "1.0" + sep_obj_arg + "1.0"
                    
        output += sep
        mineralData = ObjectRecognitionFactory.detectMineral(frame)
        if mineralData is not None:
            output += "10/10/20/20"

        output += sep
        temperatureData = ObjectRecognitionFactory.detectTemperature(frame)
        if temperatureData is not None:
            output += str(temperatureData.getState())
                   
    except Exception as e:
        print ("error: " + e)
        return "".encode("utf-8")
        
    return output.encode("utf-8")
