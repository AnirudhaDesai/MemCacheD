import socket
import sys

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_address = ('localhost', 9005)

print >>sys.stderr, 'connecting to %s port %s' % server_address
sock.connect(server_address)

f = open("commands.txt")

commands = f.read().split("\n")

print commands


for command in commands:
    try:
        # Send data
        message = command
        print sys.stderr, 'sending "%s"' % message
        sock.sendall(message)

        # Look for the response
        amount_received = 0
        amount_expected = len(message)

        while True: 
            data = sock.recv(16)
            amount_received += len(data)
            print sys.stderr, 'received "%s"' % data
            if amount_received < 16:
                break

    except e:
        print e

print sys.stderr, 'closing socket'
sock.close()
