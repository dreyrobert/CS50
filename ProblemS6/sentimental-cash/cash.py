from cs50 import get_float
from math import floor

def main():
    while True:
        change = get_float("Change owed: ")
        if change > 0:
            break

    # 0.25 - 0.10 - 0.05 - 0.01
    quarters = floor(change / 0.25)
    change = change - (0.25 * quarters)
    dimes = floor(change / 0.10)
    change = change - (0.10 * dimes)
    nickels = floor(change / 0.05)
    change = change - (0.05 * nickels)
    pennies = (change / 0.01)
    change = change - (0.01 * pennies)
    print(round(quarters + dimes + nickels + pennies))

main()