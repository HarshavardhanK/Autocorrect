import json

'''

Copyright Harshavardhan K January 2020

OBJECTIVE

The objective of this script would be to produce another text file which will have the content- the words
in order by which the vector will be fed to fill the tree

'''

#APPOACH

'''
Split the list in to half. Take the middle word and make it root--


'''

PATH = './data/words-alpha.json'
TO_PATH = './data/'

HALVED_PARENT_PATH = './data/halved/'

def load_data(path):

    with open(path) as file:
        return json.load(file)

def load_text_file(path):

    words = []

    with open(path) as file:
        for word in file:
            words.append(word)

    return words

#Halve the data to increase performance on a multithreaded system

def halve_data(char):

    path = TO_PATH + char + '.txt'

    words = load_text_file(path)

    length = len(words)

    first_filename = HALVED_PARENT_PATH + char + "1.txt"
    second_filename = HALVED_PARENT_PATH + char + "2.txt"

    file_first_half = open(first_filename, "w")
    file_second_half = open(second_filename, "w")

    top = words[0: length / 2]
    bottom = words[length / 2: length]

    for word in top:
        file_first_half.write(word)
    
    for word in bottom:
        file_second_half.write(word)

def distribute_data(path):

    word_len = 0

    data = load_data(path)
    words = data.keys()
    words_len = len(words)

    print("Total words in the vocabulary: {}".format(words_len))

    words.sort()

    for i in range(0, 26):

        alphabet = chr(97 + i)

        init_offset = word_len
        alpha_num = 0

        file = open(TO_PATH + alphabet + '.txt', "w")

        while(word_len < words_len and words[word_len][0] == alphabet):
            word_len += 1
            alpha_num += 1

        print("No. of words in {}: {}".format(alphabet, alpha_num))
        print("Ending index {}".format(word_len))
        
        word_alpha = words[init_offset:word_len]

        for word in word_alpha:
            file.write(word + '\n')

        print("Created a file for {} alphabet".format(alphabet))

    print("DONE")

def exec():

    for i in range(0, 26):
        halve_data(chr(97 + i))



#MAIN

if __name__ == '__main__':

    exec()
    



