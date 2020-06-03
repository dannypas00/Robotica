import socket
import threading

BIND_IP = "127.0.0.1"
BIND_PORT = 5050
HEADER_SIZE = 10
FORMAT = "ascii" 
DISCONNECTER = "!terminate"

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((BIND_IP, BIND_PORT))

def handleCommand(command):
    commandSplit = command.split(";")
    key,value = commandSplit[0], commandSplit[1]
    print(f"key = {key} value = {value}")





    
def handleClient(client, address):
    print(f"connection with {address} initialized")
    connected = True
    while connected:
        command_length = client.recv(HEADER_SIZE).decode(FORMAT)
        command_length = int(command_length)
        command = client.recv(command_length).decode(FORMAT)
        if command == DISCONNECTER:
            connected = False
        else:
            handleCommand(command)
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
