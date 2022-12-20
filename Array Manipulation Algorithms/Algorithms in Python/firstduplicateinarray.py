# Defining an array with 50 numbers
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 33, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50]

# Function to find first instance of duplicate in an array
def find_duplicate(array):
  seen = set()
  for element in array:
    if element in seen:
      return element
    else:
      seen.add(element)

# Calling the function to find the first instance of duplicate in the array
result = find_duplicate(numbers)

# Printing the result
print(f"The first instance of duplicate in the array is {result}")