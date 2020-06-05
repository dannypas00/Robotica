#include "TCPServer.hpp"

using namespace std;

namespace bungie{
static int serverSocket;
//static fd_set rfds;

//Singleton TCPServer instance
TCPServer& TCPServer::getInstance(){
   static TCPServer _instance;

   return _instance;
}
TCPServer::TCPServer(){
  // create the TCPServer instance.
  printf("Creating TCPServer\n");
  initialize();
}
void TCPServer::test(){
  printf("Working\n");
}
void TCPServer::initialize() {
  printf("starting socket\n");
  serverSocket = create_socket_server(SOCKET_PORT);
  //FD_ZERO(&rfds);
 //FD_SET(serverSocket, &rfds);
}

int TCPServer::create_socket_server(int port) {
  int serverSocket, rc;
  struct sockaddr_in address;

#ifdef _WIN32
  /* initialize the socket api */
  WSADATA info;

  rc = WSAStartup(MAKEWORD(1, 1), &info); /* Winsock 1.1 */
  if (rc != 0) {
    printf("cannot initialize Winsock\n");
    return -1;
  }
#endif
  /* create the socket */
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket == -1) {
    printf("cannot create socket\n");
    return -1;
  }

  /* fill in socket address */
  memset(&address, 0, sizeof(struct sockaddr_in));
  address.sin_family = AF_INET;
  address.sin_port = htons((unsigned short)port);
  address.sin_addr.s_addr = INADDR_ANY;

  /* bind to port */
  rc = bind(serverSocket, (struct sockaddr *)&address, sizeof(struct sockaddr));
  if (rc == -1) {
    printf("cannot bind port %d\n", port);
#ifdef _WIN32
    closesocket(serverSocket);
#else
    close(serverSocket);
#endif
    return -1;
  }

  /* listen for connections */
  if (listen(serverSocket, 1) == -1) {
    printf("cannot listen for connections\n");
#ifdef _WIN32
    closesocket(serverSocket);
#else
    close(serverSocket);
#endif
    return -1;
  }
  printf("Waiting for a connection on port %d...\n", port);

  //return accept_client(serverSocket);
  return(serverSocket);
}

}
