#!/usr/bin/python
import sys

def romanNum(argument):
    thousands = {"MMM" : 3000 , "MM" : 2000, "M" : 1000, "" : 0}
    hundreds = {"CM" : 900, "DCCC" : 800, "DCC" : 700, "DC" : 600, "D" : 500, "CD" : 400, "CCC" : 300, "CC" : 200, "C" : 100,  "" : 0}
    tens = {"XC" : 90, "LXXX" : 80, "LXX" : 70, "LX" : 60, "L" : 50, "XL" : 40, "XXX" : 30, "XX" : 20, "X" : 10, "" : 0}
    ones = {"IX" : 9, "VIII" : 8, "VII" : 7, "VI" : 6, "V" : 5, "IV" : 4, "III" : 3, "II" : 2, "I" : 1, "" : 0}

    #for word in sys.argv[1:]:
        #if word %
        #tempWord = word
    tempWord = argument
    firstNum = ""
    total = 0
    num = 0
    #print("\nThis is word: " + word + "\n")
    for lists in (thousands, hundreds, tens, ones): #NOT SURE tried to make lists go through of dictionaries to find x and compare with lets say M or X not workign
        for x, y in lists.items(): #NOT SURE it works though but minor errors
            #print("\nThis is first x: " + str(x) + "\n")
            #print("\nThis is tempWord: " + str(tempWord) + "\n")
            if tempWord.upper().startswith(x):
                num += y
                tempWord = tempWord.replace(x , '', 1)
                
                if (tempWord == '') & (1 <= num <= 3999): # figure out second part of & since if number if greater or less than 3999 or 0 then it wont work
                    print("\t" + word + " is " + str(num) + "")
                    return num
                if (tempWord == '') & ((0 >= num) or (num > 3999)):
                    print("\t" + word + " is " + str(num) + "")
                    return 0
                if (int(argument) % 1) == 0: #Not sure if this is needed or may cause  future issues, seems to work though 
                    print("\tError: enter a Roman Numeral")
                    return 0
romanNum(sys.argv[1:])

                    


