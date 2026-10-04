#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "validation.h"

#define MaxSuppliers 50
#define NameLen 100
#define EmailLen 100
#define PhoneLen 30
#define TownLen 50

static int supplierIDs[MaxSuppliers];
static char supplierNames [MaxSuppliers][NameLen];
static char supplierEmails [MaxSuppliers][EmailLen];
static char supplierPhones [MaxSuppliers][PhoneLen];
static char supplierTowns [MaxSuppliers][TownLen];
static int supplierCount = 0;

static void addSupplier(void);
void displaySuppliers(void);
static void searchSupplier(void);
static void showNameLengths(void);
static void generateDescriptions(void);
static void clearInputBuffer(void);

void supplierManagementMenu(void)
{
    int choice;
    do
    {
        printf("\n1. Add Supplier\n2. Display Suppliers\n3. Search Supplier\n");
        printf("4. Show Name Lengths\n5. Generate Descriptions \n6. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice)
        {
            case 1: addSupplier();
            break;
            case 2: displaySuppliers();
            break;
            case 3: searchSupplier();
            break;
            case 4: showNameLengths();
            break;
            case 5: generateDescriptions();
            break;
            case 6: printf("\nRunning to main menu...\n");
            break;
            default : printf("\nInvalid choice.\n");

        }
    } while (choice != 6);
}
static void addSupplier(void)
{
    if (supplierCount >= MaxSuppliers)
    {
        printf("\nFull.\n");
        return;
    }

    char tempName[NameLen], tempEmail[EmailLen];
    char tempPhone[PhoneLen], tempTown[TownLen];
        
    printf("Enter supplier name: ");
    fgets(tempName, sizeof(tempName), stdin);
    tempName[strcspn(tempName, "\n")] ='\0';

    if (strlen(tempName) == 0)
    {
        printf("\nName cannot be empty.\n");
        return;
    }

    printf("Enter email: ");
    fgets(tempEmail, sizeof(tempEmail), stdin);
    tempEmail[strcspn(tempEmail, "\n")] ='\0';

    printf("Enther phone: ");
    fgets(tempPhone, sizeof(tempPhone), stdin);
    tempPhone[strcspn(tempPhone, "\n")] = '\0';

    printf("Enter town: ");
    fgets(tempTown, sizeof(tempTown), stdin);
    tempTown[strcspn(tempTown, "\n")] ='\0';

    supplierIDs[supplierCount] = supplierCount + 1;
    strcpy(supplierNames[supplierCount], tempName);
    strcpy(supplierEmails[supplierCount], tempEmail);
    strcpy(supplierPhones[supplierCount], tempPhone);
    strcpy(supplierTowns[supplierCount], tempTown);
    supplierCount++;

    printf("\nAdd supplier ID: %d\n", supplierIDs[supplierCount - 1]);
    
}
void displaySuppliers(void) {

    if (supplierCount == 0) 
    { 
        printf("\nNo suppliers yet.\n");
        return;
    }
    for (int i =0; i < supplierCount; i++)
    {
        printf("\nID: %d | Name: %s | Email: %s | Phone: %s | Town: %s\n", supplierIDs[i], supplierNames[i], supplierEmails[i], supplierPhones[i], supplierTowns[i]);
    }
}

static void searchSupplier(void)
{
    if (supplierCount == 0)
    {
        printf("\nNo supplier yet.\n");
        return;
    }
    char searchName[NameLen];
    int found = 0;

    printf("Enter name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(supplierNames[i], searchName) == 0)
        {
            found = 1;
            printf("\nFound: ID %d, %s, %s\n", supplierIDs[i], supplierEmails[i], supplierTowns[i]);
            break;
        }

    }
    if (!found) printf("\nNot found.\n");
}

static void showNameLengths(void)
{
    for (int i = 0; i < supplierCount; i++)
        printf("%s -> %zu characters\n", supplierNames[i], strlen(supplierNames[i]));
}

static void generateDescriptions(void)
{
    for (int i = 0; i < supplierCount; i++)
    {
        char description[250] = "";
        strcat(description, supplierNames[i]);
        strcat(description, " operates in ");
        strcat(description, supplierTowns[i]);
        strcat(description, ".");
        printf("%s\n", description);
    }
}

static void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
