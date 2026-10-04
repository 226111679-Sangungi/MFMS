#ifndef EMPLOYEES_h
#define EMPLOYEES_h
#define MAX_ITEMS 50
#define STR_LEN 50

typedef struct {
    char id[STR_LEN];
    char name[STR_LEN];
    char department[STR_LEN];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
    double grossSalary;
} Employee;


void clearBuffer(void);
double calculateGrossSalary(double basic, double housing, double transport);

void addEmployee(Employee list[], int *count);
void displayEmployees(const Employee list[], int count);
void searchEmployee(const Employee list[], int count);
void employeeMenu(void);
#endif