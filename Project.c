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

//function for print the Employees details
void print(struct employee *ptr)
{
    int i=1;
    while(ptr !=NULL)
    {
        printf("Employee:%d\n",i);
        printf("Id:%d || ",ptr->id);
        printf("Name:%s || ",ptr->name);
        printf("Department:%s || ",ptr->department);
        printf("Designation:%s || ",ptr->post);
        printf("Salary:%f || ",ptr->salary);
        printf("Contact Info:%s || ",ptr->contactinfo);
        i++;
        printf("\n");
        ptr=ptr->next;
    }
}
//add new employee
//if use char type use a pointer ,not for the int
struct employee *last(struct employee *head, int id, char *name, char *department, char *post, float salary, char *contactinfo)
{
    struct employee *ptr = (struct employee*)malloc(sizeof(struct employee));
    ptr->id = id;
    strcpy(ptr->name, name);
    strcpy(ptr->department, department);
    strcpy(ptr->post, post);
    ptr->salary = salary;
    strcpy(ptr->contactinfo, contactinfo);
    struct employee *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
//delete from the first
struct employee *dltfirst(struct employee *head)
{
    struct employee *t=head;
    head=head->next;
    free(t);
    t=NULL;
    return head;
}
//remove from the last
struct employee *dltlast(struct employee *head)
{
    struct employee *t=head;
    struct employee *r=head->next;
    while(r->next != NULL)
    {
        t=t->next;
        r=r->next;
    }
    t->next=NULL;
    free(r);
    return head;
    
}

//remove from middle
struct employee *dltmid(struct employee *head,int index)
{
    struct employee *t=head;
    struct employee *t2;
    //use >2 for set the t before the deletation node and dlt the index node
    //use >1 for set the t in the index and dlt the after node
    while(index >2)
    {
        t=t->next;
        index--;
        
    }
    t2=t->next;
    if(t2->next==NULL)
        {
            head=dltlast(head);
            return head;
        }  
    t->next=t2->next;
    free(t2);
    return head;
}
//function for search employee
void search(struct employee *ptr,char *idname)
{   int i=1;
    while(ptr->next !=NULL)
    {
        //char type kisu function e pass korle pointer use korte hbe
        //use atoi function that is compare with int in srting for pointer
        if(strcmp(ptr->name, idname)==0 || ptr->id == atoi(idname ))
        {
            printf("\nEmployee:%d\n",i);
            printf("Id:%d || ",ptr->id);
            printf("Name:%s || ",ptr->name);
            printf("Department:%s || ",ptr->department);
            printf("Designation:%s || ",ptr->post);
            printf("Salary:%f || ",ptr->salary);
            printf("Contact Info:%s || ",ptr->contactinfo); 
            return ; 
        }
        else
        {
            ptr=ptr->next;
        }
        i++;
    }
    printf("Inter the right id or name\n");
    
}


int main()
{
    struct employee *head=(struct employee*)malloc(sizeof(struct employee));
    struct employee *second=(struct employee*)malloc(sizeof(struct employee));
    struct employee *third=(struct employee*)malloc(sizeof(struct employee));
    struct employee *fourth=(struct employee*)malloc(sizeof(struct employee));

    head->id = 232;
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

     int choice,number;
     int button;
     int id;
     char idname[100];
     char name1[50];
     char department1[50];
     char post1[50];
     float salary;
     char contactinfo1[50];
    do {
        displaymenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEmployee List:\n");
                print(head);
                printf("\n");
                printf("1. Main menu\n");
                printf("2. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &button);
                if(button==2){
                    return 0;
                }
                else
                {
                    continue;
                }
                break;
            case 2:
                // Add employee
                printf("Enter ID: ");
                scanf("%d",&id);
                printf("Enter Name: ");
                scanf("%s",name1);
                printf("Enter Department: ");
                scanf("%s", department1);
                printf("Enter Designation: ");
                scanf("%s",post1);
                printf("Enter Salatry: ");
                scanf("%f",&salary);
                printf("Enter Contact Info: ");
                scanf("%s",contactinfo1);
                head=last(head,id,name1,department1,post1,salary,contactinfo1);
                printf(" Employee added succesfull\n");
                break;
            case 3:
                //remove employee
                print(head);
                printf("Which number do you want to remove:");
                scanf("%d",&number); 
                if (number==1)
                {
                    head=dltfirst(head);
                }
                else
                {
                    head=dltmid(head,number);
                }
                printf("Employee-%d removed succesfull\n",number);
                printf("1. Main menu\n");
                printf("2. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &button);
                if(button==2){
                    return 0;
                }
                else
                {
                    continue;
                }
                break;
            case 4:
                //search employee
                printf("Enter id or name: ");
                scanf("%s", idname);
                search(head, idname);
                printf("\n\n1. Main menu\n");
                printf("2. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &button);
                if(button==2){
                    return 0;
                }
                else
                {
                    continue;
                } 
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");

        }
    }while(choice !=6);


    return 0;
}