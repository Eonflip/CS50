from pyfiglet import Figlet
from sys import argv
from cs50 import get_string

figlet = Figlet()
fontList = figlet.getFonts();

for i in range(len(argv)):
    print(argv[i])

if len(argv) == 3:
    userInput = get_string("Input: ")

    for i in range(len(fontList)):
        if (argv[2] == i):
            if (argv[1] == "-f" or argv[1] == "--font"):
                user_input = figlet.setFont(font = argv[2])
                user_input = figlet.renderText(userInput)
                print(user_input)

#elif len(argv) == 1

