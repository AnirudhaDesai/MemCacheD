import socket
import sys
import unittest
from time import sleep

one_meg_data = "X"*(1024*1024)
almost_one_meg_data = "X"*(1024*1024-41)

   
def sendMessage(message,noreply=False):
    global sock
    try:
        # print "sending {} bytes".format(len(message))
        sock.sendall(message)

        if noreply==True:
            return True

        # Look for the response
        total_length_received = 0
        data_received = ""

        while True: 
            data = sock.recv(256)
            data_received+=data
            length_received = len(data)
            total_length_received += length_received
            # print length_received,data
            if length_received < 256:
                break

    except:
        return False

    # print "received: ",data_received

    return data_received

class HappyPath(unittest.TestCase):

    def setUp(self):
        pass

    def test_000_add_new_key(self):       
        message = "add addkey 012 3000 11\\r\\nADD MESSAGE\\r\\n"
        valid_result = "STORED\r\n"
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)
    
    def test_001_get_existing_key(self):
        message = "get addkey\\r\\n"
        valid_result = "VALUE addkey 12 11\r\nADD MESSAGE\r\nEND\r\n" 
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)

    def test_002_add_existing_key(self):
        message = "add addkey 012 3000 11\\r\\nADD MESSAGE\\r\\n"
        valid_result = "NOT_STORED\r\n"
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)

    def test_003_set_existing_key(self):
        message = "set addkey 012 3000 11\\r\\nADD MESSAGE\\r\\n"
        valid_result = "STORED\r\n"
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)

    def test_004_delete_existing_key(self):
        message = "delete addkey \\r\\n"
        valid_result = "DELETED\r\n"
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)

    def test_005_delete_deleted_key(self):
        message = "delete addkey \\r\\n"
        valid_result = "NOT_FOUND\r\n"
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)

    def test_006_expiration_time_add_positive(self):
        
        message = "add expkey 012 5 11\\r\\nEXP MESSAGE\\r\\n"
        test_result = sendMessage(message)
        
        message = "get expkey\\r\\n"
        test_result = sendMessage(message)
        valid_result = "VALUE expkey 12 11\r\nEXP MESSAGE\r\nEND\r\n"
        self.assertEqual(test_result, valid_result)
    
    def test_007_expiration_time_add_negative(self):
        
        message = "add expkey 012 5 11\\r\\nEXP MESSAGE\\r\\n"
        test_result = sendMessage(message)
        sleep(8)
        message = "get expkey\\r\\n"
        test_result = sendMessage(message)
        valid_result = "END\r\n"
        self.assertEqual(test_result, valid_result)


class CacheReplacementLRU(unittest.TestCase):

    def test_000_cache_replacement_populate_cache(self):
        for i in range(1027):
            message = "add repKey%s 012 3000 11\\r\\nADD MESSAGE\\r\\n"%i
            test_result = sendMessage(message)
            self.assertTrue(test_result)

    def test_001_cache_replacement_check_least_recently_used_keys_eviction(self):
        message = "get repKey0 repKey1 repKey2\r\n"
        test_result = sendMessage(message)
        valid_result = "END\r\n"
        self.assertEqual(test_result, valid_result)

class LandlordCacheReplacement(unittest.TestCase):
    
    def test_000_landlordCacheReplacement(self):
        for i in range(1024):
            message = "add lrdrepKey%s 012 3000 11\\r\\nADD MESSAGE\\r\\n"%i
            test_result = sendMessage(message)
            sleep(0.1)
        for i in range(3,1024):
            message = "get lrdrepKey%s\\r\\n"%i
            test_result = sendMessage(message)
        for i in range(1024,1027):
            message = "add lrdrepKey%s 012 3000 11\\r\\nADD MESSAGE\\r\\n"%i
            test_result = sendMessage(message)
        message = "get lrdrepKey0 lrdrepKey1 lrdrepKey2\\r\\n"
        valid_result = "END\r\n"
        self.assertEqual(test_result,valid_result)


class Stats(unittest.TestCase):

    def test_000_stats(self):
        message = "stats\\r\\n"
        test_result = sendMessage(message)
        # print "got result:",test_result
        self.assertTrue(test_result)


class LargeData(unittest.TestCase):

    def test_000_add_long(self):       
        message = "add longvalue 012 3000 500\\r\\n"+"X"*500+"\\r\\n"
        valid_result = "STORED\r\n"
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)

    def test_001_get_long(self):
        message = "get longvalue\\r\\n"
        valid_result = "VALUE longvalue 12 500\r\n"+"X"*500+"\r\nEND\r\n" 
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)

    def test_002_add_one_meg(self):
        message = "add onemegvalues 012 3000 1048542\\r\\n"+almost_one_meg_data+"\\r\\n"
        # print len(message)
        # assert(len(message)==1024*1024)
        valid_result = "STORED\r\n"
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)


class IncrementDecrement(unittest.TestCase):

    def test_000_increment_before_add(self):
        message = "incr incrkey 2\\r\\n"
        test_result = sendMessage(message)
        valid_result = "NOT_FOUND\r\n"
        self.assertEqual(test_result, valid_result)

    def test_001_increment_add(self):
        message = "add incrkey 1200 5 1\\r\\n1\\r\\n"
        test_result = sendMessage(message)
        valid_result = "STORED\r\n"
        self.assertEqual(test_result, valid_result)

    def test_002_increment_get(self):
        message = "get incrkey\\r\\n"
        valid_result = "VALUE incrkey 1200 1\r\n1\r\nEND\r\n" 
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)

    def test_003_increment_increment(self):
        message = "incr incrkey 2\\r\\n"
        test_result = sendMessage(message)
        valid_result = "3\r\n"
        self.assertEqual(test_result, valid_result)

    def test_004_increment_get_after_incr(self):
        message = "get incrkey\\r\\n"
        valid_result = "VALUE incrkey 1200 1\r\n3\r\nEND\r\n" 
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)

    def test_005_decrement_before_add(self):
        message = "decr decrkey 2\\r\\n"
        test_result = sendMessage(message)
        valid_result = "NOT_FOUND\r\n"
        self.assertEqual(test_result, valid_result)

    def test_006_decrement_add(self):
        message = "add decrkey 1200 500 1\\r\\n3\\r\\n"
        test_result = sendMessage(message)
        valid_result = "STORED\r\n"
        self.assertEqual(test_result, valid_result)

    def test_007_decrement_get(self):
        message = "get decrkey\\r\\n"
        valid_result = "VALUE decrkey 1200 1\r\n3\r\nEND\r\n" 
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)

    def test_008_decrement_decrement(self):
        message = "decr decrkey 2\\r\\n"
        test_result = sendMessage(message)
        valid_result = "1\r\n"
        self.assertEqual(test_result, valid_result)

    def test_009_decrement_get_after_decr(self):
        message = "get decrkey\\r\\n"
        valid_result = "VALUE decrkey 1200 1\r\n1\r\nEND\r\n" 
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)


class AppendPrepend(unittest.TestCase):

    def test_000_append(self):
        message = "add appkey 12 5 11\\r\\nAPP MESSAGE\\r\\n"
        test_result = sendMessage(message)
        message = "append appkey 1\\r\\nS\\r\\n"
        test_result = sendMessage(message)
        message = "get appkey\\r\\n"
        test_result = sendMessage(message)
        valid_result = "VALUE appkey 12 12\r\nAPP MESSAGES\r\nEND\r\n"
        self.assertEqual(test_result, valid_result)

    def test_001_prepend(self):
        message = "add prepkey 12 5 11\\r\\nAPP MESSAGE\\r\\n"
        test_result = sendMessage(message)
        message = "prepend prepkey 1\\r\\nS\\r\\n"
        test_result = sendMessage(message)
        message = "get prepkey\\r\\n"
        test_result = sendMessage(message)
        valid_result = "VALUE prepkey 12 12\r\nSAPP MESSAGE\r\nEND\r\n"
        self.assertEqual(test_result, valid_result)        

class InvalidCommand(unittest.TestCase):

    def test_000_invalid_get(self):
        message = "ger key 012 3000 5\\r\\nvalue\\r\\n"
        valid_result = "ERROR\r\n"
        test_result = sendMessage(message)
        self.assertEqual(test_result, valid_result)



        

if __name__ == '__main__':
    global sock
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('localhost', 9005)


    print 'connecting to %s port %s' % server_address
    sock.connect(server_address)

    unittest.TestLoader.sortTestMethodsUsing = None

#     suite = unittest.TestLoader().loadTestsFromTestCase(HappyPath)
    # unittest.TextTestRunner(verbosity=2).run(suite)

    # suite = unittest.TestLoader().loadTestsFromTestCase(LargeData)
    # unittest.TextTestRunner(verbosity=2).run(suite)

    # suite = unittest.TestLoader().loadTestsFromTestCase(Stats)
    # unittest.TextTestRunner(verbosity=2).run(suite)

    # suite = unittest.TestLoader().loadTestsFromTestCase(CacheReplacementLRU)
    # unittest.TextTestRunner(verbosity=2).run(suite)


    # suite = unittest.TestLoader().loadTestsFromTestCase(LandlordCacheReplacement)
    # unittest.TextTestRunner(verbosity=2).run(suite)

#     suite = unittest.TestLoader().loadTestsFromTestCase(InvalidCommand)
    # unittest.TextTestRunner(verbosity=2).run(suite)

    suite = unittest.TestLoader().loadTestsFromTestCase(IncrementDecrement)
    unittest.TextTestRunner(verbosity=2).run(suite)

    # suite = unittest.TestLoader().loadTestsFromTestCase(AppendPrepend)
    # unittest.TextTestRunner(verbosity=2).run(suite)

    print 'closing socket'
    sock.close()
