#include <stdio.h>
#include "budget.h"

float calculateRemaining(float budget,float expenditure)
{
    return budget - expenditure;
}

void checkBudgetStatus(float budget, float expenditure)
{
    if (expenditure <= budget)
}
printf("Status: WITHIN BUDGET\n");
{
    else{
        printf("Status: OVER BUDGET\n")
    }
}

void manageBudget(void)
{
    float budget;
    float expenditure;
    float remaining;
    printf("\n --- MUNICIPAL BUDGET MANAGEMENT ---\n");
    scanf("%f", &budget);

    printf("Enter current expenditure: ");
    scanf("%f", &expenditure);

    remaining = calculateRemaining(budget, expenditure);

    printf("\n--- BUDGET SUMMARY ---\n");
    printf("Allocated Budget:%.2f\n", budget);
    printf("Total Expenditure:%.2f\n" , expenditure);
    printf("Remaining Balance:%.2f\n", remaining);

    checkBudgetStatus(budget, expenditure);
}