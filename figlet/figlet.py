from pyfiglet import Figlet
from sys import argv
from cs50 import get_string

figlet = Figlet()

for i in range(len(argv)):
    print(argv[i])

#if len(argv) == 2
#    input = get_string("Input: ")
#    f = Figlet(font = argv[1])
#    print(f.renderText(f))
#elif len(argv) == 0
