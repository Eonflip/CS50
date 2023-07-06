import sys
import csv
from cs50 import SQL

def main():
    # Connect to the SQLite database
    db = SQL("sqlite:///roster.db")

    #Ensure correct usage
    if sys.argv != 2:
        print("Usage: python prophecy.py file.csv")
        return

    with open(sys.argv[1], "r") as f:
        # Create DictReader object
        reader = csv.DictReader(f)

        for row in reader:
            # Insert student into database
            db.execute("INSERT INTO students(id, student_name, house, head) VALUES (?, ?, ?, ?)",
                       row["id"], row["student_name"], row["house"], row["head"])


            # Insert house into database
            db.execute("INSERT OR IGNORE INTO houses (house, head) VALUES (?, ?)",
                       row["house"], row["head"])


            db.execute("INSERT INTO house_assignment (student_id, house_name) VALUES (?, ?)",
                        row["id"], row["house"])

if __name__ == "__main__":
    main()

