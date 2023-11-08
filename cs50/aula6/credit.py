from cs50 import get_int
from cs50 import get_string

def main():
    sum = 0
    card = get_string("Number: ")
    if len(card) < 13 or len(card) > 16
        print("INVALID")
        return 0

    for i in card
        number.append(int(card[i]))

    for i in range[0, len(card), 2]
        if number[i] * 2 // 10 == 0
            sum += number[i] * 2
        elsif i * 2 // 10 == 1
            sum += number[i] * 2 + 1

    for i in range[1, len(card), 2]
        sum += number[i]

    if sum // 10 == 0
        



