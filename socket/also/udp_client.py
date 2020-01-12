import socket

# for 0 and 1 example:
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.sendto(b'Test message', ('127.0.0.1', 9999))

#for 2 example:
unix_sock_name = 'unix.sock'

#sock = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
#sock.sendto(b'Test message', unix_sock_name)