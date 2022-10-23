import re
import string


def printsomething():
    print("Hello from python!")

def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def SquareValue(v):
    return v * v


def MultiplicationTable(v):
    for i in range(1, 11):
        print("{} X {} = {}".format(v, i, v*i))
    return 1


def DoubleValue(v):
    return v* 2

def GetAllWordCount():  
        fopen= open ("..\Release\CS210 Project Three Input.txt", "r") #opens the file in read mode
        word_count = dict() #creates an empty dictionary
        for line in fopen:
            line = line.strip()
            word = line.lower()
            if word in word_count: #checks if the word is already in the dictionary or not and then increments by one
                word_count[word] = word_count[word]+1
            else:
                word_count[word] = 1
        for key in list (word_count.keys()):
            print(key.capitalize(), ":", word_count[key])
       
def GetWordCount(v):  
        fopen= open ("..\Release\CS210 Project Three Input.txt", "r") #opens the file in read mode
        word_count = 0
        for line in fopen:
            line = line.strip()
            word = line.lower()
            if word == (v.lower()): #converts input to lowercase to match word list
                word_count += 1 #if the word is found the count is incremented by 1 if not 0 will be printed
        print (v, " ", word_count);
        fopen.close()
               
          


def MakeNewFile():
        fopen= open ("..\Release\CS210 Project Three Input.txt", "r") #opens the file in read mode
        freq_file = open("frequency.dat", "w") #creates a file in write mode
        word_count = dict() #creates an empty dictionary
        for line in fopen:
            line = line.strip()
            word = line.lower()
            if word in word_count: 
                word_count[word] = word_count[word]+1
            else:
                word_count[word] = 1
        for key in list (word_count.keys()):
            freq_file.write(str(key.capitalize()) + " " + str(word_count[key]) + "\n") #writes to the new file
        fopen.close()
        freq_file.close()



