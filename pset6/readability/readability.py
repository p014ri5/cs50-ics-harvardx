# Takes text as input
text = input("Text: ")

# Initialize variables
letters = 0
words = 1
sentences = 0

# Iterate and count stuff
for char in text:
    if char.isalpha():
        letters += 1
    elif char in [".", "?", "!"]:
        sentences += 1
    elif char == " ":
        words += 1

# Count letters and sentences per words
l = letters / words * 100
s = sentences / words * 100

# Calculate grade using Coleman-Liau index formula
grade = round(0.0588 * l - 0.296 * s - 15.8)

# Printing grade

if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")