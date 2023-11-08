from cs50 import get_int

def main():
    height = get_int("Height: ")
    for i in range(1, height+1):
        for j in range(i, 0, -1):
            print("#", end="")
        print()

main()
