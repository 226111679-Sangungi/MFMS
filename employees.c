#include <stdio.h>
#include <string.h>



#define MAX_EMPLOYEES 50 
#define ID_LEN 20
#define NAME_LEN 50
#define DEPT_LEN 30
#define LABEL_LEN 80

void employeeMenu(void);
void addEmployee(void);
void displayEmployees(void);
void searchEmployee(void);
void calculateSalary(void);
float calculateGrossSalary(float basic, float housing, float transport);
float calculateTax(float grossSalary);
float calculateNetSalary(float grossSalary, float tax);
int getEmployeeCount(void); 
float calculateTotalSalaries(void);
float calculateAverageSalary(void);
float findHighestSalary(void); 
float findLowestSalary(void);

char empID[MAX_EMPLOYEES][ID_LEN];
char empName[MAX_EMPLOYEES][NAME_LEN];
char empDept[MAX_EMPLOYEES][DEPT_LEN];
float empBasicSalary[MAX_EMPLOYEES];
float empHousingAllowance[MAX_EMPLOYEES];
float empTransportAllowance[MAX_EMPLOYEES];
float empGross[MAX_EMPLOYEES];
float empTax[MAX_EMPLOYEES];
float empNetSalary[MAX_EMPLOYEES];

int employeeCount = 0;

void clearInputBuffer(void);
int readMenuChoice(void);
float readAmount(const char prompt[],int allowZero);
void readEmployeeID(char id[]);
void readEmployeeName(char name[]);
void chooseDepartment(char dept[]);
int findEmployeeByID(const char id[]);
void buildLabel(int index, char label[]);
void displaySalaryInfo(int index);
   
   void clearInputBuffer(void)



{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
{

    
}

}

int readMenuChoice(void)
{
    int choice;
    if (scanf("%d", &choice) != 1)
    {
        clearInputBuffer();
        return -1;
    }
    clearInputBuffer();
    return choice;  
}
    float readAmount(const char prompt[], int allowZero)
    {
        float value = 0;
        int valid;


        do
        {
            valid = 1;
            printf("%s", prompt);
        
        if (scanf("%f", &value) !=1)
        {
            printf(" Invalid input. Please enter a number .\n");
            valid = 0;
        }

        else if (value < 0)
        {
            printf(" Amount cannot be negative. \n");
            valid = 0;
        }
        else if (value == 0 && allowZero == 0)
        {
            printf(" Amount must be greater than zero. \n");
            valid = 0;  
        }
        clearInputBuffer();


    } while (!valid);

    return value;
}
  void readEmployeeID(char id[])
{
    char temp[ID_LEN];
    int valid;
    do
    {
        valid = 1;
        printf("Enter Employee ID (e.g. E001): ");
        if (scanf("%19s", temp) != 1 || strlen(temp) == 0)
        {
            printf(" Employee ID cannot be empty.\n");
            valid = 0;
        }
        clearInputBuffer();
    } while (!valid);
    strcpy(id, temp);
}
 void readEmployeeName(char name[])
 {
    char temp [NAME_LEN];
    int valid;

    do
{
    valid = 1;
    printf("Enter Employee Name (no spaces,e.g. John_Doe): ");
    if (scanf("%49s", temp) != 1 || strlen(temp) == 0)
    {
        printf(" Employee Name cannot be empty.\n");
        valid = 0;
    }
    clearInputBuffer();
} while (!valid);

    strcpy(name, temp);

 }
 void chooseDepartment(char dept[])
 {
    int choice;

    do
    {
    printf("\n Select Department :\n");
    printf(" 1. finance\n"); 
    printf(" 2. human Resources\n");
    printf(" 3. engineering\n");
    printf(" 4. Health\n");
    printf(" 5. Transportation\n");
    printf(" Enter your choice (1-5): ");
    choice = readMenuChoice();


    switch (choice)
    
    {
        case 1:strcpy(dept, "Finance");break;
        case 2:strcpy(dept, "Human Resources");break;
        case 3:strcpy(dept, "Engineering");break;
        case 4:strcpy(dept, "Health");break;
        case 5:strcpy(dept, "Transportation");break;
        default:
            printf(" Invalid choice. Please select a valid department.\n");
            choice = 0;
          }
      } while (choice < 1 || choice > 5);

  } 
  int findEmployeeByID(const char id[])
  {
    
    for (int i = 0; i < employeeCount; i++)
    {
        if (strcmp(empID[i], id) == 0)
        {
            return i; 
        }
    }
    return -1; 
  }
    void buildLabel(int index, char label[])
    {
        strcpy(label, empName[index]);
        strcat(label, " [- ");
        strcat(label, empDept[index]);
        strcat(label, "]");
    }

    void displaySalaryInfo(int index)
    {
        char Label[LABEL_LEN];

        buildLabel(index, Label);

        if (empNetSalary[index] >= 20000)
        {
            printf(" income Catergory      : High Income\n");
          
            
        }
        else
        {
            printf(" income Catergory      : Standard Income\n");
        }
            printf("-------------------------------\n");
    }
    float calculateGrossSalary(float basic, float housing, float transport)
    {
        return basic + housing + transport;
    }
    float calculateTax(float gross)
    {
        float rate;

        if (gross <= 5000)
        {
            rate = 0.00f; 
        }
        else if (gross <= 10000)
        {
            rate = 0.10f; 
        }
        else if (gross <= 20000)
        {
            rate = 0.18f; 
        } 
        else
        {
            rate = 0.25f; 
        }
        

        return gross * rate;

    }
    float calculateNetSalary(float gross, float tax)
    {
        return gross - tax;
    }
      void addEmployee(void)
      {
        int i;

        if (employeeCount >= MAX_EMPLOYEES)
        {
            printf("\n Employee Maximum employee limit reached (%d). Cannot add more employees.\n", MAX_EMPLOYEES);
            return;
        }
        i = employeeCount;


        printf("\n--- ADD EMPLOYEE ---\n");
        readEmployeeID(empID[i]);
        readEmployeeName(empName[i]);
        chooseDepartment(empDept[i]);
        
        empBasicSalary[i] = readAmount("Enter Basic Salary: ", 0);
        empHousingAllowance[i] = readAmount("Enter Housing Allowance: ", 1);
        empTransportAllowance[i] = readAmount("Enter Transportation Allowance: ", 2);


        empGross[i] = calculateGrossSalary(empBasicSalary[i], empHousingAllowance[i], empTransportAllowance[i]);
        empTax[i] = calculateTax(empGross[i]);
        empNetSalary[i] = calculateNetSalary(empGross[i], empTax[i]);
        employeeCount++;


     printf("\n Employee added successfully!\n");
     displaySalaryInfo(i);
    }

     void displayEmployees(void)
{
    if (employeeCount == 0)
    {
        printf("\n No employees to display.\n");
        return;
    }

    printf("\n--- EMPLOYEE LIST ---\n");
    printf("%-10s %-20s %-20s %-10s %-10s %-10s %-10s %-10s\n", "ID", "Name", "Department", "Basic", "Housing", "Transport", "Gross", "Net");
    printf("---------------------------------------------------------------------------------------------\n");
    for (int i = 0; i<employeeCount;i++)

    {
        printf("%-10s %-20s %-20s %-10.2f %-10.2f %-10.2f %-10.2f %-10.2f\n",
            empID[i], empName[i], empDept[i],
            empBasicSalary[i], empHousingAllowance[i], empTransportAllowance[i],
            empGross[i], empNetSalary[i]);
    }
    printf("---------------------------------------------------------------------------------------------\n");


    printf("Total Employees: %d\n", employeeCount);

}
    void searchEmployee(void)
    {
        int choice;
        int found = 0;
        char key[NAME_LEN];
if (employeeCount == 0)
        {
            printf("\n No employees to search.\n");
            return;
        }

        printf("\n--- SEARCH EMPLOYEE ---\n");
        printf("1. Search by ID\n");
        printf("2. Search by Name\n");
        printf("3. Search by Department\n");
        printf("Enter choice: ");
        choice = readMenuChoice();


        if (choice <1 || choice > 3)
        {
            printf("Invalid search option. \n");
            return;
        }
        printf("Enter search text: ");
        if (scanf("%49s", key) != 1 || strlen(key) == 0)
        {
            clearInputBuffer();
            printf("Search text cannot be empty.\n");
            return;

        }
        clearInputBuffer();
        for (int i = 0; i<employeeCount;i++)
        {
            int match = 0;
            switch (choice)
            {
                case 1: match = (strcmp(empID[i], key) == 0); break;
                case 2: match = (strcmp(empName[i], key) == 0); break;
                case 3: match = (strcmp(empDept[i], key) == 0); break;
            }

            if (match)
            {
                found = 1;
                displaySalaryInfo(i);
            }
        }
        if (!found)
        {
            printf("No matching employee found.\n");
            if (choice == 3)
            {
                printf("Department search exist\n");
            }
        }
    }
     void calculateSalary(void)
     {
        char id[ID_LEN];
        int index;


        if (employeeCount == 0)
        {
            printf("\n No employees available. Add an employee first.\n");
            return;
        }
        printf("\n --- Calculate Salary ---\n");

        printf("\n Enter Employee ID: ");
         if (scanf("%19s", id) != 1 || strlen(id) == 0)
         {
            clearInputBuffer();
            printf("Employee ID cannot be empty.\n");
            return;
         }
         clearInputBuffer();
         index = findEmployeeByID(id);

         if (index == -1)
         {
            printf("Employee with ID %s was not found. \n", id);

         }
         else
         {
            empGross[index] = calculateGrossSalary(empBasicSalary[index], empHousingAllowance[index],empTransportAllowance[index]);
            empTax[index] = calculateTax(empGross[index]);
            empNetSalary[index] = calculateNetSalary(empGross[index], empTax[index]);
            displaySalaryInfo(index);
            }
          }
            void employeeMenu(void)
            {
                int choice;

                do
                {
                    printf("\n ------------------------------\n");
                    printf(" EMPLOYEE MANAGEMENT\n");
                    printf("------------------------\n");
                    printf("1. Add Employee\n");
                    printf("2. Display Employee\n");
                    printf("3. Search Employee\n");
                    printf("4. calculate Salary\n");
                    printf("5. Back to Main menu\n");
                    printf("Enter your choice: ") ;


                    choice = readMenuChoice();

                switch (choice)
               {
         case 1: addEmployee();   
         break;
         case 2: displayEmployees();  
         break;
         case 3: searchEmployee(); 
         break;
         case 4: calculateSalary(); 
         break;
         case 5: printf("\n Returning to main menu...\n");  
         break;
         default:
         printf("\n Invalid choice. Please enter a number from 1 to 5.\n");
               }
            } while (choice != 5);
        }
        int getEmployeeCount(void)
        {
            return employeeCount;
        }
            float calculateTotalSalary(void)
            {
                float total = 0;
                for (int i = 0; i < employeeCount; i++)
                {
                    total = total + empGross[i];
                }
                return total;
            }
            float calculateAverageSalary(void)
            {
                if (employeeCount == 0)
                {
                    return 0;
                }
                   return calculateTotalSalary() / employeeCount;

            }
            float findHighestSalary(void)
            {
                float highest;
                if (addEmployee == 0)
                {
                    return 0;
                }

                highest = empGross[0];
                for (int i = 1; i < employeeCount; i++)
                {
                    if (empGross[i] > highest)
                    {
                        highest = empGross[i];
                    }
                }
                return highest;
            }
            float findLowestSalary(void)
            {
                float lowest;
                if (employeeCount == 0)
                {
                    return 0;
                }
                lowest = empGross[0];
                for (int i =1; i < employeeCount; i++)
                {
                    if (empGross[i] < lowest)
                    {
                        lowest = empGross[i];
                    }
                }
                return lowest;
            }
            int main(void)
            {
                employeeMenu();
                return 0;
            }

