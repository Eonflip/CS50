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
            break


def validate(n):

    number = n
    sum = 0

    sum = number % 10
    number = number / 10

    while number:
        temp = (number % 10) * 2
        if temp > 9:
            temp = temp - 9

        sum += temp
        number /= 10
        temp = number % 10
        sum += temp
        number /= 10


    while n > 100:
        n = n / 10


    if sum % 10:
        break


    return n




