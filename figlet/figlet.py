from pyfiglet import Figlet
from sys import argv
from sys import exit
from cs50 import get_string
import random

figlet = Figlet()
fontList = figlet.getFonts();

# Test code to ensure # of argv
#for i in range(len(argv)):
#    print(argv[i])


if len(argv) == 3:
    userInput = get_string("Input: ")

    if argv[2] not in fontList:
        print("Invalid Usage")
        exit(1)

    if argv[1] not in ["-f", "--font"]:
        print("Invalid Usage")
        exit(1)


    figlet.setFont(font = argv[2])
    print("Output:")
    print(figlet.renderText(userInput))
    exit(0)


elif len(argv) == 1:
    randomFont = random.randint(0, len(fontList) - 1)
    userInput = get_string("Input: ")

    figlet.setFont(font = fontList[randomFont])
    print("Output: ")
    print(figlet.renderText(userInput))
    exit(0)


else:
    print("Invalid Usage")
    exit(1)




