#ifndef OBJECT_RECOGNITION_OBSERVER
#define OBJECT_RECOGNITION_OBSERVER

// All the webots classes are defined in the "webots" namespace
using namespace webots;

#include <iostream>
#include <functional>

#include "ObjectRecognitionData.hpp"

namespace bungie {

  class ObjectRecognitionObserver {
    public:
      ObjectRecognitionObserver(ObjectRecognitionType _type, std::function<void(ObjectRecognitionData*)> _callback){
        this->_type = _type;
        this->_callback = _callback;
      };
      
      ObjectRecognitionType getType(){
        return this->_type;
      };
    
      void update(ObjectRecognitionData* _data){
        this->_callback(_data);
      };

    private:
      ObjectRecognitionType _type;
      std::function<void(ObjectRecognitionData*)> _callback;
  };
  
  
  
}

#endif
