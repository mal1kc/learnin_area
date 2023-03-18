!#/bin/env python3
import socket
HOST = "127.0.0.1"  # the server's hostname or IP address
PORT = 5634  # the port used by the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b"hello, universe.\nHi, friend.")
    data = s.recv(1024)

print(f"received some data:\n{data=}")
print(f"rendered data :\n---\n{data.decode()}\n---")
