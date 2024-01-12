import unittest
import os
from ctypes import *

fileName = "./sampleCode/sample.so"
functions = CDLL(fileName)

class sampleTestCases(unittest.TestCase):

    def setUp(self):
        self.a = 3

    def tearDown(self):
        self.a = 0

    def test1(self):
        assert functions.testFun(self.a, 4) == 12, "C can't do basic math"


if __name__ == "__main__":
    unittest.main()