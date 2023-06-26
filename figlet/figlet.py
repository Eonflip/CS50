from pyfiglet import Figlet
from sys import argv
from cs50 import get_string

figlet = Figlet()
fontList = figlet.getFonts();

# Test code to ensure # of argv
#for i in range(len(argv)):
#    print(argv[i])


if len(argv) == 3:
    userInput = get_string("Input: ")

    for font in fontList:
        if (argv[2] == font):
            if (argv[1] == "-f" or argv[1] == "--font"):
                figlet.setFont(font = argv[2])
                print(figlet.renderText(userInput))

        else:
            print("Invalid Usage")
            sys.exit(1)

elif len(argv) == 1:
    


