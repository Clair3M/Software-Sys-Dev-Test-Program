import unittest
import os

directory = 'A1'
#codeDir = input("Enter the file path of the project directory: ")


for filename in os.listdir("./" + directory + "/"):
    file = __import__((directory + "." + filename), globals={}, locals={}, fromlist=[])
    file.unittest.main();
