#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{ int empid;
  char name[15];
  struct node *nxt;
  struct node *pre;
}*last,*newnode,*postnode,*ptr;

void addfront()
{ if(last==NULL)
  { last=(struct node *)malloc(sizeof(struct node));
    printf("Enter Employee ID : ");
    scanf("%d",&last->empid);
    printf("Enter Name : ");
    scanf("%s",&last->name);
	last->nxt=NULL;
	last->pre=NULL;
    postnode=last;
  }
  else
  { newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter Employee ID : ");
    scanf("%d",&newnode->empid);
    printf("Enter Name : ");
    scanf("%s",&newnode->name);
    newnode->nxt=postnode;
    postnode->pre=newnode;
    newnode->pre=NULL;
    postnode=newnode;
  }
}

void displaycircularlist()
{ if(last==NULL)
  {  printf("--------------------------------------\n");
     printf("List is empty\n");
     printf("--------------------------------------\n");
  }
  else
  { int i=1;
    ptr=postnode;
    printf("\n\nDoubly Linked list is :-\n\n");
    printf("-------------------------------------------------------\n");
    do
    { printf("Node - %d : Employee ID - %d",i,ptr->empid);
	  printf("\n         : Name - %s",ptr->name);
	  printf("\n         : Address - %d",ptr);
	  printf("\n         : Next - %d \n",ptr->nxt);
      printf("-------------------------------------------------------\n");
      ptr=ptr->nxt;
      i++;
    }while(ptr!=NULL);
  }
}

int deleteend()
{ if(last==NULL)
  { printf("--------------------------------------\n");
    printf("List is empty\n");
    printf("--------------------------------------\n");
    return 0;
  }
  else
  { if(last->pre==NULL)
    { last=NULL; }
    else
	{ ptr=last->pre;
      ptr->nxt=NULL;
      last=ptr;
    }
	printf("\n-------------------------------------------\n");
	printf("Deleted Successfully.");
	printf("\n-------------------------------------------\n");
  }
}

void main()
{ int choice;
  printf("\n\t -: Employee Information :-");
  do
  { printf("\n\n-------------------------------------------\n");
    printf("\t\t-: Menu :-\n");
    printf("-------------------------------------------\n\n");
    printf("1. Add Node at Front\n2. Display doubly linked List\n");
	printf("3. Delete Node from End\n4. Exit\n");
    printf("\nEnter choice no. : ");
    scanf("%d",&choice);
    switch(choice)
    { case 1 : addfront();
               printf("\n-------------------------------------------\n");
			   printf("Added Successfully.");
			   printf("\n-------------------------------------------\n");
			   break;
	  case 2 : displaycircularlist();
	           break;
      case 3 : deleteend();
               break;
      case 4 : break;
	  default : printf("\nPlease enter valid choice number !!!");
	}
  }while(choice!=4);
  printf("\nPress any key to EXIT ...");
  getch();
}
