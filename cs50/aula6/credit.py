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

    # print(valid(number,card))
    if (valid(number, card)):
        # print(f"{len(card)} & {card[0]} & {card[1]}")
        # print(f"{number[0]} & {number[1]}")
        # print("Is Valid")
        if len(card) == 15 and number[0] == 3 and (number[1] == 4 or number[1] == 7): # in [4, 7]:
            print("AMEX")
            # if card[1] in [4, 7]:
            #     print("AMEX")
            # else:
            #     print("INVALID1")

        if len(card) == 16 and number[0] == 5 and (number[1] > 0 or number[1] < 6):# in range(1, 5):
            print("MASTERCARD")
            # if card[1] in range(1, 5):
            #     print("MASTERCARD")
            # else:
            #     print("INVALID2")

        if len(card) in [13, 16] and number[0] == 4:
            print("VISA")
        else:
            print("INVALID")

        # if len(card) in [13, 15, 16]:
        #     print("Test worked")

        # if {card[0]} == 4:
            # print("Test 2 worked")
    # print("Reached the end of main function")

def valid(number, card):

    sum = 0
    for i in range(0, len(card),2):
        sum += (((number[i] * 2) // 10) + (number[i] * 2) % 10)
        # print(f"{number[i] * 2} {sum}")
        # print(sum)
        # print((i * 2 // 10))
        # if number[i] * 2 // 10 == 0:
        #     sum += number[i] * 2
        #     # print(f"{number[i]} * 2 = {sum}")
        # elif (i * 2 // 10) == 1:
        #     sum += number[i] * 2 + 1
        #     # print(f"{number[i]} * 2 = {sum}")

    for i in range(1, len(card), 2):
        # print(number[i])
        sum += number[i]
        # print(f"{number[i]} {sum}")
        # print(f"{number[i]} * 2 = {sum}")

    if sum % 10 != 0:
        print("INVALID")
        return False
    else:
        return True

main()


