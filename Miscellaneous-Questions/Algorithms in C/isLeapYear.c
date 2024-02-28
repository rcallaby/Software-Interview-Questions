#include <stdio.h>

int IsLeapYear(int year);

int main() {
    int year;
	
    printf("Please enter the year: ");
    scanf("%d", &year);

    if (IsLeapYear(year)) {
        printf("%d is a leap year\n", year);
    } else {
        printf("%d is not a leap year\n", year);
    }

    return 0;
}

int IsLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return 1;
            else
                return 0;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}
