#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{ int rollno;
  char name[15];
  struct node *nxt;
}*head,*newnode,*prenode,*ptr;

void addnode()
{ if(head==NULL)
  { head=(struct node *)malloc(sizeof(struct node));
    printf("Enter Roll No. : ");
    scanf("%d",&head->rollno);
    printf("Enter Name : ");
    scanf("%s",&head->name);
	head->nxt=NULL;
    prenode=head;
  }
  else
  { newnode=(struct node *)malloc(sizeof(struct node));
    printf("\nEnter Roll No. : ");
    scanf("%d",&newnode->rollno);
    printf("Enter Name : ");
    scanf("%s",&newnode->name);
    newnode->nxt=NULL;
    prenode->nxt=newnode;
    prenode=newnode;
  }
}

void addnodeatposition()
{ int pos;
  printf("\nEnter position : ");
  scanf("%d",&pos);
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("\nEnter Roll No. : ");
  scanf("%d",&newnode->rollno);
  printf("Enter Name : ");
  scanf("%s",&newnode->name);
  int i=1;
  if(pos==1)
  { newnode->nxt=head;
    head=newnode;
  }
  ptr=head;
  do
  { i++;
    if(pos==i)
    { newnode->nxt=ptr->nxt;
	  ptr->nxt=newnode;
	  printf("\n-------------------------------------------\n");
	  printf("Added successfully.");
	  printf("\n-------------------------------------------\n");
	  break;
	}
    else
	{ ptr=ptr->nxt; }
  }while(ptr!=NULL);
}

void displaylist()
{ if(head==NULL)
  {  printf("--------------------------------------\n");
     printf("List is empty\n");
     printf("--------------------------------------\n");
  }
  else
  { int i=1;
    ptr=head;
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
    }while(ptr!=NULL);
  }
}

int deletenode()
{ if(head==NULL)
  { printf("--------------------------------------\n");
    printf("List is empty !!!\n");
    printf("--------------------------------------\n");
    return 0;
  }
  else 
  { int del;
    char c;
    do
    { printf("\n\nEnter Roll No. to delete : ");
      scanf("%d",&del);
      prenode=head;
      do
      { if(prenode->rollno==del)
        { head=prenode->nxt;
          printf("\n-------------------------------------------\n");
	      printf("Node with matching data deleted successfully.\n");
	      printf("\n-------------------------------------------\n");
	      if(head==NULL)
	      { printf("\n-------------------------------------------\n");
		    printf("List is now empty !");
	        printf("\n-------------------------------------------\n");
	        return 0;
	      }
	      break;
        }
        else if((prenode->nxt)->rollno==del)
        { prenode->nxt=(prenode->nxt)->nxt;
	      printf("Node with matching data deleted successfully.\n");
	      if(head==NULL)
	      { printf("\n-------------------------------------------\n");
		    printf("List is now empty !");
		    printf("\n-------------------------------------------\n");
	        return 0;
	      }
	      break;
        }
        else
        { prenode=prenode->nxt;
	      if(prenode==NULL)
	      { printf("\n-------------------------------------------\n");
		    printf("Element not found !!!");
		    printf("\n-------------------------------------------\n");
		  }
        }
      }while(prenode!=NULL);
      displaylist();
      printf("Want to delete more ? (y/n) : ");
      scanf("%s",&c);
    }while(c=='y');
    return 0;
  }
}

void reverselist()
{ if(head!=NULL)
  { prenode=head;
    ptr=head->nxt;
    head=head->nxt;
    prenode->nxt=NULL;
    while(head!=NULL)
    { head=head->nxt;
      ptr->nxt=prenode;
      prenode=ptr;
      ptr=head;
    }
    head=prenode;
    printf("\n-------------------------------------------\n");
	printf("List is Reversed.");
	printf("\n-------------------------------------------\n");
  }
}

void main()
{ int choice,pos;
  printf("\n\t -: Student Information :-");
  do
  { printf("\n\n-------------------------------------------\n");
    printf("\t\t-: Menu :-\n");
    printf("-------------------------------------------\n\n");
    printf("1. Add node\n2. Add node at specific position\n");
	printf("3. Display List\n4. Delete node\n5. Reverse List\n6. Exit\n");
    printf("\nEnter choice no. : ");
    scanf("%d",&choice);
    switch(choice)
    { case 1 : addnode();
               printf("\n-------------------------------------------\n");
			   printf("Added Successfully.");
			   printf("\n-------------------------------------------\n");
			   break;
	  case 2 : addnodeatposition();
	           break;
      case 3 : displaylist();
               break;
      case 4 : deletenode();
               break;
      case 5 : reverselist();
      case 6 : break;
	  default : printf("\nPlease enter valid choice number !!!");
	}
  }while(choice!=6);
  printf("\nPress any key to EXIT ...");
  getch();
}
