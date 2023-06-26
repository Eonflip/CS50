from cs50 import get_string

greeting = get_string("Greeting:")



if greeting[0] == "h":
    print("$20")
elif greeting.find("hello") != -1:
    print("$0")
else:
    print("$100")