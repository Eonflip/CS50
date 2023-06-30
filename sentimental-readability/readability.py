# TODO

def main():
    # Ask user for input and print it out
    excerpt = str(input("Text: "))
    print(excerpt)
    # Define values for words, sentences, and characters
    totalWords, totalSentences, totalChar = 1, 0, 0

    # Loop through the excerpt input and increment values
    for letter in excerpt:
        if letter == " ":
            totalWords += 1
        elif letter == "!" or letter == "?" or letter == ".":
            totalSentences += 1
        elif letter.isalnum():
            totalChar += 1

    #calculations for 
    l = (totalChar / totalWords) * 100

    s = (totalSentences / totalWords) * 100

    grade_level = round(0.0588 * l - 0.296 * s - 15.8)

    if grade_level >= 1 and grade_level < 16:
        print(f"Grade {grade_level}")
    elif grade_level >= 16:
        print("Grade 16+")
    else:
        print("Before Grade 1")

main()