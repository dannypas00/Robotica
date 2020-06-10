#include "TCPServer.hpp"

using namespace std;

namespace bungie{
static int serverSocket;
static fd_set rfds;

// Singleton TCPServer instance
TCPServer& TCPServer::getInstance(){
   static TCPServer _instance;

   return _instance;
}
// Constructor
TCPServer::TCPServer(){
  // create the TCPServer instance.
  printf("Creating TCPServer\n");
  initialize();
}
// Testing Function (Remove before rollout)
void TCPServer::test(){
  printf("Working\n");
}
// Initianlization of Socket server
void TCPServer::initialize() {
  printf("starting socket\n");
  serverSocket = create_socket_server(SOCKET_PORT);
  //FD_ZERO(&rfds);
 //FD_SET(serverSocket, &rfds);
}
// Creation of Socket server and start of listening
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
    //std::thread first (accept_client(serverSocket))
  //std::thread clientThread(&accept_client, serverSocket);
  //return(serverSocket);
  return(accept_client(serverSocket));
}
// Handle Client connection
int TCPServer::accept_client(int server_fd) {
  int clientSocket;
  struct sockaddr_in client;
#ifndef _WIN32
  socklen_t asize;
#else
  int asize;
#endif
  struct hostent *client_info;
 printf("Accepted conn");
  asize = sizeof(struct sockaddr_in);

  clientSocket = accept(server_fd, (struct sockaddr *)&client, &asize);
   printf("Accepted conn");
  if (clientSocket == -1) {
    printf("cannot accept client\n");
    return -1;
  }
  client_info = gethostbyname((char *)inet_ntoa(client.sin_addr));
  printf("Accepted connection from: %s \n", client_info->h_name);

  return clientSocket;
}
// Handle commands
void TCPServer::run() {
  char commandLength;
  int command;
  int number;
  char header[10];
  struct timeval tv = {0, 0};
  FD_ZERO(&rfds);
  FD_SET(serverSocket, &rfds);
  /*
   * Watch TCPIP file descriptor to see when it has input.
   * No wait - polling as fast as possible
   */
  number = select(serverSocket + 1, &rfds, NULL, NULL, &tv);
  /* If there is no data at the socket, then redo loop */
  if (number == 0){
    return;
  }


     commandLength = recv(serverSocket, header, 10, 0);
     //printf("Received %d bytes: %s\n", commandLength);

    int command_length = atoi(header);
    //printf(command_length);
    std::cout << command_length << std::endl;
     char msg[256];
    command = recv(serverSocket, msg, command_length, 0);
  if (command < 0) {
    printf("error reading from socket\n");
    return;
  }

  msg[command] = '\0';
  // Handle Commands Here:
  printf("Received %d bytes: %s\n", command, msg);

}
}
