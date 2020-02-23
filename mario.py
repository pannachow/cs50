height = input("Height: ")
height = int(height)

for row in range(height):
    for column in range(row + 1):
        print("#", end="")
    print()
