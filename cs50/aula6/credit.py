from cs50 import get_int
from cs50 import get_string

def main():
    sum = 0
    card_int = get_int("Number: ")
    card = str(card)
    if len(card) == 13, 15, 16 #< 13 or len(card) > 16:
        print("INVALID")
        return 0

    for i in card:
        number.append(int(card[i]))

    if valid(number):
        if len(card) == 15 and card[0] == 3 and card[1] ==

def valid(number):

    for i in range[0, len(card), 2]:
        if number[i] * 2 // 10 == 0:
            sum += number[i] * 2
        elsif i * 2 // 10 == 1:
            sum += number[i] * 2 + 1

    for i in range[1, len(card), 2]:
        sum += number[i]

    if sum // 10 == 0:
        return True
    else:
        return False

main()


