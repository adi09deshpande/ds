#include <stdio.h>

struct Student
{
    int roll;
    int div;
    float percent;
    char name[20];
    char address[50];
};

void print_array(struct Student students[50], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n\nStudent %d: ", i + 1);
        printf("\nRoll No:  %d", students[i].roll);
        printf(" Name:  %s", students[i].name);
        printf(" Address: %s", students[i].address);
        printf(" Division: %d", students[i].div);
        printf(" Percent: %f", students[i].percent);
    }
}
void bubble_sort(struct Student students[50], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (students[j].roll > students[j + 1].roll) // if(strcmp(students[j].name,students[j + 1].name)>0) for string , < for descending order  
            {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
                flag = 1;
            }
            //print after each iteration
            // printf("\nIteration %d",i+1);
            // print_array(students, n);
        }
        //print after each pass
        // printf("\nIteration %d",i+1);
        // print_array(students, n);
        if (flag == 0)
        {
            break;
        }
    }
}

void selection_sort(struct Student students[50],int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min=i;
        for (int j= i + 1; j < n; j++)
        {
            if (students[j].roll<students[min].roll) // if (strcmp(students[j].name,students[min].name)<0) for string , > for descending order
            {
                min=j;
            }
        }
        if (min!=i)
        {
            struct Student temp = students[i];
            students[i] = students[min];
            students[min] = temp;
        }
        // print after each pass
        // printf("\nIteration %d",i+1);
        // print_array(students, n);
    }
}

void insertion_sort(struct Student students[50],int n)
{
    for (int i = 1; i < n; i++)
    {
        struct Student key = students[i];
        int j=i-1;
        while(j>=0 && students[j].roll>key.roll)  //  while(j>=0 && strcmp(students[j].name,key.name) >0) for string, < for descending order
        {
            students[j+1]=students[j];
            j--;
        }
        students[j+1]=key;
        // print after each pass
        // printf("\nIteration %d",i);
        // print_array(students, n);
    }
}

int main()
{
    struct Student students[50];
    int n, ch;
    do
    {
        printf("\n\nEnter the operation to be perfomed :-\n1.Bubble sort\n2.Selection sort\n3.Insertion Sort\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        if (ch == 4)
        {
            return 0;
        }
        printf("\nEnter number of students: ");
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            printf("\nEnter details for student %d: ", i + 1);
            printf("\nRoll Number: ");
            scanf("%d", &students[i].roll);
            printf("Name: ");
            scanf("%s", students[i].name);
            printf("Address: ");
            scanf("%s", students[i].address);
            printf("Division: ");
            scanf("%d", &students[i].div);
            printf("Percent: ");
            scanf("%f", &students[i].percent);
        }

        printf("\nData Before sorting: ");
        print_array(students, n);
        printf("\n\nData after sorting: ");
        switch (ch)
        {
        case 1:
            bubble_sort(students, n);
            print_array(students, n);
            break;
        case 2:
            selection_sort(students, n);
            print_array(students, n);
            break;
        case 3:
           insertion_sort(students, n);
           print_array(students, n);
            break;
        case 4:
            return 0;
        default:
            printf("Enter a valid choice");
            break;
        }
    } while (ch != 4);

    return 0;
}