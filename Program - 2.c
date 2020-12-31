#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{ int data;
  struct node *nxt;
}*head,*newnode,*ptr;

void push()
{ if(head==NULL)
  { head=(struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&head->data);
    head->nxt=NULL;
  }
  else
  { newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter data : ");
    scanf("%d",&newnode->data);
    newnode->nxt=head;
    head=newnode;
  }
}

void traverse()
{ if(head==NULL)
  { printf("--------------------------------------\n");
    printf("Stack is empty\n");
    printf("--------------------------------------\n");
  }
  else
  { int i=1;
    ptr=head;
    printf("\n\nStack is :-\n\n");
    printf("---------------------------------------------------------------\n");
    do
    { printf("Node - %d | Data - %d | Address - %d |  Next - %d \n",
      i,ptr->data,ptr,ptr->nxt);
      printf("---------------------------------------------------------------\n");
      ptr=ptr->nxt;
      i++;
    }while(ptr!=NULL);
  }
}

void pop()
{ if(head==NULL)
  { printf("\nUnderflow !!!"); }
  else
  { ptr=head;
    head=head->nxt;
    free(ptr);
    printf("\nPopped Successfully.");
  }
}

void main()
{ int choice;
  printf("\n    -: Stack using Linear Linked List :-");
  do
  { printf("\n\n-------------------------------------------\n");
    printf("\t\t-: Menu :-\n");
    printf("-------------------------------------------\n\n");
    printf("1. Push\n2. Traverse\n3. Pop\n4. Exit\n");
    printf("\nEnter choice no. : ");
    scanf("%d",&choice);
    switch(choice)
    { case 1 : push();
               printf("\nPushed Successfully.");
			   break;
      case 2 : traverse();
               break;
      case 3 : pop();
               break;
      case 4 : break;
	  default : printf("\nPlease enter valid choice number !!!");
	}
  }while(choice!=4);
  printf("\nPress any key to EXIT ...");
  getch();
}
