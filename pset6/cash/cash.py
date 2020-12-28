import cs50

# Initialize coins and total dollars
total = 0
coins = 0

# Get input continuously
while total <= 0:
    total = cs50.get_float("Change owed: ")

# Convert dollars to cents
cents = round(total * 100, 0)


# Count the coins
while cents > 0:
    if (cents >= 25):
        cents -= 25
        coins += 1
    elif (cents >= 10):
        cents -= 10
        coins += 1
    elif (cents >= 5):
        cents -= 5
        coins += 1
    else:
        cents -= 1
        coins += 1


# Print coins
print(coins)
