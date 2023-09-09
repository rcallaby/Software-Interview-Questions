using System;
using System.IO;
using System.Text;
using System.Collections.Generic;

int main()
{

}


/* This is just a function to find the length of a string without using an in built libraries

*/

int FindStringLength(string str)
{
    int length = 0;

    while (str[length] != '\0')
    {
        length++;
    }

    return length;
}