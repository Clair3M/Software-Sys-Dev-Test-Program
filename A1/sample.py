import unittest
from ctypes import *

fileName = "../sampleCode/sample.c"
functions = CDLL(fileName)

class sampleTestCases(unittest.TestCase):

    def setUp(self):
        
        self.a = 3

    def test1(self):
        assert functions.testFun(self.a, 4) == 12, "C can't do basic math"