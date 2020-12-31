#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{ int rollno;
  char name[15];
  struct node *nxt;
}*last,*newnode,*prenode,*ptr;

void addfront()
{ if(last==NULL)
  { last=(struct node *)malloc(sizeof(struct node));
    printf("Enter Roll No. : ");
    scanf("%d",&last->rollno);
    printf("Enter Name : ");
    scanf("%s",&last->name);
	last->nxt=last;
    prenode=last;
  }
  else
  { newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter Roll No. : ");
    scanf("%d",&newnode->rollno);
    printf("Enter Name : ");
    scanf("%s",&newnode->name);
    newnode->nxt=prenode;
    last->nxt=newnode;
    prenode=newnode;
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
    ptr=last->nxt;
    printf("\n\nLinked list is :-\n\n");
    printf("-------------------------------------------------------\n");
    do
    { printf("Node - %d : Roll No. - %d",i,ptr->rollno);
	  printf("\n         : Name - %s",ptr->name);
	  printf("\n         : Address - %d",ptr);
	  printf("\n         : Next - %d \n",ptr->nxt);
      printf("-------------------------------------------------------\n");
      ptr=ptr->nxt;
      i++;
    }while(ptr!=prenode);
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
  { if(last->nxt==last)
    { last=NULL; }
    else
	{ ptr=last->nxt;
      do
      { ptr=ptr->nxt;
        if(ptr->nxt==last)
        { ptr->nxt=last->nxt;
          free(last);
          last=ptr;
          break;
	    }
      }while(ptr!=prenode);
    }
	printf("\n-------------------------------------------\n");
	printf("Deleted Successfully.");
	printf("\n-------------------------------------------\n");
  }
}

void main()
{ int choice;
  printf("\n\t -: Student Information :-");
  do
  { printf("\n\n-------------------------------------------\n");
    printf("\t\t-: Menu :-\n");
    printf("-------------------------------------------\n\n");
    printf("1. Add Node at Front\n2. Diaplay Circular List\n");
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
