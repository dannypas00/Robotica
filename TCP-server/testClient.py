import socket

HOST_IP = "127.0.0.1"
HOST_PORT = 5050
BUFFER_SIZE = 16
FORMAT = "ascii" 
DISCONNECTER = "!terminate"

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect((HOST_IP,HOST_PORT))

msg = client.recv(BUFFER_SIZE)
print(msg.decode(FORMAT))
