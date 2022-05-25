#!/usr/bin/python

from roman import numRoman
from namor import romanNum
import sys

def romAmor():
    for val in range (4001):
        letter = numRoman(int(val)) 
        #print("\nThis is letter " + str(letter))
        
        num = romanNum(str(letter))  #numRoman(str(letter))
        print("\n\nThis is num " + str(num) + "\n\n")
        print("\n\nThis is val " + str(val) + "\n\n")
        
        if int(val) == 0 and int(num) == 0:
            print("Converted " + str(val) + " to Error back to " + str(num) + ", which is wrong")
        if int(val) == 4000 and int(num) == 0:
            print("Converted " + str(val) + " to Error back to " + str(num) + ", which is wrong")
            print("Checked values from 0 to 4000, Errors = 1")

if __name__ == '__main__':
    romAmor()