from cs50 import get_string

greeting = get_string("Greeting: ")

greeting = greeting.lower()

if greeting.find("hello") != -1:
    print("$0")
elif greeting[0] == "h":
    print("$20")
else:
    print("$100")