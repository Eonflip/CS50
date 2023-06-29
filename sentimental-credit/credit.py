# TODO
import cs50

def main():

    while True:
        try:
            card_number = int(input("Please enter a valid credit card number: "))
            for num in card_number:

        except ValueError:
            print("That is not a valid credit card number\n")



def get_cc():

    while True:
        try:
            card_number = int(input("Please enter a valid credit card number: "))
        except ValueError:
            print("That is not a valid credit card number\n")
            return 0


def validate():
