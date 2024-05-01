#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee{
    int id;
    char name[50];
    char department[50];
    char post[50];
    float salary;
    char contactinfo[50];
    struct employee *next;
};

//function for display menu
void displaymenu() {
    printf("\nEmployee Management System Menu:\n");
    printf("1. Display All Employees\n");
    printf("2. Add Employee\n");
    printf("3. Remove an employee\n");
    printf("4. Search an employee\n");
    printf("5. Edit employee details\n");
    printf("6. Exit\n");
}

//function for print the value
void print(struct employee *ptr)
{
    int i=1;
    while(ptr !=NULL)
    {
        printf("Employee:%d\n",i);
        printf("Id:%d ",ptr->id);
        printf("Name:%s ",ptr->name);
        printf("Department:%s ",ptr->department);
        printf("Designation:%s ",ptr->post);
        printf("Salary:%f ",ptr->salary);
        printf("Contact Info:%s ",ptr->contactinfo);
        i++;
        printf("\n");
        ptr=ptr->next;
    }
}

int main()
{
    struct employee *head=(struct employee*)malloc(sizeof(struct employee));
    struct employee *second=(struct employee*)malloc(sizeof(struct employee));
    struct employee *third=(struct employee*)malloc(sizeof(struct employee));
    struct employee *fourth=(struct employee*)malloc(sizeof(struct employee));

    head->id = 23215882;
    strcpy(head->name, "Asir Hamim");
    strcpy(head->department, "CSE");
    strcpy(head->post, "Lecturer");
    head->salary = 18000;
    strcpy(head->contactinfo, "01521704220");
    head->next = second;

    second->id = 23215882;
    strcpy(second->name, "Reyad");
    strcpy(second->department, "CSE");
    strcpy(second->post, "Lecturer");
    second->salary = 18000;
    strcpy(second->contactinfo, "01521704220");
    second->next = third;

    third->id = 23215882;
    strcpy(third->name, "Esha");
    strcpy(third->department, "CSE");
    strcpy(third->post, "Lecturer");
    third->salary = 18000;
    strcpy(third->contactinfo, "01521704220");
    third->next = fourth;

    fourth->id = 23215882;
    strcpy(fourth->name, "Tanvir");
    strcpy(fourth->department, "CSE");
    strcpy(fourth->post, "Lecturer");
    fourth->salary = 18000;
    strcpy(fourth->contactinfo, "01521704220");
    fourth->next = NULL;

     int choice;
     int button;
    do {
        displaymenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEmployee List:\n");
                print(head);
                printf("1. Main menu\n");
                printf("2. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &button);
                if(button=2){
                    return 0;
                }
                else
                {
                    break;
                }
            case 2:
                // Exit
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");

        }
    }while(choice !=6);


    return 0;
}