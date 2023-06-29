# TODO
import cs50

def main():

    switch(validate(get_cc()))



def get_cc():

    while True:
        try:
            card_number = int(input("Please enter a valid credit card number: "))
        except ValueError:
            return -1


def validate():
