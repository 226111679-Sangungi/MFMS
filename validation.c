#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validation.h"

/* Throws away the rest of the line. Returns 1 if anything other
   than spaces/tabs was found, otherwise 0. */
static int clearInputBuffer(void)
{
    int extra = 0;
    int ch = getchar();

    while (ch != '\n' && ch != EOF) {
        if (ch != ' ' && ch != '\t') {
            extra = 1;
        }
        ch = getchar();
    }
    return extra;
}

int getInt(const char prompt[], int min, int max)
{
    int value;
    int result;

    while (1) {
        printf("%s", prompt);
        result = scanf("%d", &value);

        if (result == EOF) {
            printf("\nInput ended. Exiting program.\n");
            exit(1);
        }

        if (result != 1) {
            clearInputBuffer();
            printf("Error: please enter a whole number.\n");
        } else if (clearInputBuffer() == 1) {
            printf("Error: please enter a whole number only.\n");
        } else if (value < min || value > max) {
            printf("Error: value must be between %d and %d.\n", min, max);
        } else {
            return value;
        }
    }
}

double getDouble(const char prompt[], double min)
{
    double value;
    int result;

    while (1) {
        printf("%s", prompt);
        result = scanf("%lf", &value);

        if (result == EOF) {
            printf("\nInput ended. Exiting program.\n");
            exit(1);
        }

        if (result != 1) {
            clearInputBuffer();
            printf("Error: please enter a valid number.\n");
        } else if (clearInputBuffer() == 1) {
            printf("Error: please enter a valid number only.\n");
        } else if (value < min) {
            printf("Error: value cannot be less than %.2f.\n", min);
        } else {
            return value;
        }
    }
}

void getString(const char prompt[], char buffer[], int size)
{
    int count;
    int hasText;
    int ch;

    while (1) {
        printf("%s", prompt);
        count = 0;
        hasText = 0;

        ch = getchar();
        while (ch != '\n' && ch != EOF) {
            if (count < size - 1) {
                buffer[count] = (char)ch;
            }
            count++;
            if (ch != ' ' && ch != '\t') {
                hasText = 1;
            }
            ch = getchar();
        }

        if (ch == EOF) {
            printf("\nInput ended. Exiting program.\n");
            exit(1);
        }

        if (hasText == 0) {
            printf("Error: this field cannot be empty.\n");
        } else if (count > size - 1) {
            printf("Error: too long (maximum %d characters).\n", size - 1);
        } else {
            buffer[count] = '\0';
            return;
        }
    }
}

int getMenuChoice(int min, int max)
{
    return getInt("Enter your choice: ", min, max);
}

int isValidEmail(const char email[])
{
    int len = (int)strlen(email);
    int at = -1;
    int lastDot = -1;
    int i;

    if (len < 5) {
        return 0;
    }

    for (i = 0; i < len; i++) {
        if (email[i] == ' ') {
            return 0;
        }
        if (email[i] == '@') {
            if (at != -1) {
                return 0;
            }
            at = i;
        }
    }

    if (at < 1) {
        return 0;
    }

    for (i = at + 1; i < len; i++) {
        if (email[i] == '.') {
            lastDot = i;
        }
    }

    if (lastDot == -1 || lastDot == at + 1 || lastDot == len - 1) {
        return 0;
    }
    return 1;
}

int isValidPhone(const char phone[])
{
    int i = 0;
    int digits = 0;

    if (phone[0] == '+') {
        i = 1;
    }

    while (phone[i] != '\0') {
        if (phone[i] < '0' || phone[i] > '9') {
            return 0;
        }
        digits++;
        i++;
    }

    if (digits >= 7 && digits <= 15) {
        return 1;
    }
    return 0;
}

void getEmail(const char prompt[], char buffer[], int size)
{
    while (1) {
        getString(prompt, buffer, size);
        if (isValidEmail(buffer) == 1) {
            return;
        }
        printf("Error: invalid email (example: name@example.com).\n");
    }
}

void getPhone(const char prompt[], char buffer[], int size)
{
    while (1) {
        getString(prompt, buffer, size);
        if (isValidPhone(buffer) == 1) {
            return;
        }
        printf("Error: phone must be 7 to 15 digits (optional leading +).\n");
    }
}

int getYesNo(const char prompt[])
{
    char answer[10];

    while (1) {
        getString(prompt, answer, 10);
        if (strlen(answer) == 1 && (answer[0] == 'y' || answer[0] == 'Y')) {
            return 1;
        }
        if (strlen(answer) == 1 && (answer[0] == 'n' || answer[0] == 'N')) {
            return 0;
        }
        printf("Error: please enter y or n.\n");
    }
}

void pressEnterToContinue(void)
{
    printf("\nPress Enter to continue...");
    clearInputBuffer();
}
