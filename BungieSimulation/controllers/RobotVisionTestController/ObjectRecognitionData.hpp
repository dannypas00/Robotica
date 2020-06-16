#ifndef OBJECT_RECOGNITION_DATA
#define OBJECT_RECOGNITION_DATA

#include <iostream>

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
      QrCode(ObjectRecognitionType _type, std::string _data) : ObjectRecognitionData(_type){
        this->_data = _data;
      };
      
      ~QrCode(){
      
      };
      
      std::string getData(){
        return this->_data;
      };
      
    private:
      std::string _data;
      
  };
  
  class Card : public ObjectRecognitionData {
  
    public:
      Card(ObjectRecognitionType _type, std::string _cardType) : ObjectRecognitionData(_type){
        this->_cardType = _cardType;
      };
      
      ~Card(){
      
      };
      
      std::string getCardType(){
        return this->_cardType;
      };
      
    private:
      std::string _cardType;
      
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