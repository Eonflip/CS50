import sys
import csv

def main()
    if sys.argv == 2:
        reader = csv.DictReader(sys.argv[1])
        for row in reader:
            