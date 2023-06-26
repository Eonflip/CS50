from pyfiglet import Figlet
from sys import argv
from cs50 import get_string

figlet = Figlet()
fontList = figlet.getFonts();

for i in range(len(argv)):
    print(argv[i])

if len(argv) == 3:
    input = get_string("Input: ")
    f = Figlet(font = argv[1])
    print(f.renderText(f))

    for i in range(len(fontList)):
        if (argv[3] == i)
elif len(argv) == 1

