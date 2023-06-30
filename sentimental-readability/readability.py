# TODO
import math

def main():
    sentence = input("Text: ")
    print(sentence)

    totalWords = 0
    totalSentences = 0

    for letter in sentence:
        if letter = " ":
            totalWords += 1
        if letter = "!" or letter = "?" or letter = ".":
            totalSentences += 1

    l = float(len(sentence) / totalWords) * 100

    s = float(totalSentences / totalWords) * 100

    grade_level = round(0.0588 * l - 0.296 * s - 15.8)

    if grade_level >= 1 and grade_level < 16:
        print(f"Grade {grade_level}")
    elif grade_level >= 16:
        print("Grade 16+")
    else:
        print(Before Grade 1)

