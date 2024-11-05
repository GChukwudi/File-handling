#include <stdio.h>
#include <stdlib.h>

#define EMAIL_LEN 100

/**
 * struct Employee - Employee structure
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

    file = fopen("employe.bin", "rb");

    if (file == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    fread(employee, sizeof(Employee), 5, file);
    fclose(file);

    for (i = 0; i < 5; i++)
    {
        printf("Email: %s, Age: %d, Salary: %.2f\n",
               employee[i].email, employee[i].age, employee[i].salary);
    }

    return (0);
}
