# define a function to check if two strings are anagrams
def isAnagram(str1, str2): 
  
    # remove all white space and convert strings to lowercase for comparison
    str1 = str1.replace(" ", "").lower()
    str2 = str2.replace(" ", "").lower()
  
    # sort the strings
    str1_list = sorted(str1)
    str2_list = sorted(str2)
  
    # check if the two strings are equal
    if str1_list == str2_list:
        return True
    else:
        return False
  
# get input from user
str1 = input("Please enter the first string: ")
str2 = input("Please enter the second string: ")

# check if two strings are anagrams
if isAnagram(str1, str2):
    print("The two strings are anagrams")
else:
    print("The two strings are not anagrams")