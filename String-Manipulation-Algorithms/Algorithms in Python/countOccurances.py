# Program to count occurrences of a character in a given string 

# Function to count occurrences of a character 
def countOccurrences(string, ch): 
	count = 0
	for i in range(len(string)): 
		if (string[i] == ch): 
			count = count + 1
	return count	 

string = input("Enter the string: ")
ch = input("Enter the character to find the occurrences: ")

print("Number of occurrences of", ch, "in", string, "is", countOccurrences(string, ch))