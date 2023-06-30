# TODO
import math

def main():
    excerpt = str(input("Text: "))

    print(excerpt)

    totalWords = 1 # changed to 1
    totalSentences = 0

    for letter in excerpt:
        if letter == " ":
            totalWords += 1
        if letter == "!" or letter == "?" or letter == ".":
            totalSentences += 1

    totalChar = len(excerpt) - (totalWords - 1) - totalSentences

    l = (totalChar / totalWords) * 100

    s = (totalSentences / totalWords) * 100

    grade_level = math.round(0.0588 * l - 0.296 * s - 15.8)

    if grade_level >= 1 and grade_level < 16:
        print(f"Grade {grade_level}")
    elif grade_level >= 16:
        print("Grade 16+")
    else:
        print("Before Grade 1")



main()