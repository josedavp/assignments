#!/usr/bin/python
import sys
#from collections import defaultdict

def numRoman(num):
    thousands = {3000 : "MMM", 2000 : "MM", 1000 : "M", 0 : ""}
    hundreds = {900 : "CM", 800 : "DCCC", 700 : "DCC", 600 : "DC", 500 : "D", 400 : "CD", 300 : "CCC", 200 : "CC", 100 : "C", 0 : ""}
    tens = {90 : "XC", 80 : "LXXX", 70 : "LXX", 60 : "LX", 50 : "L", 40 : "XL", 30 : "XXX" , 20 : "XX", 10 : "X", 0 : ""}
    ones = {9 : "IX", 8 : "VIII", 7 : "VII", 6 : "VI", 5 : "V", 4 : "IV", 3 : "III", 2 : "II", 1 : "I", 0 : ""}
    #num = argument
    numOne = 0
    numTen = 0
    numHundred = 0
    numThousand = 0
    total = ""
 #   if isinstance(num, str): ##What if the user inputs a number rather than a string?
   #     print("Error: Enter a number")
   #     return 0
    if (0 >= int(num) or int(num) > 3999):
        print("\t" + str(num) + " is Error")
    elif (0 < int(num) or int(num) <= 3999):
        #################----------THOUSANDS----------##############
        numThousand = int(num) // 1000
        numThousand *= 1000
        ##print("\nThis is numThousand " + str(numThousand) + "\n")
        ##################----------HUNDREDS----------##############
        numHundred = ( int(num) // 100 ) % 10
        numHundred *= 100
        ##print("\nThis is numHundred " + str(numHundred) + "\n")
        #################----------TENS--------------##############
        numTen = ( int(num) // 10 ) % 10
        numTen *= 10
        ##print("\nThis is numTen " + str(numTen) + "\n")
        #################----------ONES--------------##############
        numOne = int(num) % 10
        ##print("\nThis is numOne " + str(numOne) + "\n")
        
        ##print("\nThis is thousandList " + str(thousands[numThousand]) + "\n")
        ##print("\nThis is hundredList " + str(hundreds[numHundred]) + "\n")
        
        total = thousands[numThousand] + hundreds[numHundred] + tens[numTen] + ones[numOne]
        #print("This is total: " + total)
      #  print("This is num: " + str(num))
        print("\t" + str(num) + " is " + total + "")
        
        return total
    
        
    
    
        
#numRoman(sys.argv[1:])     
if __name__ == '__main__':
    for argument in sys.argv[1:]:
        numRoman(argument)
    
    