# TODO

def main():
    while True:
        try:
            user_input = int(input("Please enter a number: "))

            if user_input > 0  and user_input <= 8:
                break

        except ValueError:
            print("You must enter a number...")

    for num in range(1, user_input + 1):
        print((" " * (user_input - num)) + ("#" * num) + (" " * 2) + ("#" * num))




main()