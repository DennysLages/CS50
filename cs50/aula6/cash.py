from cs50 import get_float


def main():
    coins = 0
    while True
        change = get_float("Change owed: ")
        if change > 0
            break

    change = int(change*100)
    for coin in [25, 10, 5, 1]:
        if change > 0:
            coins += change // coin
            # print(change//coin)
            change -= (change // coin) * coin
            # print(coins)
    print(coins)

main()


        # if change mod 0.1 == 0:
        #     coin = int change / 0.1
        #     change = change mod 0.1
        # if change mod 0.05 == 0:
        #     coin = int change / 0.05
        #     change = change mod 0.05

