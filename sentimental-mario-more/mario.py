# TODO

def main():
    while True:
        user_input = int(input("Please enter a number: "))

        if user_input > 0  and user_input <= 8:
            break

    for num in range(1, user_input + 1):
        print((" " * (user_input - num)) + ("#" * num) + (" " * 2) + ("#" * num) + (" " * (user_input - num)))




main()