#include <stdio.h>
#include "reports.h"
void displayReportmenu(voiid) {
    printf("\n========================\n");
    printf("  MUNICIPAL REPORTS SYSTEM  ");
    printf("==========================\n");
    printf("1. Employee Summary Report\n");
    printf("2. Budget & Financial Report\n");
    printf("3. Supplier Listing Report\n");
    printf("4. Asset Management Report\n");
    printf("===========================\n");
}

void generateEmployeeReport(void) {
    printf("\n--- EMPLOYEE SUMMARY REPORT ---\n");
}

void generateBudgetReport(void) {
    printf("\n--- FINANCIAL & BUDGET REPORT ---\n");
}

void generateSupplierReport(void) {
    printf("\n--- REGISTERED SUPPLIERS REPORT ---\n");
}

void generateAssetReport(void) {
    printf("\n--- MUNICIPAL ASSETS REPORT ---\n");
}