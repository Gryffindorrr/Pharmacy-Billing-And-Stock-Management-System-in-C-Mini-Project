#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<time.h>
int count=0;

int password()
{
    char username[15];
    char password[12];
    printf("                                                 Enter Your Username:");
    scanf("%s",&username);
    printf("                                                 Enter Your Password:");
    scanf("%s",&password);
    if(strcmp(username,"Batch")==0)
    {
        if(strcmp(password,"XYZ")==0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

struct node
{
struct node *prev;
int id,barcode;
float price;
char name[20],type[20];
struct node *next;
}*last=NULL,*temp=NULL,*current=NULL,*head=NULL;


void Update_Stock(int n)
{
    int i,id,barcode;
    float price;
    char name[20],type[20];
    struct node *newNode;
    if(n >= 1)
    {
        head=(struct node *)malloc(sizeof(struct node));
        printf("                                       Enter the Medicine Details: Name,Id,Type,Barcode,Price\n                                       ");
        scanf("%s%d%s%d%f",head->name,&head->id,head->type,&head->barcode,&head->price);
        head->prev = NULL;
        head->next = NULL;
        last = head;
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("                                       Enter the Medicine Details: Name,Id,Type,Barcode,Price\n                                       ");
            scanf("%s%d%s%d%f",newNode->name,&newNode->id,newNode->type,&newNode->barcode,&newNode->price);
            newNode->prev = last;
            newNode->next = NULL;
            last->next = newNode;
            last = newNode;
        }
        printf("\n                                       Stock Updated Successfully.\n");
    }
}

void insertAtEnd()
{
    struct node * newNode;
    if(last == NULL)
    {
        printf("                                       Stock Is Empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("                                       Enter the Medicine Details: Name,Id,Type,Barcode,Price\n                                       ");
        scanf("%s%d%s%d%f",newNode->name,&newNode->id,newNode->type,&newNode->barcode,&newNode->price);
        newNode->next = NULL;
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
        printf("                                       Stock Added Successfully.\n");
    }
}

void display()
{
    struct node * temp;
    int n = 0;
    if(head == NULL)
    {
        printf("                                       Stock Is Empty.\n");
    }
    else
    {
        temp = head;
        printf("                                       Medicines in Stock are :\n");
        printf("\n                                       Name\tID\tType\tBarcode\t   Price\t\n");
        while(temp != NULL)
        {
            printf("\n                                       %s\t%d\t%s\t%d\t   %f\n",temp->name,temp->id,temp->type,temp->barcode,temp->price);
            n++;
            temp = temp->next;
        }
    }
    printf("\n                                        Total Stock Availability :%d",n);
}


void deleteFromBeginning()
{
    struct node *toDelete;
    if(head == NULL)
    {
        printf("                                       Stock Is empty.\n");
    }
    else
    {
        toDelete = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(toDelete);
    }
}


void deleteFromEnd()
{
    struct node * toDelete;
    if(last == NULL)
    {
        printf("                                       Stock Is Empty.\n");
    }
    else
    {
        toDelete = last;
        last = last->prev;
        if (last != NULL)
            last->next = NULL;
        free(toDelete);
    }
}


void DeleteAnyNode(int pos)
{
    struct node *current;
    int i;
    current = head;
    for(i=1; i<pos && current!=NULL; i++)
    {
        current = current->next;
    }
    if(pos == 1)
    {
        deleteFromBeginning();
    }
    else if(current == last)
    {
        deleteFromEnd();
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }
    else
    {
        printf("                                       Invalid position!\n");
    }
}



//Search Function With Return Value
int search(int barcode)
{
    int index;
    index = 0;
    current = head;
    while (current != NULL && current->barcode != barcode)
    {
        index++;
        current = current->next;
    }
    return (current != NULL) ? index : -1;
}



//Search Function Without Return Value
int search1(int barcode)
{
    int i=0,flag;
    temp = head;
    if(temp == NULL)
    {
        printf("\n                                        Stock Is Empty.\n");
    }
    else
    {
        while (temp!=NULL)
        {
            if(temp->barcode == barcode)
            {
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            temp = temp -> next;
        }
        if(flag==1)
        {
            printf("\n                                        Stock Not Found.\n");
        }
    }
}



//Medicine Search Using ID
void search_med(int id)
{
    int count=0;
    temp= head;
    if(temp == NULL)
    {
        printf("\n                                        Stock Is Empty.\n");
    }
    else
    {
        printf("\n                                       Name\tID\tType\tBarcode\t\n");
        while (temp!=NULL)
        {
            if(temp->id == id)
            {
                printf("                                       %s\t%d\t%s\t%d\n",temp->name,temp->id,temp->type,temp->barcode);
                count++;
            }
            temp=temp->next;
        }
    }
    printf("\n                                       Total Stock Available : %d\n",count);
}


//Customer_Information
int count1=0;
struct node1
{
struct node1 *prev1;
int id;
char name[20];
struct node1 *next1;
}*first1=NULL,*last1=NULL,*temp3=NULL,*temp4=NULL,*curNode1=NULL;



void create1()
{
int id;
char name[20];
temp3=(struct node1 *)malloc(sizeof(struct node1));
printf("                                       Enter the Customer Details: Name,Id\n                                       ");
scanf("%s%d",temp3->name,&temp3->id);
temp3->prev1=NULL;
temp3->next1=NULL;
count1++;
}



void Update_customer_id()
{
create1();
    if(first1==NULL)
    {
    first1=temp3;
    last1=first1;
    }
    else
    {
    last1->next1=temp3;
    temp3->prev1=last1;
    last1=temp3;
    }
}



//Customer ID Search
int search_cus_id(int id)
{
    int i=0,flag;
    temp3 = first1;
    if(temp3 == NULL)
    {
        printf("\n                                        Customer Information Empty.\n");
    }
    else
    {
        while (temp3!=NULL)
        {
            if(temp3->id == id)
            {
                printf("                                       Name\tId");
                printf("\n                                       %s\t%d\n",temp3->name,temp3->id);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            temp3 = temp3 -> next1;
        }
        if(flag==1)
        {
            printf("\n                                       Customer Id Not Found.\n");
        }
    }
    return flag;
}



//Customer ID Search Without Print Statement
void search_cus_id1(int id)
{
    int i=0,flag;
    temp3 = first1;
    if(temp3 == NULL)
    {
        printf("\n                                        Customer Information Empty.\n");
    }
    else
    {
        while (temp3!=NULL)
        {
            if(temp3->id == id)
            {
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            i++;
            temp3 = temp3 -> next1;
        }
        if(flag==1)
        {
            printf("\n                                       Customer Id Not Found.\n");
        }
    }
}


void Billing()
{
    FILE *fp,*fp1;
    time_t t;
    time(&t);
    int i,a,index,barcode,n,ch2,flag,id;
    float Total=0,Final_Total=0;
    printf("                                       Enter the Customer Id:");
    scanf("%d",&id);
    a=search_cus_id(id);
    if(a==0)
    {
        printf("\n                                       Enter the Number of Medicines : ");
        scanf("%d", &n);
        fp=fopen("D:\Bill.txt","w");
        fprintf(fp,"                                       **************************Bill**************************");
        fprintf(fp,"\n                                       Customer Name: %s\t\t\t\tID: %d\n",temp3->name,id);
        fprintf(fp,"\n                                       Name\tID\tType\tBarcode\t   Price\t\n");
        for(i=0; i<n; i++)
        {
            printf("                                       Enter Barcode Of  Medicine:");
            scanf("%d",&barcode);
            search1(barcode);
            fprintf(fp,"\n                                       %s\t%d\t%s\t%d\t   %f\n",temp->name,temp->id,temp->type,temp->barcode,temp->price);
            Customer(id);
            Total=Total+temp->price;
            index=search(barcode);
            DeleteAnyNode(index+1);
        }
        if(Total>=100)
        {
            Final_Total=Total-(Total*0.10);
            fprintf(fp,"                                       ---------------------------------------------------------");
            fprintf(fp,"\n                                       \t\t          Total Price :  Rs%f",Total);
            fprintf(fp,"\n                                       \t\t       Discount Price :  Rs%f",Total*0.10);
            fprintf(fp,"\n                                       \t\t          Final Price :  Rs%f",Final_Total);
        }
        else
        {
        fprintf(fp,"                                       ---------------------------------------------------------");
        fprintf(fp,"\n                                       \t\t          Total Price :  Rs%f",Total);
        }
        fprintf(fp,"\n\n                                       Date And Time: %s",ctime(&t));
        fprintf(fp,"\n                                       ***********************THANK YOU*************************");
        fclose(fp);
    }
    else
    {
        Update_customer_id();
        Billing();
    }
}


void Stock_Management()
{
    int index,i,n,barcode,ch2;
    printf("\n                                       1.Update Stock\n                                       2.Add Stock\n                                       3.Delete Stock\n                                       4.Back to Main Menu");
    while(3)
    {
        printf("\n                                       Enter Your Choice:");
        scanf("%d",&ch2);
        switch(ch2)
        {
            case 1:printf("                                       Enter Number of Medicines to be Entered:");
                   scanf("%d",&n);
                   Update_Stock(n);
                   break;
            case 2:printf("                                       Enter Number of Medicines to be Added:");
                   scanf("%d",&n);
                   for(i=0;i<n;i++)
                    insertAtEnd();
                   break;
            case 3:printf("                                       Enter Barcode:");
                   scanf("%d",&barcode);
                   index=search(barcode);
                   DeleteAnyNode(index+1);
                   break;
            case 4:admin();
                   break;
            default:printf("                                       Invalid Input.");
        }
    }
}



//Admin Function
void admin()
{
    int ch,i,n,pos,barcode,id,ch1,ch2;
    printf("\n\n   ************************************ Medicine Billing and stock Management System ***********************************\n");
    printf("\n                                       1.Stock Management");
    printf("\n                                       2.Display Stock Availability ");
    printf("\n                                       3.Search Medicine");
    printf("\n                                       4.Customer Info Management");
    printf("\n                                       5.Billing");
    printf("\n                                       6.Logout");
    while(1)
    {
        printf("\n                                       Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:Stock_Management();
                   break;
            case 2:display();
                   break;
            case 3:printf("                                       Enter Medicine ID:");
                   scanf("%d",&id);
                   search_med(id);
                   break;
            case 4: printf("\n                                       1.Update Customer Information");
                    printf("\n                                       2.Search Customer");
                    printf("\n                                       3.Customer Purchase Record");
                    printf("\n                                       4.Back to Main Menu");
                    while(2)
                    {
                        printf("\n                                       Enter your choice:");
                        scanf("%d",&ch1);
                        switch(ch1)
                        {
                            case 1:printf("                                       Enter Number of Customer Information to be Updated:");
                                   scanf("%d",&n);
                                   for(i=0;i<n;i++)
                                   Update_customer_id();
                                   break;
                            case 2:printf("                                       Enter Customer ID:");
                                   scanf("%d",&id);
                                   search_cus_id(id);
                                   break;
                            case 3:Customer_Purchase_Record();
                                   break;
                            case 4:admin();
                                   break;
                            default:printf("                                       Invalid Input.");
                        }
                    }
                   break;
            case 5:printf("\n                                       1.Billing\n                                       2.Print Bill\n                                       3.Back to Main Menu");
                     while(3)
                     {
                         printf("\n                                       Enter Your Choice:");
                         scanf("%d",&ch2);
                         switch(ch2)
                         {
                             case 1:Billing();
                                    break;
                             case 2:Print_Bill();
                                    break;
                             case 3:admin();
                                    break;
                             default:printf("                                       Invalid Input.");

                         }
                     }
                   break;
            case 6:main();
            default:printf("                                       Invalid Input.");
        }
    }
}



//Customer Function Used To Append
void Customer(int id)
{
    FILE *fp1;
    time_t t;
    time(&t);
    search_cus_id1(id);
    fp1=fopen("D:\Customer.txt","a");
    fprintf(fp1,"\n\n                                       Date And Time: %s\n",ctime(&t));
    fprintf(fp1,"                                       Customer Name: %s\t\t\t\tID: %d\n",temp3->name,id);
    fprintf(fp1,"\n                                       Name\tID\tType\tBarcode\t   Price\t\n");
    fprintf(fp1,"\n                                       %s\t%d\t%s\t%d\t   %f\n",temp->name,temp->id,temp->type,temp->barcode,temp->price);
    fprintf(fp1,"\n                                       ________________________________________________________");
    fclose(fp1);
}


void Print_Bill()
{
   FILE *fp;
   char s;
   fp=fopen("D:\Bill.txt","r");
   if(fp==NULL)
   {
       printf("Record Is Empty");
       admin();
   }
   while((s=fgetc(fp))!=EOF)
   {
      printf("%c",s);
   }
   fclose(fp);
   admin();
   getch();
}


void Customer_Purchase_Record()
{
   FILE *fp1;
   char s;
   fp1=fopen("D:\Customer.txt","r");
   if(fp1==NULL)
   {
       printf("Record Is Empty");
       admin();
   }
   while((s=fgetc(fp1))!=EOF)
   {
      printf("%c",s);
   }
   fclose(fp1);
   admin();
   getch();
}


void main()
{
    int a;
    printf("\n********************************************************ADMIN LOGIN********************************************************\n\n");
    a=password();
    if(a==0)
    {
      printf("\n                                                   Welcome.Login Success!\n");
      admin();
    }
    else
    {
       printf("\n                                           Wrong Password Or User Doesn't Exist");
       main();
    }
}



