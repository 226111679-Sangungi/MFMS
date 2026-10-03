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