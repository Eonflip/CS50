from pyfiglet import Figlet
from sys import argv
from cs50 import get_string

figlet = Figlet()
fontList = figlet.getFonts();

for i in range(len(argv)):
    print(argv[i])

for i in range(len(fontList)):
    print(fontList[i])

#if len(argv) == 3:
#    input = get_string("Input: ")
#    f = Figlet(font = argv[1])
#    print(f.renderText(f))
#elif len(argv) == 1

