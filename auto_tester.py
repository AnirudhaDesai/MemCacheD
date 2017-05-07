import socket
import sys
import unittest
from time import sleep

   
def sendMessage(message):
    global sock
    try:
        print 'sending "%s"' % message
        sock.sendall(message)

        # Look for the response
        amount_received = 0
        data_received = ""

        while True: 
            data_received += sock.recv(256)
            amount_received += len(data_received)
            # print data_received
            if amount_received < 256:
                break

    except:
        return False

    print "received: ",data_received

    return data_received

class HappyPath(unittest.TestCase):

    def setUp(self):
        pass

    def test_add(self):       
        message = "add addkey 012 3000 11\\r\\nADD MESSAGE\\r\\n"
        valid_result = "STORED\r\n"
        test_result = sendMessage(message)
        # print "got result:",test_result
        self.assertEqual(test_result, valid_result)

    def test_get(self):
        message = "get addkey\\r\\n"
        valid_result = "VALUE addkey 12 11\r\nADD MESSAGE\r\n" 
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)

    def test_expiration_time_add(self):
        
        message = "add expkey 012 5 11\\r\\nEXP MESSAGE\\r\\n"
        test_result = sendMessage(message)
        self.assertTrue(test_result)

    def test_expiration_time_get(self):
        message = "get expkey\\r\\n"
        test_result = sendMessage(message)
        self.assertTrue(test_result)

    def test_cache_replacement(self):
        for i in range(1027):
            message = "add repKey%s 012 3000 11\\r\\nADD MESSAGE\\r\\n"%i
            test_result = sendMessage(message)
            self.assertTrue(test_result)

if __name__ == '__main__':
    global sock
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('localhost', 9005)

    print 'connecting to %s port %s' % server_address
    sock.connect(server_address)

    unittest.main()

    print 'closing socket'
    sock.close()
