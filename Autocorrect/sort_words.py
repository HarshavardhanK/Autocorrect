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

def load_data():

    with open(PATH) as file:
        return json.load(file)

def halve_data(filename):

    data = load_data()
    words = data.keys()

    words.sort()

    length = len(words)

    file_first_half = open('./first_words.txt', "w")
    file_second_half = open('./second_words.txt', "w")

    top = words[0: length / 2]
    bottom = words[length / 2: length]

    for word in top:
        file_first_half.write(word+'\n')
    
    for word in bottom:
        file_second_half.write(word+'\n')

def distribute_data():

    word_len = 0

    data = load_data()

    words = data.keys()
    words_len = len(words)

    print("Total words in the vocabulary: {}".format(words_len))

    words.sort()

    for i in range(0, 26):

        alphabet = chr(97 + i)

        file = open(TO_PATH + alphabet + '.txt', "w")

        init_offset = word_len
        alpha_num = 0

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



def test():

    #print(vocabulary_size())
    #print(load_data()['aardvark'])

    halve_data()
    #distribute_data()



if __name__ == '__main__':

    distribute_data()
    



