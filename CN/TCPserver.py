import socket
host="127.0.0.1"
port=1234
sock=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
with sock:
	sock.bind((host,port))
	sock.listen()
	print("Server on....")
	conn,addr=sock.accept()
	with conn:
		while True:
			data=conn.recv(1024)
			if not data:
				break
			conn.sendall(data)
