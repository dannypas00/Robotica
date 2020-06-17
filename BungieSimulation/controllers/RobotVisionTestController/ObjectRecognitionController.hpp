#ifndef OBJECT_RECOGNITION_CONTROLLER
#define OBJECT_RECOGNITION_CONTROLLER

#include <webots/Camera.hpp>
#include <sstream>
#include <Python.h>
#include <vector>
#include <map>

#include "ObjectRecognitionSubject.hpp"
#include "ObjectRecognitionData.hpp"
#include "Vector3.h"

using namespace webots;

namespace bungie {

class ObjectRecognitionController : public ObjectRecognitionSubject {

  public:
    static ObjectRecognitionController& getInstance(){
     static ObjectRecognitionController instance;
     return instance;
    };
    
    void registObserver(ObjectRecognitionObserver* _observer){
      _observers.push_back(_observer);
    };
    
    void removeObserver(ObjectRecognitionObserver* _observer){
      int size = _observers.size();
      for(int i = 0; i < size; i++){
        if(_observers[i] == _observer){
          _observers.erase(_observers.begin() + i);
        }
      }
    };
    
    void notifyObservers(ObjectRecognitionData* _data){
      int size = _observers.size();
      for(int i = 0; i < size; i++){
        if(_observers[i]->getType() == _data->getType()){
          _observers[i]->update(_data);
        }
      }
    };
    
    bool detectAll(Camera* _cam){
      std::string output = this->formatImage(_cam);
      if(output == ""){
        return false;
      }
      
      std::string ret = PythonController::getInstance().callFunctionReturn("detectAll", output);
      this->parsePythonOutput(ret);
      return true;
    };
    
    void detectQrCode(Camera* _cam){
      std::cout << "";
    };
    
  private:
    std::vector<ObjectRecognitionObserver*> _observers;
  
    std::string formatImage(Camera* _cam){
      std::string output = "";
      const unsigned char* image = _cam->getImage();
      if(image != NULL){ // on get image
        int w = _cam->getWidth();
        int h = _cam->getHeight();
      
        output = std::to_string(w) + "," + std::to_string(h) + ",";
        for (int y = 0; y < h; y++) {
          for (int x = 0; x < w; x++) {
            unsigned char r = Camera::imageGetRed(image, w, x, y);
            unsigned char g = Camera::imageGetGreen(image, w, x, y);
            unsigned char b = Camera::imageGetBlue(image, w, x, y);
            output += std::to_string((int)r) + "," + std::to_string((int)g) + "," + std::to_string((int)b);
            if(y == h - 1 && x == w - 1){
              
            }else{
              output += ",";
            }
          }
        }
      }
      return output;
    };
    
    void parsePythonOutput(std::string _output){
      std::vector<std::string> split = this->splitString(_output, ';');
      //std::cout << "QRCODE: " << split[0] << "\n";
      //std::cout << "CARDS: " << split[1] << "\n";
      //std::cout << "MINERAL: " << split[2] << "\n";
      //std::cout << "TEMPERATURE: " << split[3] << "\n";
      
      if(split[0] != ""){ // qr code
        std::vector<std::string> qrDataSplit = splitString(split[0], '/');
        ObjectRecognitionData* qrData = new QrCode(ObjectRecognitionType::QRCODE, qrDataSplit[0], Vector3(std::stod(qrDataSplit[1]), std::stod(qrDataSplit[2]), 0.0f));
        this->notifyObservers(qrData);
      }
      
      if(split[1] != ""){ // cards
        std::vector<std::string> cards = splitString(split[1], ':');
        int size = cards.size();
        for(int i = 0; i < size; i++){
          std::vector<std::string> cardDataSplit = splitString(cards[i], '/');
          ObjectRecognitionData* cardData = new Card(ObjectRecognitionType::CARD, splitString(cardDataSplit[0], '.')[1], Vector3(std::stod(cardDataSplit[1]), std::stod(cardDataSplit[2]), 0.0f));
          this->notifyObservers(cardData);
        }
      }
      
      if(split[2] != ""){ // mineral
        std::vector<std::string> minerals = splitString(split[1], ':');
        int size = minerals.size();
        for(int i = 0; i < size; i++){
          std::vector<std::string> mineralDataSplit = splitString(minerals[i], '/');
          ObjectRecognitionData* mineralData = new Mineral(ObjectRecognitionType::MINERAL);
          this->notifyObservers(mineralData);
        }
      }
      
      if(split[3] != ""){ // temperature
        ObjectRecognitionData* temperatureData = new Temperature(ObjectRecognitionType::TEMPERATURE, split[3]);
        this->notifyObservers(temperatureData);
      }
    }
    
    std::vector<std::string> splitString(const std::string& s, char delimiter){
       std::vector<std::string> tokens;
       std::string token;
       std::istringstream tokenStream(s);
       while (std::getline(tokenStream, token, delimiter)){
          tokens.push_back(token);
       }
       return tokens;
    };
  
    ObjectRecognitionController(){
      //_observers = new std::vector<ObjectRecognitionObserver*>();
    };
};
}
#endif