# Validation and getting input
while True:
    mb = input("Height: ")
    try:
        mb = int(mb)  # Checking if input is int cuz regex sucks 
    except:
        continue
    if mb not in range(1, 9):  # Checking if in range
        continue
    else:
        break

# printing the bricks
for i in range(1, mb + 1):
    preindent = " " * (mb - i)
    bricks = "#" * i
    gap = " " * 2
    print(preindent + bricks + gap + bricks)
