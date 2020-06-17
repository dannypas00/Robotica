
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <vector>
#include <iostream>

#include "ISubject.hpp"
// #include <webots/distance_sensor.h>
// #include <webots/led.h>
// #include <webots/light_sensor.h>
// #include <webots/motor.h>
// #include <webots/position_sensor.h>
// #include <webots/robot.h>
#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>

#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <thread>   
//#include <future>
//#pragma comment(lib, "ws2_32.lib")
#else
#include <arpa/inet.h>  /* definition of inet_ntoa */
#include <netdb.h>      /* definition of gethostbyname */
#include <netinet/in.h> /* definition of struct sockaddr_in */
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h> /* definition of close */
#endif

#define SOCKET_PORT 5050
#define TIMESTEP 250

namespace bungie {

class TCPServer : public TCPServerSubject {
  public:
    static TCPServer& getInstance();
    void test();
    void run();
    void launch();
    
    void registObserver(TCPServerObserver _observer);
    void removeObserver(TCPServerObserver _observer);
    void notifyObservers(std::string _key, std::string _value);
    
  private:
    static TCPServer _instance;
    TCPServer();
    ~TCPServer();
    std::string bufferToString(char* buffer, int bufflen);
    void initialize();
    int create_socket_server(int port);
    int accept_client(int server_fd);

    std::vector<TCPServerObserver> _observers;
};
}
