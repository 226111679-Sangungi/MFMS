#include <stdio.h>
#include "reports.h"
#include "validation.h"
#include "employees.h"
#include "suppliers.h"
#include "budget.h"

void displayReportsmenu(void)
{
    int choice;

    do {
        printf("\n==========================\n");
        printf("  MUNICIPAL REPORTS SYSTEM\n");
        printf("\n==========================\n");
        printf("1. Employee Summary Report\n");
        printf("2. Budget & Financial Report\n");
        printf("3. Supplier Listing Report\n");
        printf("4. Asset Management Report\n");
        printf("5. Back to Main Menu\n");
        printf("==========================\n");

        choice = getInt("Enter your choice: ", 1, 5);

        switch (choice) {
            case 1: generateEmployeeReport(); break;
            case 2: generateBudgetReport();   break;
            case 3: generateSupplierReport(); break;
            case 4: generateAssetReport();    break;
            case 5: break;
        }
        if (choice != 5) {
            pressEnterToContinue();
        }
    } while (choice != 5);
}


void generateEmployeeReport(void)
{
    printf("\n--- EMPLOYEE SUMMARY REPORT ---\n");

    if (getEmployeeCount() == 0) {
        printf("No employees registered yet.\n");
        return;
    }

    printf("Total Employees: %d\n", getEmployeeCount());
    printf("Average Salary : N$%.2f\n", getAverageSalary());
    printf("Highest Salary : N$%.2f\n", getHighestSalary());
    printf("Lowest Salary  : N$%.2f\n", getLowestSalary());
}


void generateBudgetReport(void)
{

    printf("\n--- FINANCIAL & BUDGET REPORT ---\n");
}

void generateSupplierReport(void) {
    printf("\n--- REGISTERED SUPPLIERS REPORT ---\n");
}

void generateAssetReport(void) {
    printf("\n--- MUNICIPAL ASSETS REPORT ---\n");
}