from cs50 import get_int


def main():
    while True:
        height = get_int("Height: ")
        if height > 0 and height < 9:
            break

    for i in range(1, height + 1):
        for j in range(i, height):
            print(" ", end="")
        for j in range(i, 0, -1):
            print("#", end="")

        print(" ")
        for j in range(i, 0, -1):
            print("#", end="")
        print()


main()
