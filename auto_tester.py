import socket
import sys
import unittest
from time import sleep

one_meg_data = "X"*(1024*1024)
almost_one_meg_data = "X"*(1024*1024-41)

   
def sendMessage(message):
    global sock
    try:
        # print 'sending "%s"' % message
        sock.sendall(message)

        # Look for the response
        total_length_received = 0
        data_received = ""

        while True: 
            data = sock.recv(256)
            data_received+=data
            length_received = len(data)
            total_length_received += length_received
            print length_received,data
            if length_received < 256:
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
        self.assertEqual(test_result, valid_result)
    

    def test_get(self):
        message = "get addkey\\r\\n"
        valid_result = "VALUE addkey 12 11\r\nADD MESSAGE\r\n" 
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)

    def test_expiration_time_add_positive(self):
        
        message = "add expkey 012 5 11\\r\\nEXP MESSAGE\\r\\n"
        test_result = sendMessage(message)
        
        message = "get expkey\\r\\n"
        test_result = sendMessage(message)
        valid_result = "VALUE expkey 12 11\r\nEXP MESSAGE\r\n"
        self.assertEqual(test_result, valid_result)
    
    
    def test_expiration_time_add_negative(self):
        
        message = "add expkey 012 5 11\\r\\nEXP MESSAGE\\r\\n"
        test_result = sendMessage(message)
        sleep(8)
        message = "get expkey\\r\\n"
        test_result = sendMessage(message)
        valid_result = "NOT_FOUND\r\n"
        self.assertEqual(test_result, valid_result)

    def test_cache_replacement(self):
        for i in range(1027):
            message = "add repKey%s 012 3000 11\\r\\nADD MESSAGE\\r\\n"%i
            test_result = sendMessage(message)
            self.assertTrue(test_result)

    def test_stats(self):
        message = "stats\\r\\n"
        test_result = sendMessage(message)
        # print "got result:",test_result
        self.assertTrue(test_result)

    def test_add_long(self):       
        message = "add longvalue 012 3000 500\\r\\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\\r\\n"
        valid_result = "STORED\r\n"
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)

    def test_get_long(self):
        message = "get longvalue\\r\\n"
        valid_result = "VALUE longvalue 12 500\r\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\r\n" 
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)

    def test_add_one_meg(self):
        message = "add onemegvalues 012 3000 1048542\\r\\n"+almost_one_meg_data+"\\r\\n"
        # print len(message)
        # assert(len(message)==1024*1024)
        valid_result = "STORED\r\n"
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)



if __name__ == '__main__':
    global sock
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('localhost', 9005)

    print 'connecting to %s port %s' % server_address
    sock.connect(server_address)

    unittest.main()

    print 'closing socket'
    sock.close()
