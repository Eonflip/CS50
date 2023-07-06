import sys
import csv
from cs50 import SQL

def main()
    db = SQL.("sqlite:///roster.db)
    if sys.argv == 2:
        reader = csv.DictReader(sys.argv[1])
        for row in reader:

