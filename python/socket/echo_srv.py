#!/usr/bin/env python3
import socket

HOST = "127.0.0.1"  # localhost or "127.0.0.1" (standart loopback interface address)
PORT = 5634  # port to listen on (non-privileged ports are > 1023)

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    conn, addr = s.accept()
    with conn:
        print(f"connected by {addr} conn {conn=}")
        while True:
            data = conn.recv(1024)
            if not data:
                break
            conn.sendall(data)
