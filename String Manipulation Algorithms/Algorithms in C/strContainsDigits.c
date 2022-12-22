#include <stdio.h>
#include <string.h>

int is_string_digit(char *input)
{
    int i;
    int len = strlen(input);
    for (i = 0; i < len; i++)
    {
        if (input[i] < '0' || input[i] > '9')
            return 0;
    }
    return 1;
}

int main()
{
    char input[50];

    printf("Enter a string: ");
    scanf("%s", input);

    if (is_string_digit(input))
        printf("The string contains only digits\n");
    else
        printf("The string does not contain only digits\n");

    return 0;
}