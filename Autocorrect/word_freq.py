import pandas as pd

PATH = './data/word-frequency.txt'
TO_PATH = "./data/frequency.csv"

def get_word_frequency():

    #data = pd.read_csv(PATH)

    fields = []

    with open(PATH) as file:
        for line in file:

            line_ = line.split()
            #print(line_)
            fields.append((line_[0], line_[1]))

    return fields

def write_frequency(word_freq):

    target_file = open(TO_PATH, "w")

    for word_fre in word_freq:
        rank, word = word_fre

        line = word + ", " + rank +'\n'

        #print(line)

        target_file.write(line)

if __name__ == '__main__':
    #print(get_word_frequency())
    words = get_word_frequency()
    write_frequency(words)
