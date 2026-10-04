#include <stdio.h>
#include "common.h"
#include "validation.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

static void displayMenu(void)
{
    printf("\n========================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Employee Management\n");
    printf("2. Budget Management\n");
    printf("3. Supplier Management\n");
    printf("4. Asset Management\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("========================================\n");
}

int main(void)
{
    int choice;
    int running = 1;

    while (running) {
        displayMenu();
        choice = getMenuChoice(1, 6);

        switch (choice) {
            case 1: employeeMenu(); break;
            case 2: manageBudget(); break;
            case 3: supplierManagementMenu(); break;
            case 4: assetManagement(); break;
            case 5: displayReportsmenu(); break;
            case 6:
                printf("\nGoodbye!\n");
                running = 0;
                break;
        }
    }
    return 0;
}
