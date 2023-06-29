# TODO
# create main function
def main():
    # continue to ask for user input until they enter a number between 1-8
    while True:
        try:
            user_input = int(input("Please enter a number: "))

            if user_input > 0 and user_input <= 8:
                break
        # if user does not enter an int throw value error
        except ValueError:
            print("You must enter a number...")
    # loop through numbers in range to print # tower
    for num in range(1, user_input + 1):
        print((" " * (user_input - num)) + ("#" * num) + (" " * 2) + ("#" * num))


main()