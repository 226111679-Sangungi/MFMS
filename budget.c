#include <stdio.h>
#include "budget.h"
#include "validation.h"


float calculateRemaining(float budget,float expenditure)
{
    return budget - expenditure;
}

void checkBudgetStatus(float budget, float expenditure)
{
    if (expenditure <= budget) {
        printf("Status: WITHIN BUDGET\n");
    }
    else {
        printf("Status: OVER BUDGET\n");
    }
}

void manageBudget(void)
{
    float budget;
    float expenditure;
    float remaining;
    
    printf("\n --- MUNICIPAL BUDGET MANAGEMENT ---\n");
    
    budget = (float)getDouble("Enter allocated budget: N$", 0);
    expenditure = (float)getDouble("Enter current expenditure: N$", 0);

    remaining = calculateRemaining(budget, expenditure);

    printf("\n--- BUDGET SUMMARY ---\n");
    printf("Allocated Budget:%.2f\n", budget);
    printf("Total Expenditure:%.2f\n" , expenditure);
    printf("Remaining Balance:%.2f\n", remaining);

    checkBudgetStatus(budget, expenditure);

    pressEnterToContinue();
}