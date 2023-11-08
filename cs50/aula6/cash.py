from cs50 import get_float


def main():
    int coin = 0
    change = get_float("Change owed: ")
    for coins in [0.25, 0.1, 0.05, 0.01]
        if change mod coins == 0:
            coin += int change / coins
            change = change mod coins

main()


        # if change mod 0.1 == 0:
        #     coin = int change / 0.1
        #     change = change mod 0.1
        # if change mod 0.05 == 0:
        #     coin = int change / 0.05
        #     change = change mod 0.05

