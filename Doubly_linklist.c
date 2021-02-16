#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct dnode
{
 struct dnode *left;
 int data;
 struct dnode *right;
};
typedef struct dnode dnode;
dnode *getnode();
int main()
    {
    dnode *first;
    int n,pos,item,ch;
    clrscr();
    InitializeDLL(&first);
    printf("\nEnter the number of elements : ");
    scanf("%d",&n);
    CreateDLL(&first,n);
    while(ch!=9)
    {
     printf("\n1.Insert at any  Position");
     printf("\n2.Delete from any position");
     printf("\n3.Display the list");
     printf("\n4.Searching an element");
     printf("\n5.Exit");
     printf("\nEnter the choice : ");
     scanf("%d",&ch);
     switch(ch)
     {

     case 1:{
	     printf("\nEnter the element : ");
	     scanf("%d",&item);
	     printf("\nEnter the position : ");
	     scanf("%d",&pos);
	     InsertDLLpos(&first,pos,item);
	     break;
	     }

     case 2:{
	     printf("\nEnter the position to delete : ");
	     scanf("%d",&pos);
	     DeleteDLLpos(&first,pos);
	     break;
	     }
     case 3:DisplayDLL(first);
	    break;
     case 4:{
	     SearchDLL();
	     break;
	     }
     case 5:exit(0);
	    break;
     default:printf("\nInvalid");
      }
      }
      getch();
      }
InitializeDLL(dnode **first)
{
 (*first)=NULL;
}
DisplayDLL(dnode *first)
{
 if(first==NULL)
  printf("\nLEmpty List");
 else
  {
  printf("\nDisplaying in forward direction");
  printf("\nFirst<->");
  while(first!=NULL)
   {
   printf("%d<->",first->data);
   first=first->right;
   }
   printf("Last\n");
   }
   }
CreateDLL(dnode **f,int n)
{
 dnode *temp,*current;
 int i,item;
 for(i=1;i<=n;i++)
  {
  printf("\nEnter the element at position %d : ",i);
  scanf("%d",&item);
  temp=getnode();
  temp->data=item;
  temp->right=NULL;
  if((*f)==NULL)
   {
   (*f)=temp;
   temp->left=NULL;
   }
  else
  {
   current->right=temp;
   temp->left=current;
  }
  current=temp;
  }
  }
InsertDLLpos(dnode **first,int pos,int item)
{
 dnode *temp,*current;
 int i;
 temp=getnode();
 temp->data=item;
 if(pos==1)
  {
  if(*first!=NULL)
    (*first)->left=temp;
  temp->right=(*first);
  temp->left=NULL;
  (*first)=temp;
  }
  else
  {
  i=2;
  current=(*first);
  while((i<pos)&&(current->right!=NULL))
   {
   i++;
   current=current->right;
   }
  temp->left=current;
  temp->right=current->right;
  if(current->right!=NULL)
   temp->right->left=temp;
  current->right=temp;
  }
 }
SearchDLL(dnode **first)
{
 dnode *temp;
 int item;
 if(*first==NULL)
  {
   printf("\nList is empty");
   return;
  }
  printf("\nEnter the element to search:");
  scanf("%d",&item);
  temp=getnode();
  temp=(*first);
 while(temp!=NULL)
 {
  if(temp->data==item)
  {
   printf("\nElement %d found in the list",item);
   return;
   }
   else
    temp=temp->right;
    }
    printf("\n%d not found",item);
  }
DeleteDLLpos(dnode **first,int pos)
 {
 dnode *current,*prev;
 int i=1,item;
 if(*first==NULL)
  {
  printf("\nList is empty");
  return;
  }
 current=(*first);
 while(current!=NULL)
  {
  if(i==pos)
   {
   item=current->data;
   if(current->left==NULL)
    {
     current->right->left=NULL;
     (*first)=current->right;
     freenode(current);
    }
    else if(current->right=NULL)
     {
      current->left->right=current->right;
      freenode(current);
     }
   else
   {
   current->left->right=current->right;
   current->right->left=current->left;
   freenode(current);
   }
   printf("\nDeleted element = %d",item);
   return;
   }
   i++;
   current=current->right;
  }
  printf("\nInvalid");
  }
  dnode *getnode()
  {
  dnode *p;
  p=(dnode *)malloc(sizeof(dnode));
  return (p);
  }
  freenode(dnode *p)
  {
  free(p);
  }
