import socket
import threading

BIND_IP = "127.0.0.1"
BIND_PORT = 5050
HEADER_SIZE = 10
FORMAT = "ascii" 
DISCONNECTER = "!terminate"
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind((BIND_IP, BIND_PORT))


def handleClient(client, address):
    print(f"connection with {address} initialized")
    client.send(bytes("Connected",FORMAT))
    connected = True
    while connected:
        command_length = client.recv(HEADER_SIZE).decode(FORMAT)
        command_length = int(command_length)
        command = client.recv(command_length).decode(FORMAT)
        if command == DISCONNECTER:
            connected = False
        print(f"{command}")
    client.close()


def initConnection():
    print(f"listening on {BIND_IP}")
    server.listen(5)
    while True:
        client, address = server.accept()
        thread = threading.Thread(target=handleClient, args=(client, address))
        thread.start()
        
            
print("Server Started")
initConnection()
