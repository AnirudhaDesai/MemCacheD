[1mdiff --git a/auto_tester.py b/auto_tester.py[m
[1mindex 8ca5a07..0cdd1a2 100644[m
[1m--- a/auto_tester.py[m
[1m+++ b/auto_tester.py[m
[36m@@ -77,11 +77,6 @@[m [mclass HappyPath(unittest.TestCase):[m
             message = "add repKey%s 012 3000 11\\r\\nADD MESSAGE\\r\\n"%i[m
             test_result = sendMessage(message)[m
             self.assertTrue(test_result)[m
[31m-<<<<<<< HEAD[m
[31m-            [m
[31m-=======[m
[31m-    [m
[31m->>>>>>> e0d9f53dc9766ef98dcd7cfe0e3157e377022844[m
     def test_stats(self):[m
         message = "stats\\r\\n"[m
         test_result = sendMessage(message)[m
[36m@@ -107,7 +102,7 @@[m [mclass HappyPath(unittest.TestCase):[m
         valid_result = "STORED\r\n"[m
         test_result = sendMessage(message)[m
         self.assertEqual(test_result, valid_result)[m
[31m-[m
[32m+[m[41m        [m
 [m
 [m
 if __name__ == '__main__':[m
[1mdiff --git a/source/memo.cpp b/source/memo.cpp[m
[1mindex cb41963..80a3fec 100644[m
[1m--- a/source/memo.cpp[m
[1m+++ b/source/memo.cpp[m
[36m@@ -248,9 +248,7 @@[m [mnamespace  Memo[m
             Table.erase({key});[m
             TableLock.unlock();[m
 [m
[31m-[m
             return(add(key,temp_flags,temp_expiration_time,size,std::string(temp)));[m
[31m-[m
           [m
         }[m
 [m
