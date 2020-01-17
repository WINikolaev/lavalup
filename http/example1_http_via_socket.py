import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(('example.com', 80))
contet_items = [
    'GET / HTTP/1.1',
    'Host: example.com',
    'Connection: keep-alive',
    'Accept: test/html',
    '\n'
]

content = '\n'.join(contet_items)
print('---HTTP MESSAGE')
print(content)
print('---END of MESSAGE')
sock.send(content.encode())
result = sock.recv(10024)
print(result.decode())