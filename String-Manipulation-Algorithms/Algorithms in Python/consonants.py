# Python prograam soluton to coount the number of consonants in a given string

def count_consonants(str1):
    consonant_count = 0
    for char in str1.lower():
        if char in "bcdfghjklmnpqrstvwxyz":
            consonant_count += 1
    return consonant_count

# Main program
str1 = input("Please enter a string: ")
consonant_count = count_consonants(str1)

print("The number of consonants in the string is:", consonant_count)