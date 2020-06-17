#ifndef OBJECT_RECOGNITION_DATA
#define OBJECT_RECOGNITION_DATA

#include <iostream>

#include "Vector3.h"

namespace bungie {

  enum ObjectRecognitionType{
    QRCODE = 0,
    CARD = 1,
    MINERAL = 2,
    TEMPERATURE = 3
  };
  
  class ObjectRecognitionData {
  
    public:
      ObjectRecognitionData(ObjectRecognitionType _type){
        this->_type = _type;
      };
      
      ~ObjectRecognitionData(){
      
      };
      
      ObjectRecognitionType getType(){
        return this->_type;
      };
      
    private:
      ObjectRecognitionType _type;
      
  };
  
  class QrCode : public ObjectRecognitionData {
  
    public:
      QrCode(ObjectRecognitionType _type, std::string _data, Vector3 _center) : ObjectRecognitionData(_type){
        this->_data = _data;
        this->_center = _center;
      };
      
      ~QrCode(){
      
      };
      
      std::string getData(){
        return this->_data;
      };
      
      Vector3 getCenter(){
        return this->_center;
      };
      
    private:
      std::string _data;
      Vector3 _center;
      
  };
  
  class Card : public ObjectRecognitionData {
  
    public:
      Card(ObjectRecognitionType _type, std::string _cardType, Vector3 _center) : ObjectRecognitionData(_type){
        this->_cardType = _cardType;
        this->_center = _center;
      };
      
      ~Card(){
      
      };
      
      std::string getCardType(){
        return this->_cardType;
      };
      
      Vector3 getCenter(){
        return this->_center;
      };
      
    private:
      std::string _cardType;
      Vector3 _center;
      
  };
  
  
  
  class Mineral : public ObjectRecognitionData {
  
    public:
      Mineral(ObjectRecognitionType _type) : ObjectRecognitionData(_type){
        _min = "mineral";
      };
      
      ~Mineral(){
      
      };
      
      std::string getMin(){
        return _min;
      };
      
    private:
    std::string _min;
      
  };
  
  class Temperature : public ObjectRecognitionData {
  
    public:
      Temperature(ObjectRecognitionType _type, std::string _state) : ObjectRecognitionData(_type){
        this->_state = _state;
      };
      
      ~Temperature(){
      
      };
      
      std::string getState(){
        return this->_state;
      };
      
    private:
      std::string _state;
      
  };
}
#endif