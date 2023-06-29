import math

# create function to get credit card number
def get_cc():
    n = int(input("Enter a credit card number: "))
    if 0 <= n <= 50000000000000000:
        num_digits = int(math.log10(abs(n))) + 1
        if num_digits in {13, 15, 16}:
            return n
    return -1

# create function to validate the card number
def validate(n):
    sum_digits, number = n % 10, n // 10

    while number > 0:
        temp = (number % 10) * 2
        temp = temp - 9 if temp > 9 else temp
        sum_digits += temp + number // 10 % 10
        number //= 100

    while n > 100:
        n //= 10

    return -1 if sum_digits % 10 else n


def main():
    card_types = {
        34: "AMEX",
        37: "AMEX",
        40: "VISA",
        41: "VISA",
        42: "VISA",
        43: "VISA",
        44: "VISA",
        45: "VISA",
        46: "VISA",
        47: "VISA",
        48: "VISA",
        49: "VISA",
        51: "MASTERCARD",
        52: "MASTERCARD",
        53: "MASTERCARD",
        54: "MASTERCARD",
        55: "MASTERCARD",
    }
    #if card_types.get returns a value that matches a key in the dict, it prints the value from that key, if not, print "INVALID"
    print(card_types.get(validate(get_cc()), "INVALID"))


if __name__ == "__main__":
    main()