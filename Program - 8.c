#include <stdio.h>
#include <stdlib.h>

struct nodebt
{
  int info;
  struct nodebt *l;
  struct nodebt *r;
} * root, *temp, *t2, *t1;

int flag = 1;

void insert()
{
  create();
  if (root == NULL)
  {
    root = temp;
  }
  else
  {
    search(root);
  }
}

void create()
{
  int data;
  printf("Enter Data : ");
  scanf("%d", &data);
  temp = (struct nodebt *)malloc(1 * sizeof(struct nodebt));
  temp->info = data;
  temp->l = temp->r = NULL;
}

int search(struct nodebt *t)
{
  if ((temp->info > t->info) && (t->r != NULL))
  {
    search(t->r);
  }
  else if ((temp->info > t->info) && (t->r == NULL))
  {
    t->r = temp;
  }
  else if ((temp->info < t->info) && (t->l != NULL))
  {
    search(t->l);
  }
  else if ((temp->info < t->info) && (t->l == NULL))
  {
    t->l = temp;
  }
}

int in_order(struct nodebt *t)
{
  if (root == NULL)
  {
    printf("\n-------------------------------------------\n");
    printf("Tree is Empty !!!");
    printf("\n-------------------------------------------\n");
    return 0;
  }
  if (t->l != NULL)
  {
    in_order(t->l);
  }
  printf("-> %d", t->info);
  if (t->r != NULL)
  {
    in_order(t->r);
  }
}

int deletenode()
{
  int data;
  if (root == NULL)
  {
    printf("\n-------------------------------------------\n");
    printf("Tree is Empty !!!");
    return 0;
  }
  printf("Enter data to be deleted : ");
  scanf("%d", &data);
  t1 = root;
  t2 = root;
  search1(root, data);
}

int pre_order(struct nodebt *t)
{
  if (root == NULL)
  {
    printf("Tree is Empty !!!");
    return 0;
  }
  printf("-> %d", t->info);
  if (t->l != NULL)
  {
    pre_order(t->l);
  }
  if (t->r != NULL)
  {
    pre_order(t->r);
  }
}

int post_order(struct nodebt *t)
{
  if (root == NULL)
  {
    printf("Tree is Empty !!!");
    return 0;
  }
  if (t->l != NULL)
  {
    post_order(t->l);
  }
  if (t->r != NULL)
  {
    post_order(t->r);
  }
  printf("-> %d", t->info);
}

void search1(struct nodebt *t, int data)
{
  if ((data > t->info))
  {
    t1 = t;
    search1(t->r, data);
  }
  else if ((data < t->info))
  {
    t1 = t;
    search1(t->l, data);
  }
  else if ((data == t->info))
  {
    delete1(t);
  }
}

int delete1(struct nodebt *t)
{
  int k;
  if ((t->l == NULL) && (t->r == NULL))
  {
    if (t1->l == t)
    {
      t1->l = NULL;
    }
    else
    {
      t1->r = NULL;
    }
    t = NULL;
    free(t);
    return 0;
  }
  else if ((t->r == NULL))
  {
    if (t1 == t)
    {
      root = t->l;
      t1 = root;
    }
    else if (t1->l == t)
    {
      t1->l = t->l;
    }
    else
    {
      t1->r = t->l;
    }
    t = NULL;
    free(t);
    return 0;
  }
  else if (t->l == NULL)
  {
    if (t1 == t)
    {
      root = t->r;
      t1 = root;
    }
    else if (t1->r == t)
    {
      t1->r = t->r;
    }
    else
    {
      t1->l = t->r;
    }
    t == NULL;
    free(t);
    return 0;
  }
  else if ((t->l != NULL) && (t->r != NULL))
  {
    t2 = root;
    if (t->r != NULL)
    {
      k = least(t->r);
      flag = 1;
    }
    else
    {
      k = biggest(t->l);
      flag = 2;
    }
    search1(root, k);
    t->info = k;
  }
}

int least(struct nodebt *t)
{
  t2 = t;
  if (t->l != NULL)
  {
    t2 = t;
    return (least(t->l));
  }
  else
  {
    return (t->info);
  }
}

int biggest(struct nodebt *t)
{
  if (t->r != NULL)
  {
    t2 = t;
    return (biggest(t->r));
  }
  else
  {
    return (t->info);
  }
}

void main()
{
  int choice;
  printf("\n\n-------------------------------------------\n");
  printf("\t\t-: Tree :-\n");
  printf("-------------------------------------------\n");
  do
  {
    printf("\n\n-------------------------------------------\n");
    printf("\t\t-: Menu :-\n");
    printf("-------------------------------------------\n\n");
    printf("\n1. Insert Element\n");
    printf("2. Delete Element\n");
    printf("3. Inorder Expression\n");
    printf("4. Preorder Expression\n");
    printf("5. Postorder Expression\n");
    printf("6. Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      insert();
      printf("\n-------------------------------------------\n");
      printf("Added successfully.");
      printf("\n-------------------------------------------\n");
      break;
    case 2:
      deletenode();
      printf("\n-------------------------------------------\n");
      printf("Completed.");
      printf("\n-------------------------------------------\n");
      break;
    case 3:
      printf("\n-------------------------------------------\n");
      in_order(root);
      printf("\n-------------------------------------------\n");
      break;
    case 4:
      printf("\n-------------------------------------------\n");
      pre_order(root);
      printf("\n-------------------------------------------\n");
      break;
    case 5:
      printf("\n-------------------------------------------\n");
      post_order(root);
      printf("\n-------------------------------------------\n");
      break;
    case 6:
      break;
    default:
      printf("\nPlease enter valid choice number !!!");
    }
  } while (choice != 6);
  printf("\nPress any key to EXIT ...");
  getch();
}
