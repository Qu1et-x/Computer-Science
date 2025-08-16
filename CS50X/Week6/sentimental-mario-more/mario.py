from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height in range(1, 9):
        break

for i in range(height):
    air = " " * (height - i - 1)
    wall = "#" * (i + 1)
    print(air + wall + "  " + wall)
