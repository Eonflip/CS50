import cs50

def validate(n):
    number = n
    sum = 0
    sum = number % 10
    number = number // 10  # use integer division

    while number:
        temp = (number % 10) * 2
        if temp > 9:
            temp = temp - 9

        sum += temp
        number //= 10
        temp = number % 10
        sum += temp
        number //= 10

    while n > 100:
        n = n // 10

    if sum % 10:
        return False

    return n

def get_cc():
    while True:
        try:
            card_number = int(input("Please enter a valid credit card number: "))
            if card_number > 0:
                if len(str(card_number)) in [13, 15, 16]:  # convert to string before len()
                    return card_number
        except ValueError:
            print("Invalid input. Please enter an integer.")

def switch(n):
    if n == 34 or n == 37:
        return "AMEX\n"
    elif 40 <= n < 50:
        return "VISA\n"
    elif 51 <= n < 56:
        return "MASTERCARD\n"
    else:
        return "INVALID\n"

card_number = get_cc()
valid_number = validate(card_number)
switch(valid_number)










