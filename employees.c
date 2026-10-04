#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employees.h"
#include "validation.h"

#define MAX_EMPLOYEES 100
#define ID_LEN 15
#define NAME_LEN 30
#define FULLNAME_LEN 62
#define DEPT_LEN 30
#define POSITION_LEN 30
#define PENSION_RATE 0.05f

char empId[MAX_EMPLOYEES][ID_LEN];
char empName[MAX_EMPLOYEES][FULLNAME_LEN];
char empDept[MAX_EMPLOYEES][DEPT_LEN];
char empPosition[MAX_EMPLOYEES][POSITION_LEN];
float empBasic[MAX_EMPLOYEES];
float empHousing[MAX_EMPLOYEES];
float empTransport[MAX_EMPLOYEES];
float empGross[MAX_EMPLOYEES];
int employeeCount = 0;

void empClearInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void empReadString(char prompt[], char buffer[], int size)
{
    do
    {
        printf("%s", prompt);
        if (fgets(buffer, size, stdin) == NULL)
        {
            printf("\nInput ended. Exiting.\n");
            exit(1);
        }

        if (strcspn(buffer, "\n") == strlen(buffer))
        {
            empClearInput();
        }
        else
        {
            buffer[strcspn(buffer, "\n")] = '\0';
        }

        if (strlen(buffer) == 0)
        {
            printf("  Error: input cannot be empty.\n");
        }
    } while (strlen(buffer) == 0);
}
        
float empReadAmount(char prompt[], int allowZero)
{
    float value;
    int ok;
    int c;
    int valid = 0;

    while (valid == 0)
    {
        printf("%s", prompt);
        ok = scanf("%f", &value);

        if (ok == EOF)
        {
            printf("\nInput ended. Exiting.\n");
            exit(1);
        }

        if (ok != 1)
        {
            printf("  Error: please enter a valid number.\n");
            empClearInput();
        }
        else
        {
            c = getchar();
            if (c != '\n')
            {
                printf("  Error: please enter a valid number.\n");
                empClearInput();
            }
            else if (value < 0)
            {
                printf("  Error: amount cannot be negative.\n");
            }
            else if (value == 0 && allowZero == 0)
            {
                printf("  Error: amount must be greater than zero.\n");
            }
            else
            {
                valid = 1;
            }
        }
    }
    return value;
}

int empReadChoice(int min, int max)
{
    int choice;
    int ok;
    int c;
    int valid = 0;

    while (valid == 0)
    {
        printf("Enter your choice: ");
        ok = scanf("%d", &choice);

        if (ok == EOF)
        {
            printf("\nInput ended. Exiting.\n");
            exit(1);
        }

        if (ok != 1)
        {
            printf("  Invalid input. Enter a number from %d to %d.\n", min, max);
            empClearInput();
        }
        else
        {
            c = getchar();
            if (c != '\n')
            {
                printf("  Invalid input. Enter a number from %d to %d.\n", min, max);
                empClearInput();
            }
            else if (choice < min || choice > max)
            {
                printf("  Invalid choice. Enter a number from %d to %d.\n", min, max);
            }
            else
            {
                valid = 1;
            }
        }
    }
    return choice;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateTax(float gross)
{
    float tax;

    if (gross <= 4000)
    {
        tax = 0;
    }
    else if (gross <= 8000)
    {
        tax = (gross - 4000) * 0.15f;
    }
    else if (gross <= 15000)
    {
        tax = 600 + (gross - 8000) * 0.25f;
    }
    else
    {
        tax = 2350 + (gross - 15000) * 0.30f;
    }
    return tax;
}

float calculatePension(float basic)
{
    return basic * PENSION_RATE;
}

int searchEmployee(char id[], char ids[][ID_LEN], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (strcmp(ids[i], id) == 0)
        {
            return i;
        }
    }
    return -1;
}

void addEmployee(void)
{
    char id[ID_LEN];
    char firstName[NAME_LEN];
    char surname[NAME_LEN];
    int n = employeeCount;

    printf("\n--- ADD EMPLOYEE ---\n");

    if (n >= MAX_EMPLOYEES)
    {
        printf("Error: employee list is full.\n");
        return;
    }

    do
    {
        empReadString("Employee ID: ", id, ID_LEN);

        if (searchEmployee(id, empId, employeeCount) != -1)
        {
            printf("  Error: ID %s already exists.\n", id);
            strcpy(id, "");
        }
    } while (strlen(id) == 0);

    strcpy(empId[n], id);

    empReadString("First name: ", firstName, NAME_LEN);
    empReadString("Surname: ", surname, NAME_LEN);
    strcpy(empName[n], firstName);
    strcat(empName[n], " ");
    strcat(empName[n], surname);

    empReadString("Department: ", empDept[n], DEPT_LEN);
    empReadString("Position: ", empPosition[n], POSITION_LEN);

    empBasic[n]     = empReadAmount("Basic salary (N$): ", 0);
    empHousing[n]   = empReadAmount("Housing allowance (N$): ", 1);
    empTransport[n] = empReadAmount("Transport allowance (N$): ", 1);

    empGross[n] = calculateSalary(empBasic[n], empHousing[n], empTransport[n]);

    employeeCount++;
    printf("\nEmployee added successfully!\n");
}

void displayEmployees(void)
{
    int i;

    printf("\n--- ALL EMPLOYEES ---\n");

    if (employeeCount == 0)
    {
        printf("No employees registered yet.\n");
        return;
    }

    printf("\n%-10s %-25s %-15s %-20s %12s\n",
           "ID", "Name", "Department", "Position", "Gross (N$)");
    printf("--------------------------------------------------------------------------------\n");

    for (i = 0; i < employeeCount; i++)
    {
        printf("%-10s %-25s %-15s %-20s %12.2f\n",
               empId[i], empName[i], empDept[i], empPosition[i], empGross[i]);
    }

    printf("\nTotal employees: %d\n", employeeCount);
}

void searchEmployeeRecords(void)
{
    char text[FULLNAME_LEN];
    int choice;
    int i;
    int found = 0;
    int match;

    printf("\n--- SEARCH EMPLOYEE ---\n");

    if (employeeCount == 0)
    {
        printf("No employees registered yet.\n");
        return;
    }

    printf("1. Search by Employee ID\n");
    printf("2. Search by Full Name\n");
    printf("3. Search by Department\n");
    choice = empReadChoice(1, 3);

    empReadString("Enter search text: ", text, FULLNAME_LEN);

    for (i = 0; i < employeeCount; i++)
    {
        match = 0;

        switch (choice)
        {
            case 1:
                if (searchEmployee(text, empId, employeeCount) == i)
                {
                    match = 1;
                }
                break;
            case 2:
                if (strcmp(empName[i], text) == 0)
                {
                    match = 1;
                }
                break;
            case 3:
                if (strcmp(empDept[i], text) == 0)
                {
                    match = 1;
                }
                break;
        }

        if (match == 1)
        {
            if (found == 0)
            {
                printf("\n%-10s %-25s %-15s %-20s %12s\n",
                       "ID", "Name", "Department", "Position", "Gross (N$)");
                printf("--------------------------------------------------------------------------------\n");
            }
            printf("%-10s %-25s %-15s %-20s %12.2f\n",
                   empId[i], empName[i], empDept[i], empPosition[i], empGross[i]);
            found++;
        }
    }

    if (found == 0)
    {
        printf("No employee found for \"%s\" (search is case-sensitive).\n", text);
    }
    else
    {
        printf("\n%d employee(s) found.\n", found);
    }
}

void showSalarySlip(void)
{
    char id[ID_LEN];
    int position;
    float gross, tax, pension;

    printf("\n--- SALARY CALCULATION ---\n");

    if (employeeCount == 0)
    {
        printf("No employees registered yet.\n");
        return;
    }

    empReadString("Enter Employee ID: ", id, ID_LEN);
    position = searchEmployee(id, empId, employeeCount);

    if (position == -1)
    {
        printf("Employee %s not found.\n", id);
        return;
    }

    gross   = empGross[position];
    tax     = calculateTax(gross);
    pension = calculatePension(empBasic[position]);

    printf("\n========== SALARY SLIP ==========\n");
    printf("Employee ID  : %s\n", empId[position]);
    printf("Name         : %s\n", empName[position]);
    printf("Department   : %s\n", empDept[position]);
    printf("Position     : %s\n", empPosition[position]);
    printf("---------------------------------\n");
    printf("Basic salary        : N$%10.2f\n", empBasic[position]);
    printf("Housing allowance   : N$%10.2f\n", empHousing[position]);
    printf("Transport allowance : N$%10.2f\n", empTransport[position]);
    printf("Gross salary        : N$%10.2f\n", gross);
    printf("---------------------------------\n");
    printf("Income tax          : N$%10.2f\n", tax);
    printf("Pension (5%% basic)  : N$%10.2f\n", pension);
    printf("---------------------------------\n");
    printf("NET SALARY          : N$%10.2f\n", gross - tax - pension);
    printf("=================================\n");
}

int getEmployeeCount(void)
{
    return employeeCount;
}

float getAverageSalary(void)
{
    int i;
    float total = 0;

    if (employeeCount == 0)
    {
        return 0;
    }

    for (i = 0; i < employeeCount; i++)
    {
        total = total + empGross[i];
    }
    return total / employeeCount;
}

float getHighestSalary(void)
{
    int i;
    float highest;

    if (employeeCount == 0)
    {
        return 0;
    }

    highest = empGross[0];
    for (i = 1; i < employeeCount; i++)
    {
        if (empGross[i] > highest)
        {
            highest = empGross[i];
        }
    }
    return highest;
}

float getLowestSalary(void)
{
    int i;
    float lowest;

    if (employeeCount == 0)
    {
        return 0;
    }

    lowest = empGross[0];
    for (i = 1; i < employeeCount; i++)
    {
        if (empGross[i] < lowest)
        {
            lowest = empGross[i];
        }
    }
    return lowest;
}

void employeeMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("          EMPLOYEE MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Calculate Salary\n");
        printf("5. Back to Main Menu\n");

        choice = empReadChoice(1, 5);

        switch (choice)
        {
            case 1: addEmployee();           break;
            case 2: displayEmployees();      break;
            case 3: searchEmployeeRecords(); break;
            case 4: showSalarySlip();        break;
            case 5: printf("Returning to main menu...\n"); break;
        }
    } while (choice != 5);
}