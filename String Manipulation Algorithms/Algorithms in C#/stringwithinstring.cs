
int main(){
    

}


public static bool FindStringInAString(string str, string substr)
{
    // Initialize the return value to false
    bool found = false;

    // If either of the strings is null or empty, return false
    if (string.IsNullOrEmpty(str) || string.IsNullOrEmpty(substr))
    {
        return false;
    }

    // Iterate through the string
    for (int i = 0; i < str.Length - substr.Length + 1; i++)
    {
        // If the substring is found, set the return value to true and break out of the loop
        if (str.Substring(i, substr.Length) == substr)
        {
            found = true;
            break;
        }
    }

    return found;
}