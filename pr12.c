#include <stdio.h>

struct Employee
{
    int id;
    char name[20];
    float salary;
};

static void clear_input_buffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}

int main(void)
{
    struct Employee emp;
    struct Employee temp;
    int choice;

    do
    {
        printf("EMPLOYEE MANAGEMENT\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();

        if (choice == 1)
        {
            FILE *file = fopen("employee.dat", "ab");

            if (file == NULL)
            {
                printf("File could not be opened.\n");
            }
            else
            {
                printf("Enter Employee ID: ");
                scanf("%d", &emp.id);
                clear_input_buffer();

                printf("Enter Employee Name: ");
                scanf("%19[^\n]", emp.name);
                clear_input_buffer();

                printf("Enter Employee Salary: ");
                scanf("%f", &emp.salary);
                clear_input_buffer();

                fwrite(&emp, sizeof(emp), 1, file);
                fclose(file);
                printf("Employee data saved successfully!\n");
            }
        }
        else if (choice == 2)
        {
            FILE *file = fopen("employee.dat", "rb");

            if (file == NULL)
            {
                printf("No employee data found.\n");
            }
            else
            {
                printf("EMPLOYEE DETAILS\n");

                while (fread(&temp, sizeof(temp), 1, file) == 1)
                {
                    printf("Employee ID: %d\n", temp.id);
                    printf("Name: %s\n", temp.name);
                    printf("Salary: %.2f\n", temp.salary);
                }

                fclose(file);
            }
        }
        else if (choice == 3)
        {
            printf("\nProgram ended.\n");
        }
        else
        {
            printf("\nWrong choice!\n");
        }
    } while (choice != 3);

    return 0;
}