import socket
host="127.0.0.1"
port=1234
sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
with sock:
	sock.connect((host,port))
	sock.sendall(bytes(input("Enter message "),"utf-8"))
	print("message from server=>"+(sock.recv(1024)).decode("utf-8"))
