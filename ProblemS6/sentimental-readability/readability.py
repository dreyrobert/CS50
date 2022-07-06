from cs50 import get_string

def whatGrade(numWords, numLetters, numSentences):
    L = numLetters / numWords * 100
    S = numSentences / numWords * 100
    grade = round(0.0588 * L - 0.296 * S - 15.8)
    return grade

def countLetters(text):
    l = 0
    for c in text:
        if c.isalpha():
            l += 1
    return l

def countWords(text):
    w = 0
    for c in text:
        if c == " ":
            w += 1
    w += 1
    return w

def countSentences(text):
    sentence = 0
    for c in text:
        if c == "." or c == "?" or c == "!":
            sentence += 1
    return sentence

def main():
    text = get_string("Text: ")

    numLetters = countLetters(text)
    numWords = countWords(text)
    numSentences = countSentences(text)

    grade = whatGrade(numWords, numLetters, numSentences)

    if grade < 1:
        print("Before Grade 1")
    elif grade > 15:
        print("Grade 16+")
    else:
        print("Grade: {}".format(grade))

main()
