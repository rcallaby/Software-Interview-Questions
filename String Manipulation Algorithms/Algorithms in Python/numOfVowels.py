# define a function to count the number of vowels
def countVowels(string):
  # initialise the count variable
  count = 0
  # iterate through each character of the string
  for character in string:
    # check if the character is a vowel
    if character in 'aeiouAEIOU':
      # increment the count variable
      count += 1
  # return the count
  return count

# get the input string from the user
str = input('Please enter a string: ')

# call the count_vowels function
vowel_count = countVowels(str)

# print the result
print(f'The number of vowels in the string is {vowel_count}')