import socket


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(('127.0.0.1', 8888))
sock.listen(5)
sock.setblocking(False)

client, addr = sock.accept()
res = client.recv(1024)
client.close()
print('Message: ', res.decode('utf-8'))