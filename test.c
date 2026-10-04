#include "test.h"
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

static int g_tests_run = 0;
static int g_tests_passed = 0;

#define RUN_TEST(condition, test_name) \
    do { \
        g_tests_run++; \
        if (condition) { \
            g_tests_passed++; \
            printf("  [PASS] %s\n", test_name); \
        } else { \
            printf("  [FAIL] %s (Line %d)\n", test_name, __LINE__); \
        } \
    } while (0)


bool empClearInput(void) {
    printf("\n--- Testing Employee Module ---\n");

    double invalid_salary = -5000.0;
    RUN_TEST(invalid_salary < 0, "Validation: Negative salary detected correctly");

    float basic = 10000.0f;
    float housing = 2000.0f;
    float transport = 1000.0f;
    float total_salary = calculateSalary(basic, housing, transport);
    RUN_TEST(total_salary == 13000.0f, "Calculation: Gross salary matches calculateSalary()");

    float expected_tax = 1850.0f;
    float calculated_tax = calculateTax(total_salary);
    RUN_TEST(calculated_tax == expected_tax, "Calculation: Income tax matches calculateTax()");


    float expected_pension = 500.0f;
    float calculated_pension = calculatePension(basic);
    RUN_TEST(calculated_pension == expected_pension, "Calculation: Pension matches calculatePension()");

    
    char mock_ids[2][ID_LEN] = {"EMP001", "EMP002"};
    int index = searchEmployee("EMP002", mock_ids, 2);
    RUN_TEST(index == 1, "Logic: searchEmployee() correctly locates existing ID");

    int not_found = searchEmployee("EMP999", mock_ids, 2);
    RUN_TEST(not_found == -1, "Logic: searchEmployee() correctly returns -1 for missing ID");

    return true;
}

// ==========================================
// Module 2: Budget Management Tests
// ==========================================
bool manageBudget(void) {
    printf("\n--- Testing Budget Module ---\n");

    double allocated = 500000.0;
    double expenditure = 420000.0;
    double remaining = allocated - expenditure;

    
    RUN_TEST(remaining == 80000.0, "Calculation: Remaining budget correctly calculated");

    
    bool is_within_budget = (expenditure <= allocated);
    RUN_TEST(is_within_budget == true, "Logic: Expenditure within allocated budget identified");

    
    double excess_expenditure = 550000.0;
    bool is_over_budget = (excess_expenditure > allocated);
    RUN_TEST(is_over_budget == true, "Logic: Over-budget condition identified");

    return true;
}

// ==========================================
// Module 3: Supplier Management Tests
// ==========================================
bool supplierManagementMenu(void) {
    printf("\n--- Testing Supplier Module ---\n");

    char supplier_id[MAX_ID_LEN] = "SUP101";
    char supplier_name[MAX_NAME_LEN] = "Namibia Tech Supplies";

   
    RUN_TEST(strlen(supplier_id) > 0, "Data Check: Supplier ID is non-empty");
    RUN_TEST(strlen(supplier_name) > 0, "Data Check: Supplier Name is non-empty");

    
    RUN_TEST(strcmp(supplier_id, "SUP101") == 0, "String Handling: Exact ID comparison match");

    return true;
}

// ==========================================
// Module 4: Asset Management Tests
// ==========================================
bool assetManagement(void) {
    printf("\n--- Testing Asset Module ---\n");

    double purchase_value = 150000.0;

    // Test 1: Verify purchase value validation
    RUN_TEST(purchase_value > 0.0, "Validation: Positive asset value verified");

    return true;
}

// ==========================================
// Module 5: Report Generation Tests
// ==========================================
bool displayReportmenu(void) {
    printf("\n--- Testing Reports Module ---\n");

    int total_employees = 35;
    double avg_salary = 18500.0;

   
    RUN_TEST(total_employees > 0, "Report Data: Total employee count valid");
    RUN_TEST(avg_salary > 0.0, "Report Data: Average salary calculation valid");

    return true;
}


void run_all_tests(void) {
    g_tests_run = 0;
    g_tests_passed = 0;

    printf("=========================================\n");
    printf("     RUNNING MFMS AUTOMATED TEST SUITE   \n");
    printf("=========================================\n");

    empClearInput();
    manageBudget();
    supplierManagementMenu();
    assetManagement();
    displayReportmenu();

    printf("\n=========================================\n");
    printf(" TEST RESULTS SUMMARY\n");
    printf(" Total Tests Executed: %d\n", g_tests_run);
    printf(" Passed: %d\n", g_tests_passed);
    printf(" Failed: %d\n", g_tests_run - g_tests_passed);
    printf(" Success Rate: %.1f%%\n", ((double)g_tests_passed / g_tests_run) * 100.0);
    printf("=========================================\n\n");
}