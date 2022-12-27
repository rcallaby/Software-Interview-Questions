# This program will find the first non-repeating character in a string

# Get the input string
string = input("Please enter a string: ")

# Initialize an empty dictionary 
dic = {}

# Loop through the characters in the string
for char in string:
    # If the character already exists in the dictionary, 
    # increment its count by 1
    if char in dic:
        dic[char] += 1
    # Otherwise, add the character to the dictionary
    # and set its value to 1
    else:
        dic[char] = 1

# Loop through the characters in the string
for char in string:
    # Check if the character's count is 1 in the dictionary
    if dic[char] == 1:
        # If so, print the character and break the loop
        print("The first non-repeating character is '" + char + "'")
        break

# If no character is found, print a message
else:
    print("No non-repeating characters found!")