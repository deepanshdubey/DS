#include<stdio.h>

int i,j,n;

void inputarray(int arr[])
{ printf("\nEnter number of elements : ");
  scanf("%d",&n);
  printf("\n");
  for(i=0;i<n;i++)
  { printf("Enter element %d : ",i+1);
    scanf("%d",&arr[i]);
  }
}

int linearsearch(int arr[],int x)
{ int flag=0;
  for(i=0;i<n;i++)
  { if(arr[i]==x)
    { return i+1; }
  }
  return -1;
}

void sortarray(int arr[])
{ int temp;
  for(i=0;i<n;i++)
  { for(j=i+1;j<n;j++)
    { if(arr[i]>arr[j])
      { temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
	  }
	}
  }
  printf("\n\n# Sorted array is :-\n\n |");
  for(i=0;i<n;i++)
  { printf(" %d |",arr[i]); }
  printf("\n");
}

int binarysearch(int arr[],int x)
{ int first=0,middle,last=n-1;
  while(first<=last)
  { middle=first+(last-first)/2;
    if(arr[middle]==x)
    { return middle+1; }
    else if(arr[middle]<x)
    { first=middle+1; }
    else
    { last=middle-1; }
  }
  return -1;
}

void main()
{ int arr[50],x,choice,k;
  printf("\t-: Linear & Binary Search on an Array :-");
  printf("\n\n# Input array details :-\n");
  inputarray(arr);
  printf("\nEnter element to search : ");
  scanf("%d",&x);
  printf("\n\n# Which sorting method to use ?\n");
  printf("\n1. Linear Search\n2. Binary Search");
  printf("\n\nEnter your choice number (1 or 2) : ");
  scanf("%d",&choice);
  switch(choice)
  { case 1 : k=linearsearch(arr,x);
             if(k!=-1)
			 { printf("\nFound at position : %d",k); }
			 else
			 { printf("\nNot found (%d) !",k); }
             break;
    case 2 : sortarray(arr);
             k=binarysearch(arr,x);
             if(k!=-1)
			 { printf("\nFound at position : %d",k); }
			 else
			 { printf("\nNot found (%d) !",k); }
             break;
    default : printf("\n\nPlease enter valid choice number !!!");
  }
  printf("\n\nPress any key to EXIT ...");
  getch();
}
