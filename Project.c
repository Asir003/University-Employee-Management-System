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
    printf("6. Display Employees by Department\n");
    printf("7. Exit\n");
}

//void display menu for edit
void displayedit()
{
    printf("\n1. Edit Id\n");
    printf("2. Edit Name\n");
    printf("3. Edit Department\n");
    printf("4. Edit Designation\n");
    printf("5. Edit Salary\n");
    printf("6. Edit Contact Info\n");

}


//function for print the Employees details
void print(struct employee *ptr)
{
    int i=1;
    while(ptr !=NULL)
    {
        printf("Employee-%d\n",i);
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
void search(struct employee *head,char *idname)
{    
      struct employee *ptr=head;
      int i=1;
      //for useing this the attempts will not be zero again
      static int attempts=0;
    while(ptr !=NULL)
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
    
    attempts++;
    if (attempts >=3)
    {
        printf("You've exceeded the maximum number of attempts.\n");
        return;
    }
    
    else
    {
    printf("Inter the right id or name: ");
    fgets(idname, sizeof(idname), stdin);
    size_t len = strlen(idname);
    if (len > 0 && idname[len - 1] == '\n') {
        idname[len - 1] = '\0';
    }
    search(head, idname); 
    } 
}
//function for edit number
int find(struct employee *ptr,char *idname)
{
      int i=1;
    while(ptr->next !=NULL)
    {
        //char type kisu function e pass korle pointer use korte hbe
        //use atoi function that is compare with int in srting for pointer
        if(strcmp(ptr->name, idname)==0 || ptr->id == atoi(idname ))
        {
            return i; 
        }
        else
        {
            ptr=ptr->next;
        }
        i++;
    }
}
// update employee details
struct employee *editemployee(struct employee *head,int index,char *newname,int no)
{
    struct employee *t=head;
    while(index >1)
    {
        t=t->next;
        index--;
    }
    if(no==1)
    {
        t->id=atoi(newname);
        return head;
    }
    else if(no==2)
    {
        strcpy(t->name,newname);
        return head;
    }
    else if(no==3)
    {
        strcpy(t->department,newname);
        return head;
    }
    else if(no==4)
    {
        strcpy(t->post,newname);
        return head;
    }
    else if(no==5)
    {
        t->salary=atoi(newname);
        return head;
    }
    else if(no==6)
    {
        strcpy(t->contactinfo,newname);
        return head;
    }
} 

//function for Display Employees by Department
void DepartmentDisplay(struct employee *head,char *DepartmentName)
{
      struct employee *ptr=head;
      int i=1;
      while(ptr !=NULL)
      {
        if(strcmp(ptr->department,DepartmentName)==0)
        {
            printf("Employee:%d\n",i);
            printf("Id:%d || ",ptr->id);
            printf("Name:%s || ",ptr->name);
            printf("Department:%s || ",ptr->department);
            printf("Designation:%s || ",ptr->post);
            printf("Salary:%f || ",ptr->salary);
            printf("Contact Info:%s || \n",ptr->contactinfo);          
        }
        ptr=ptr->next;
        i++;
      }
}

int main()
{
    int userId = 23215882;
    char password[] = "asirhamim";
    int UserId;
    char Password[50];

    printf("\t\t\t\t\t\t\tAdmin Login\n");
    printf("\t\t\t\t\t\t   User Id: ");
    scanf("%d", &UserId);
    printf("\t\t\t\t\t    Enter Password: ");
    scanf("%s", Password);

    int attempts = 1;
    while (userId != UserId || strcmp(password, Password) != 0) 
    {
        printf("Invalid User Id or Password\n");
        printf("User Id: \n");
        scanf("%d", &UserId);
        printf("Enter Password: \n");
        scanf("%s", Password);
        attempts++;
        if (attempts == 3) 
        {
            printf("Too many unsuccessful attempts. Try again later.\n");
            return 0;
        }
    }

    printf("Login successful!\n");
    
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
    strcpy(second->department, "SEW");
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
    strcpy(fourth->department, "Agri");
    strcpy(fourth->post, "Lecturer");
    fourth->salary = 18000;
    strcpy(fourth->contactinfo, "01521704220");
    fourth->next = NULL;

     int choice,number,edit,found,totalEmployee;
     int button;
     int id;
     char idname[50];
     char name1[50];
     char department1[50];
     char post1[50];
     float salary;
     char contactinfo1[50];
     char nid[100];
     int c;
     char DepartmentName[50];
     int total;
    do {
        displaymenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\t\t\t\t\t\t\tEmployee List:\n");
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
                while ((c = getchar()) != '\n' && c != EOF);
                        printf("Enter Name: ");
                        fgets(name1, sizeof(name1), stdin);
                        size_t len3 = strlen(name1);
                        if (len3 > 0 && name1[len3 - 1] == '\n') {
                            name1[len3 - 1] = '\0';
                        }
                        printf("Enter Department: ");
                        fgets(department1, sizeof(department1), stdin);
                        size_t len4 = strlen(department1);
                        if (len4 > 0 && department1[len4 - 1] == '\n') {
                            department1[len4 - 1] = '\0';
                        }
                        printf("Enter Designation: ");
                        fgets(post1, sizeof(post1), stdin);
                        size_t len5 = strlen(post1);
                        if (len5 > 0 && post1[len5 - 1] == '\n') {
                            post1[len5 - 1] = '\0';
                        }
                printf("Enter Salary: ");
                scanf("%f",&salary);
                printf("Enter Contact Info: ");
                scanf("%s",contactinfo1);
                head=last(head,id,name1,department1,post1,salary,contactinfo1);
                printf(" Employee added successfully\n");
                // short menu bar
                printf("\n");
                printf("1. View All Employees\n");
                printf("2. Main Menu\n");
                printf("3. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &button);
                if(button==3){
                    return 0;
                }
                else if(button==1)
                {
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
                }
                else
                {
                    continue;
                }
                break;
            case 3:
                //remove employee
                printf("\n");
                print(head);
                printf("\n* Which number do you want to remove: ");
                scanf("%d",&number); 
                if (number==1)
                {
                    head=dltfirst(head);
                }
                else
                {
                    head=dltmid(head,number);
                }
                printf("\t!...Employee-%d removed succesfully...!\n",number);
                printf("\n1. Main menu\n");
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
                while ((c = getchar()) != '\n' && c != EOF);
                        printf("Enter id or name: ");
                        fgets(idname, sizeof(idname), stdin);
                        size_t len6 = strlen(idname);
                        if (len6 > 0 && idname[len6 - 1] == '\n') {
                            idname[len6 - 1] = '\0';
                        }         
                search(head, idname);
                //menu bar
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
            case 5:
                //Edit employee details
                printf("Enter id of the employee: ");
                scanf("%s", idname);              
                search(head, idname);
                displayedit();
                found=find(head,idname);
                printf("Which details do you want to edit: ");
                scanf("%d",&edit);
                switch(edit)
                {
                    case 1:
                        printf("Enter new Id: ");
                        scanf("%s",nid); 
                        head=editemployee(head,found,nid,edit);
                        break;
                    case 2:
                        while ((c = getchar()) != '\n' && c != EOF);
                        printf("Enter new Name: ");
                        fgets(nid, sizeof(nid), stdin);
                        // Remove the trailing newline character, if present
                        size_t len = strlen(nid);
                        if (len > 0 && nid[len - 1] == '\n') {
                            nid[len - 1] = '\0';
                        }
                        head = editemployee(head, found, nid, edit);
                        break;
                    case 3: 
                        while ((c = getchar()) != '\n' && c != EOF);
                        printf("Enter new Department: ");
                        fgets(nid, sizeof(nid), stdin);
                        // Remove the trailing newline character, if present
                        size_t len1 = strlen(nid);
                        if (len1 > 0 && nid[len1 - 1] == '\n') {
                            nid[len1 - 1] = '\0';
                        }
                        head = editemployee(head, found, nid, edit);
                        break;
                    case 4: 
                        while ((c = getchar()) != '\n' && c != EOF);
                        printf("Enter new Designation: ");
                        fgets(nid, sizeof(nid), stdin);
                        // Remove the trailing newline character, if present
                        size_t len2 = strlen(nid);
                        if (len2 > 0 && nid[len2 - 1] == '\n') {
                            nid[len2 - 1] = '\0';
                        }
                        head = editemployee(head, found, nid, edit);
                        break;  
                    case 5: 
                        printf("Enter new Salary: ");
                        scanf("%s",nid); 
                        head=editemployee(head,found,nid,edit);
                        break;  
                    case 6: 
                        printf("Enter new Contact Info: ");
                        scanf("%s",nid); 
                        head=editemployee(head,found,nid,edit);
                        break;
                    default:
                        printf("Invalid choice. Please enter a valid option.\n");      
                }
                printf(" Edited successfully\n");
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
            case 6:
                //Display Employees by Department
                while ((c = getchar()) != '\n' && c != EOF);
                    printf("Enter Department Name: ");
                    fgets(DepartmentName, sizeof(DepartmentName), stdin);
                    size_t len8 = strlen(DepartmentName);
                    if (len8 > 0 && DepartmentName[len8 - 1] == '\n') {
                        DepartmentName[len8 - 1] = '\0';
                    }  
                printf("\n"); 
                printf("Department: ");
                puts(DepartmentName); 
                DepartmentDisplay(head,DepartmentName) ;
                printf("\n1. Main menu\n");
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

            case 7:
                printf("Exit Successfully.........\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;

        }
    }while(choice !=7);


    return 0;
}