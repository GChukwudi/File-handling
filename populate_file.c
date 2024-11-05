#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMAIL_LEN 100

/**
 * struct Employee - Represents an employee
 * @email: The employee's email
 * @age: The employee's age
 * @salary: The employee's salary
 *
 * Return: 0
 */
typedef struct Employee
{
    char email[EMAIL_LEN];
    int age;
    float salary;
} Employee;

int main(void)
{
    FILE *file;
    Employee employee[5];
    int i;

    file = fopen("employe.bin", "wb");
    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    for (i = 0; i < 5; i++)
    {
        printf("Enter employee details %d:\n", i + 1);

        printf("Email: ");
        scanf("%s", employee[i].email);

        printf("Age: ");
        scanf("%d", &employee[i].age);

        printf("Salary: ");
        scanf("%f", &employee[i].salary);
    }

    fwrite(employee, sizeof(Employee), 5, file);

    fclose(file);

    return (0);
}
