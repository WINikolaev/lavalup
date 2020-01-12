import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(('127.0.0.1', 9999))
sock.listen(5)
sock.settimeout(5)
#sock.setblocking(False)


while True:
    try:
        client, addr = sock.accept()
    except socket.error:
        print('no connection')
    except KeyboardInterrupt:
        break
    else:
        res = client.recv(1024)
        client.close()
        print('Message: ', res.decode('utf-8'))