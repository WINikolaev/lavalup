import socket

# 1st agr - ipv4; 1nd agr - udp
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# get port
sock.bind(('127.0.0.1', 8888))
result = sock.recv(1024)
print('Message: ', result.decode('utf-8'))
sock.close()