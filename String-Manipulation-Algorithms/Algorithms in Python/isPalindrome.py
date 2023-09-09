# Define a function to check if a string is a palindrome
def isPalindrome(string):
    # Reverse the string
    rev_str = string[::-1]
    # Check if the string is equal to its reverse
    if (string == rev_str):
        return True
    return False

# Get input from the user
string = input("Please enter a string: ")

# Check if the string is a palindrome
if(isPalindrome(string)):
    print("The string is a palindrome.")
else:
    print("The string is not a palindrome.")