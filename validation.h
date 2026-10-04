#ifndef VALIDATION_H
#define VALIDATION_H

int getInt(const char prompt[], int min, int max);
double getDouble(const char prompt[], double min);
void getString(const char prompt[], char buffer[], int size);
int getMenuChoice(int min, int max);
void getEmail(const char prompt[], char buffer[], int size);
void getPhone(const char prompt[], char buffer[], int size);
int getYesNo(const char prompt[]);
int isValidEmail(const char email[]);
int isValidPhone(const char phone[]);
void pressEnterToContinue(void);

#endif
