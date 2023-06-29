import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)


    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    state_cases = {}

    for row in reader:
       state = row['state']
       cases = int(row['cases'])

       if state not in state_cases:
           state_cases[state] = [cases]

       elif state in state_cases:
           state_cases[state].append(cases)
           if len(state_cases[state]) > 14:
                state_cases[state] = state_cases[state][-14:]

    return state_cases


# TODO: Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for state in states:
        cases = new_cases[state]
        moving_average = sum(cases[-7:]) / 7
        print(f"{state}: {moving_average:.2f}")


main()
