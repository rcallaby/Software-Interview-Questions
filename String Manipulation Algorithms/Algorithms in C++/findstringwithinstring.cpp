#include <iostream>
#include <string>

using namespace std;

int findString(string mainStr, string toFind)
{
    size_t found = mainStr.find(toFind);
    if (found != string::npos)
        return found;
    else
        return -1;
}

int main()
{
    string mainStr = "This is a sample string";
    string toFind = "sample";
    int index = findString(mainStr, toFind);

    if (index >= 0)
        cout << "Found at index " << index << endl;
    else
        cout << "String not found!" << endl;
    return 0;
}