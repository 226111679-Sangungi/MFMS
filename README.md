# MFMS
# Municipal Financial Management System
Course: PAP521S - Programming in Practice (Project A)  
Group Number: 23

1. Project Description 
MFMS is a modular, menu-driven C program built for municipal record-keeping. It allows administrators to track and manage employee payroll, departmental budgets, vendor information, and physical municipal assets through an integrated command-line interface.

2. Group Members & Responsibilities

Student 1 (Hakko): Employee Management (employees.c / employees.h)
Student 2 (Kadhikwa): Budget Management (budget.c / budget.h)
Student 3 (Shinedima): Supplier Management (suppliers.c / suppliers.h)
Student 4 (Kakelo): Asset Management (assets.c / assets.h)
Student 5 (Mbahuurua): Reports (reports.c / reports.h)
Student 6 (!Gaoseb): Functions, Integration & Validation (main.c)
Student 7 (Sangungi): Testing, Documentation & Git Coordination (tests.c / tests.h)

4. System Features
* Employee Management: Add, search, display, and calculate salary details
* Budget Management:Track departmental budgets, record expenditure, calculate remaining funds, and flag over-budget departments.
* Supplier Management:Store and search supplier contact details, email addresses, and locations.
* Asset Management:Register municipal assets, track purchase values, and inspect asset conditions.
* Reports:Generate summary metrics for salaries, budgets, asset values, and supplier records.
* Automated Tests:Built-in test suite (`test.c`/`test.h`) to verify module functionality.

4. Compilation Instructions

Ensure you have GCC and Visual Studio Code (or terminal) configured.

To compile all system modules together into a single executable, run:

(In bash)
gcc main.c employees.c budget.c suppliers.c assets.c reports.c tests.c -o mfms
