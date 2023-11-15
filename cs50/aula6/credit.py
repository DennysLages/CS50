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

    if (valid(number, card)):
        # print(f"{len(card)} & {card[0]} & {card[1]}")
        # print(f"{number[0]} & {number[1]}")

        if len(card) == 15 and number[0] == 3 and (number[1] == 4 or number[1] == 7): # in [4, 7]:
            print("AMAAMEX")

        if len(card) == 16 and number[0] == 5 and (number[1] > 0 or number[1] < 6):# in range(1, 5):
            print("MASTERCARD")

        if len(card) in [13, 16] and number[0] == 4:
            print("VISA")
        else:
            print("INVALID")

def valid(number, card):

    sum = 0
    for i in range(len(card) - 2, -1, -2):
        sum += (((number[i] * 2) // 10) + (number[i] * 2) % 10)
        # print(f"{number[i]} * 2 = {sum}")

    for i in range(len(card) - 1, -1, -2):
        # print(number[i])
        sum += number[i]
        # print(f"{number[i]} {sum}")

    if sum % 10 != 0:
        print("INVALID")
        return False
    else:
        return True

main()


