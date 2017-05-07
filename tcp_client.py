import socket
import sys
from time import sleep
    
def sendMessage(message,sock):
    try:
        # Send data
        
        print sys.stderr, 'sending "%s"' % message
        sock.sendall(message)

        # Look for the response
        amount_received = 0
        amount_expected = len(message)

        while True: 
            data = sock.recv(256)
            amount_received = len(data)
            print 'received "%s"' % data
            if amount_received < 256:
                break

    except(e) :
        print e

def TestAddGet(sock):       
    print "Testing ADD"
    print "Basic ADD"
    message = "add addkey 012 3000 11\\r\\nADD MESSAGE\\r\\n"
    sendMessage(message,sock)
    sleep(8)
    message = "get addkey"
    sendMessage(message,sock)

def TestExpirationTime(sock):
    print "Testing Expiration Time"
    
    message = "add expkey 012 5 11\\r\\nEXP MESSAGE\\r\\n"
    sendMessage(message,sock)
    sleep(8)
    message = "get expkey\\r\\n"
    sendMessage(message,sock)

def TestCacheReplacement(sock):
    for i in range(1027):
        message = "add repKey%s 012 3000 11\\r\\nADD MESSAGE\\r\\n"%i
        sendMessage(message,sock)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_address = ('localhost', 9005)

print >>sys.stderr, 'connecting to %s port %s' % server_address
sock.connect(server_address)

# Test Functions can be called here 
#TestAddGet(sock)
#TestCacheReplacement(sock)
#TestExpirationTime(sock)



f = open("commands.txt")

commands = f.read().split("\n")

print commands


for command in commands:
    if len(command) <= 1:
        break
    try:
        # Send data
        message = command
        print sys.stderr, 'sending "%s"' % message
        sock.sendall(message)

        # Look for the response
        amount_received = 0
        amount_expected = len(message)

        while True: 
            data = sock.recv(256)
            amount_received = len(data)
            print 'received "%s"' % data
            if amount_received < 256:
                break

    except(e) :
        print e


print sys.stderr, 'closing socket'
sock.close()
