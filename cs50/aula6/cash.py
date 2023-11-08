from cs50 import get_float


def main():
    coins = 0
    change = get_float("Change owed: ")
    for coin in [0.25, 0.1, 0.05, 0.01]:
        if change / coin > 0:
            coins += change // coin
            change = change - change // coin
    print(coins)

main()


        # if change mod 0.1 == 0:
        #     coin = int change / 0.1
        #     change = change mod 0.1
        # if change mod 0.05 == 0:
        #     coin = int change / 0.05
        #     change = change mod 0.05

