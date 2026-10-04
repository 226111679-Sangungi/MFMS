#ifndef BUDGET_H
#define BUDGET_H

void addBudget();
void displayBudget();
void searchBudget();

float calculateRemaining(float budget,float expenditure);

void checkBudgetStatus(float budget, float expenditure);
void manageBudget(void);
float getTotalBudget(void);
float gettotalExpenditure(void);

#endif