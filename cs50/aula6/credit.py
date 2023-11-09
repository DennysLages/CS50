from cs50 import get_int
from cs50 import get_string

def main():
    card_int = get_int("Number: ")
    card = str(card_int)
    number = []
    valid_len = [13, 15, 16]
    if len(card) not in valid_len:
        print("INVALID")
        return 0

    for i in range(0, len(card)):
        number.append(int(card[i]))

    if valid(number, card):
        if len(card) == 15 and card[0] == 3:
            if card[1] in [4, 7]:
                print("AMEX")

        if len(card) == 16 and card[0] == 5:
            if card[1] in range(1, 5):
                print("MASTERCARD")

        if len(card) in [13, 16] and card[0] == 4:
            print("VISA")


def valid(number, card):

    sum = 0
    for i in range(0, len(card), 2):
        # print(f"{number[i]}")
        print((i * 2 // 10))
        if number[i] * 2 // 10 == 0:
            sum += number[i] * 2
            # print(f"{number[i]} * 2 = {sum}")
        elif (i * 2 // 10) == 1:
            sum += number[i] * 2 + 1
            # print(f"{number[i]} * 2 = {sum}")

    for i in range(1, len(card), 2):
        # print(number[i])
        sum += number[i]
        # print(f"{number[i]} * 2 = {sum}")

    if sum // 10 == 0:
        return True
    else:
        print("INVALID")
        return False

main()


