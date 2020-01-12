import socket
from trace import Trace

with socket.socket(socket.AF_INET, socket. SOCK_DGRAM) as sock:
    print('9999 is bind')
    sock.bind(('127.0.0.1', 9999))


    while True:
        res = sock.recv(1024)
        print('Message: ', res.decode('utf-8'))