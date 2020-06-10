
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <iostream>
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

class TCPServer {
  public:
    static TCPServer& getInstance();
    void test();
    void run();
    
  private:
    static TCPServer _instance;
    TCPServer();
    void initialize();
    int create_socket_server(int port);
    int accept_client(int server_fd);
};
}
