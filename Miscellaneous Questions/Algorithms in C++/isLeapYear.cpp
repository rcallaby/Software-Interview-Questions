#include <iostream> 
using namespace std; 

int main() 
{ 
    int year; 
  
    cout << "Enter a year: "; 
    cin >> year; 
  
    // leap year if perfectly visible by 4 
    if (year % 4 == 0) { 
        if (year % 100 == 0) { 
            // year is leap year if its multiple of 400 
            if (year % 400 == 0) 
                cout << year << " is a leap year"; 
            else
                cout << year << " is not a leap year"; 
        } 
        else
            cout << year << " is a leap year"; 
    } 
    else
        cout << year << " is not a leap year"; 
  
    return 0; 
}