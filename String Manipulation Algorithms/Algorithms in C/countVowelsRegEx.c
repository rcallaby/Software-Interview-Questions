#include <stdio.h>
#include <regex.h>

// function to count vowels in a string
int countVowels(char* str)
{
    int count = 0;
    regex_t re;
    int reti;

    // compile regular expression
    reti = regcomp(&re, "[aeiouAEIOU]", 0);
    if (reti) {
        printf("Could not compile regex\n");
        exit(1);
    }

    reti = regexec(&re, str, 0, NULL, 0);
    while (reti == 0) {
        count++;
        str++;
        reti = regexec(&re, str, 0, NULL, 0);
    }

    // free compiled regular expression
    regfree(&re);

    return count;
}

int main()
{
    char str[] = "Hello World!";
    int count = countVowels(str);
    printf("Number of vowels in '%s' = %d\n", str, count);

    return 0;
}