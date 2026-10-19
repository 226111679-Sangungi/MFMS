#ifndef EMPLOYEES_H
#define EMPLOYEES_H


#define MAX_EMPLOYEES 40
#define NAME_LEN 40
#define ID_LEN 60
#define LABEL_LEN 100
#define  DEPT_LEN 40

void employeeMenu( void);
void displayEmployee(void);
void SearchEmployee(void);
void  addEmployee(void);
void calculateSalary(void);
float  calculateTax(float grossSalary);
float   calculateGrossSalary(float basic, float housing, float transport);
float calculateNetSalary(float grossSalaray, float tax);
int getEmployeeCount(void);
float calculateTotalSalaries(void);
float  calculateAverageSalary(void);
float findHighestSalary(void);
float findlowestSalary(void);

#endif
