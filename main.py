import unittest
import os

A1Dir = './A1/'
#codeDir = input("Enter the file path of the project directory: ")


for filename in os.listdir(A1Dir):
    file = __import__((A1Dir+filename))
    print(file)
    file.unittest.main();