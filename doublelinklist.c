#include<stdio.h>
#include<stdlib.h>
struct student
{
int rollno;
struct student *next;
struct student *prev;
}*start,*end;
struct student *createnode()
{
    struct student *ptr;
    ptr=(struct student *)malloc(sizeof(struct student));
    printf("Enter a Student Rollno:");
    scanf("\n%d",&ptr->rollno);
    return ptr;
}
void addStart()
{
 struct student *ptr=createnode();
 if(start==NULL)
  printf("No Data Found :");
 else
 {
    ptr->next=start;
    start=ptr;
    start->prev=NULL;
 }
}
void addMiddle()
{
 struct student *ptr=createnode();
 struct student *p;
 int m;
 if(start==NULL)
  printf("No Data Found");
 else
 {
    printf("Enter a Rollno after you want to add a new Student :");
    scanf("%d",&m);
    for(p=start;(p);p=p->next)
    {
        if(p->rollno==m)
        {
         p->next->prev=ptr;
         ptr->next=p->next;
         ptr->prev=p;
         p->next=ptr;
        }
    }
 }
}
void addEnd()
{
    struct student*prt=createnode();
    if(start==NULL)
    {

    start=end=prt;
    prt->next=NULL;
    prt->prev=NULL;
   
    }
    else
    {
        end->next=prt;
        prt->prev=end;
        end=prt;
        end->next=NULL;
    }

}
void searchStudent()
{
    int s;
    struct student *p;
    int count=1;
  if(start==NULL)
   printf("\nNo Data Found :");
  else
  {
    printf("Enter a Rollno to Search :");
    scanf("%d",&s);
   for(p=start;(p);p=p->next)
   {
    if(p->rollno==s)
     {
      printf("Student is Found");
      count=0;
     }
   }
   if(count==1)
    printf("Student is not Found");
  }
}
void showAll()
{
    struct student *ptr;
    if(start==NULL)
    printf("\nNo Data Found :");
 else{
    for(ptr=start;(ptr);ptr=ptr->next)
    {
        printf("\n%d",ptr->rollno);
    }
   }
}
void deleteStudent()
{
 int d;
 struct student *prev,*p;
 printf("Enter a Rollno to Delete "); 
 scanf("%d",&d);
 for(p=start;(p);p=p->next)
 {
    if(p->rollno==d)
    {
        if(p==start)
        {
            start=start->next;
            start->prev=NULL;
        }
        else if(p->next==NULL)
        {
            end=end->prev;
            end->next=NULL;
        }
        else
        {
           p->prev->next=p->next;
           p->next->prev=p->prev;
        }
        free(p);
        break;
    }
 }
}
void main()
{
    start=end=NULL;
    int c;
    do
    {
        printf("\n1.Add a Student in the beginning:");
        printf("\n2.Add a Student in the Middle");
        printf("\n3.Add a Student in the End");
        printf("\n4.Show all Student :");
        printf("\n5.Delete a Student :");
        printf("\n6.Search a Student :");
        printf("\n7.Exit ");
        printf("Select your choice :");
        scanf("%d",&c);
        if(c==1)
        addStart();
       else if(c==2)
        addMiddle();
       else if(c==3)
         addEnd();
       else if(c==4)
        showAll();
      else if(c==5)
        deleteStudent();
      else if(c==6)
        searchStudent();
    }while(c!=7);

}