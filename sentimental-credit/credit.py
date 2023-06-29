# TODO
import cs50

def switch(validate(get_cc())):




def get_cc():

    while True:
        try:
            card_number = int(input("Please enter a valid credit card number: "))
            if card_number > 0 and card_number < 50000000000000000:
                if len(card_number) == 13 or len(card_number) == 15 or len(card_number) == 16:
                    return card_number
        except ValueError:
            return -1


def validate():
