# This is a possible solution to find a string within a string. It returns true. It would be better if it returned the index
# of the string

def find_string(string, sub_string): 
 
    length = len(sub_string) 
  
    # Iterate over the length of the string 
    for i in range(len(string)):
        if (string[i: i + length] == sub_string): 
            return True
    return False
  

string = "This is the string to search in"
sub_string = "search"
  
if (find_string(string, sub_string)): 
    print("Yes, the string is found") 
else: 
    print("No, the string is not found")