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

PATH = './words-alpha.json'

def load_data():

    with open(PATH) as file:
        return json.load(file)

def halve_data():

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
        

def test():

    #print(vocabulary_size())
    #print(load_data()['aardvark'])

    halve_data()



if __name__ == '__main__':

    test()
    



