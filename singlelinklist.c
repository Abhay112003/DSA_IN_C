#include<stdio.h>
#include<stdlib.h>
struct student{
    int rollno;
    char name[20];
    struct  student *next;
}*start;
void addStudent()
{
  struct student *m,*ptr;
  int c,r;
  ptr=(struct student *)malloc(sizeof(struct student));
  if(ptr==NULL)
  printf("Do Not Allocate  memory");
  else
  {
    printf("Enter a Student Rollno :");
    scanf("%d",&ptr->rollno);
    printf("Enter a Student Name :");
    scanf("%s",&ptr->name);
    printf("\n1.Add New Student in the Beginning :");
    printf("\n2.Add New Student in the Middle :");
    printf("\n3.Add New Student in the End");
    printf("\nSelect Your Choice :");
    scanf("%d",&c);
    if(c==1)
    {    
    ptr->next=start;
    start=ptr;
    }
    else if(c==2)
    {
        printf("Enter a rollno before you add a Student Data :");
        scanf("%d",&r);
        for(m=start;(m);m=m->next)
        {
           if(m->rollno==r)
           {
            ptr->next=m->next;
             m->next=ptr;
           }
        }
    }
    else
    {
    if(start==NULL)
    {
        start=ptr;
        ptr->next=NULL;
    }
    else
    {
        struct student *prev,*p;
        for(p=start;(p);p=p->next)
           prev=p;
        prev->next=ptr;
        ptr->next=NULL;
    }
    } 
  }
}
void showAllStudent()
{
 struct student *p;
 if(start==NULL)
 printf("No Student Data Found");
 for(p=start;(p);p=p->next)
 {
    printf("\nStudent Rollno is %d",p->rollno);
    printf("\nStudent Name is %s",p->name);
 }
}
void deleteStudent()
{
 int d;
 struct student *prev,*ptr;
 printf("\nEnter a Rollno to Delete :");
 scanf("%d",&d);
 for(ptr=start;(ptr);ptr=ptr->next)
 {
  if(ptr->rollno==d)
  {
    if(ptr==start)
     start=start->next;
    else if(ptr->next==NULL)
     prev->next=NULL;
    else
     prev->next=ptr->next;

     free(ptr);
     break;
  }
  prev=ptr;
 }
}
void main(){
 start=NULL;
 int ch;
 do
 {
 printf("\n1.Add a New Student :");
 printf("\n2.Show All Student :");
 printf("\n3.Delete a Student by Rollno :");
 printf("\n4.Exit :");
 printf("\nSelect Your Choice :");
 scanf("%d",&ch);
 if(ch==1)
  addStudent();
else if(ch==2)
  showAllStudent();
else 
    deleteStudent();
 }while(ch!=4);
}