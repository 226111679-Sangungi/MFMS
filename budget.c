#include <stdio.h>
#include <string.h>
#include <budget.h>

static char dept_names[max_departments][max_name_len};
static double allocated_budget[max_departnames];
static double expenditure[max_departments];
static int dept_count = 0;

void addDepartmentBudget(void) {
    if (dept_count >= max_departments) {
        printf("\nError: Maximum department limit reached.\n");
        return;
    }

    printf("\n--- Add Department Budget ---\n");
    printf("Enter Department Name: ");
    scanf(" %[^\n]", dept_names[dept_count]);

    do {
        printf("Enter Allocated Budget (N$): ");
        if (scanf("%lf", &allocated_budget[dept_count]) != 1 || allocated_budget[dept_count] < 0) {
            printf("Invalid input! Budget cannot be negative.\n");
            while (getchar() != '\n');
        } else break;
    } while (1);

    do {
        printf("Enter Current Expenditure (N$): ");
        if (scanf("%lf", &expenditure[dept_count]) != 1 || expenditure[dept_count] < 0) {
            printf("Invalid input! Expenditure cannot be negative.\n");
            while (getchar() != '\n');
        } else break;
    } while (1);

    dept_count++;
    printf("Budget recorded successfully!\n");
}

void displayBudgetInformation(void) {
    if (dept_count == 0) {
        printf("\nNo budget records found.\n");
        return;
    }

    printf("\n=======================================\n");
    printf("%-20s | %-12s | %-12s | %-12s | %-15s\n", "Department", "Allocated", "Expenditure", "Remaining", "Status");
    printf("\n=======================================\n");

    for (int i = 0; i < dept_count; i++) {
        double remaining = allocated_budget[i] - expenditure[i];
        char *status = (expenditure[i] > allocated_budget[i]) ? "EXCEEDED BUDGET" : "WITHIN BUDGET";
        printf("%-20s | N$%-10.2f | N$%-10.2f | N$%-10.2f | %-15s\n",
               dept_names[i], allocated_budget[i], expenditure[i], remaining, status);
    }
}

void displayOverBudgetDepartments(void) {
    int found = 0;
    printf("\n--- Departments Exceeding Allocated Budget ---\n");
    for (int i = 0; i < dept_count; i++) {
        if (expenditure[i] > allocated_budget[i]) {
            printf("Department: %s | Over Budget By: N$%.2f\n", dept_names[i], expenditure[i] - allocated_budget[i]);
            found = 1;
        }
    }
    if (!found) printf("All departments are within their allocated budget.\n");
}