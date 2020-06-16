#ifndef PYTHON_CONTROLLER
#define PYTHON_CONTROLLER

#include <Python.h>
#include <map>

namespace bungie {

class PythonController {

  public:
    static PythonController& getInstance(){
     static PythonController instance;
     return instance;
    };
    void init(){
      if(!_init){
        Py_Initialize();
        _init = true;
      }
    };
    void exit(){
      if(_init){
        Py_Finalize();
        _init = false;
      }
    };
  
    bool callFunction(std::string _functionName, std::string _arguments = ""){
      if(pModule == NULL){
          PyErr_Print();
          std::cout << "failed to call function: " << _functionName << ", On module: " << _module << std::endl;
          return false;
      }
      
      PyObject* pFunc;
      std::map<std::string, PyObject*>::iterator it = _functions.find(_functionName);
      if(it != _functions.end()){
        pFunc = it->second;
      }else{
        pFunc = PyObject_GetAttrString(pModule, _functionName.c_str());
        _functions.insert(std::pair<std::string,PyObject*>(_functionName, pFunc));
      }
      PyObject *pArgs;
      
      if(_arguments != "")
        pArgs = PyTuple_Pack(1, PyBytes_FromString(_arguments.c_str())); 
      else
        pArgs = PyTuple_Pack(0);
      
      PyObject_CallObject(pFunc, pArgs);
      
      //Py_XDECREF(pFunc);
      //Py_DECREF(pModule);
      Py_DECREF(pArgs);
      //Py_DECREF(pValue);
      
      return true;
    };
    
    std::string callFunctionReturn(std::string _functionName, const char* _arguments){
    
      if(pModule == NULL){
          PyErr_Print();
          std::cout << "failed to call function: " << _functionName << ", On module: " << _module << std::endl;
          return "";
      }
      
      PyObject* pFunc;
      std::map<std::string, PyObject*>::iterator it = _functions.find(_functionName);
      if(it != _functions.end()){
        pFunc = it->second;
      }else{
        pFunc = PyObject_GetAttrString(pModule, _functionName.c_str());
        _functions.insert(std::pair<std::string,PyObject*>(_functionName, pFunc));
      }
      PyObject *pArgs, *pValue;
      
      if(_arguments != NULL)
        pArgs = PyTuple_Pack(1, PyBytes_FromString(_arguments)); 
      else
        pArgs = PyTuple_Pack(0);
      
      pValue = PyObject_CallObject(pFunc, pArgs);
      std::string ret = PyBytes_AS_STRING(pValue);
      
      Py_DECREF(pArgs);
      Py_DECREF(pValue);
      
      return ret;
    };
    std::string callFunctionReturn(std::string _functionName, std::string _arguments = ""){
      if(_arguments != "")
        return PythonController::callFunctionReturn(_functionName, _arguments.c_str());
      return PythonController::callFunctionReturn(_functionName, NULL);
    };
    
    void setModule(std::string _moduleName){
      _module = _moduleName; 
      pName = PyUnicode_FromString(_moduleName.c_str());
      pModule = PyImport_Import(pName);
      Py_DECREF(pName);
    };
    
  private:
    std::map<std::string, PyObject*> _functions;
    std::string _module;
    PyObject *pName, *pModule;
    bool _init;
  
    PythonController(){
      _init = false;
      _module = "None";
    };
};
}
#endif