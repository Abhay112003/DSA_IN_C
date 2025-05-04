#include<stdio.h>
#include<stdlib.h>
struct Employee{
  int empid;
  char name[20];
  struct Employee *next; 
}*start;
struct Employee *create()
{
  struct Employee *ptr;
  ptr=(struct Employee *)malloc(sizeof(struct Employee));
  if(ptr==NULL)
  {
    printf("Not Memory Allocated :");
  }
  else
  {
    printf("Enter a Employee ID :");
    scanf("%d",&ptr->empid);
    fflush(stdin);
    printf("Enter a Employee Name :");
    scanf("%s",&ptr->name);
    return ptr;
  }
}
void AddStart()
{
  if(start==NULL)
  {
    printf("No Employee Exists :");
  }
  else
  {
    struct Employee *ptr=create();
    struct Employee *p=start;
    while(p->next!=start)
      p=p->next;
    ptr->next=start;
    start=ptr;
    p->next=start;
  }
}
void AddMiddle()
{
  if(start==NULL)
  {
    printf("No Employee Exists :");
  }
  else
  {
    int m;
    printf("\nEnter a Employee Id before you add a New Employee");
    scanf("%d",&m);
    struct Employee *ptr=create();
    struct Employee *p=start; 
  do
  {
    if(p->empid==m)
    {
      ptr->next=p->next;
      p->next=ptr;
    }
    p=p->next;
  }while(p!=start);
 }
}
void AddEnd()
{
   struct Employee *ptr=create();
    if(start==NULL)
    {
      start=ptr;
      ptr->next=start;
    }
    else
    {
      struct Employee *p=start;
      while(p->next!=start)
       p=p->next;   
      p->next=ptr;
      ptr->next=start;
    }
}
void ShowAllEmployee()
{
  if(start==NULL)
  printf("NO Employee Exists :");
  struct Employee *ptr=start;
  do
  {
    printf("\n%d",ptr->empid);
    printf("\n%s",ptr->name);
    printf("\n==============");
    ptr=ptr->next;
  }while(ptr!=start);
}
void DeleteEmployee()
{
  struct Employee *p=start,*prev;
  int d;
  printf("Enter a Employee Id to delete");
  scanf("%d",&d);
  do
  {
    if(p->empid==d)
    {
      if(p==start)
      {
        struct Employee *p2;
        if(start->next==start)
         {
          start=NULL;
          return ;
         }
        while(p->next!=start)
         p=p->next;
        start=start->next;
        p->next=start;
      }
      else if(p->next==start)
      {
         prev->next=start;
      }
      else
      {
        prev->next=p->next;
      }
      free(p);
      break;
    }
    prev=p;
    p=p->next;
  }while(p!=start);
}
void main()
{
 start=NULL;
 int ch;
 do
 {
 printf("\n1.Add a Employee in the Start :");
 printf("\n2.Add a Employee in the Middle :");
 printf("\n3,Add a Employee in the End :");
 printf("\n4.Show All Employee :");
 printf("\n5.Delete a Employee :");
 printf("\n6.Exit :");
 printf("Select Your Choice :");
 scanf("%d",&ch);
 if(ch==1)
 AddStart();
else if(ch==2)
AddMiddle();
else if(ch==3)
AddEnd();
else if(ch==4)
 ShowAllEmployee();
else 
  DeleteEmployee(); 
}while(ch!=6);
}