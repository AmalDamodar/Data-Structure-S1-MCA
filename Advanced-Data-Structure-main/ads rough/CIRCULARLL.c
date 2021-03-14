#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
 { int data;
   struct node *link;
 };
typedef struct node node;
node *getnode();
main()
 { node *first,*last;
   int ch,item,pos,n;
   InCL(&first,&last);
   clrscr();
   printf("\n Creating a circular linked list...");
   printf("\n How many nodes do you want to create?");
   scanf("%d",&n);
   CLC(&first,&last);
   while(1)
    { printf("\n Enter your choice...");
      printf("\n 1.Insertion");
      printf("\n 2.Deletion");

      printf("\n 3.Display");
      printf("\n 4.Exit\n");
      scanf("%d",&ch);
      switch(ch)
       { case 1:printf("\n Enter the item:");
		scanf("%d",&item);
		printf("\n Enter the node number:");
		scanf("%d",&pos);
		ICL(&first,&last,item,pos);
	 break;
	 case 2:printf("\n Enter the node to be deleted:");
		scanf("%d",&pos);
		DCL(&first,&last,pos);
	 break;
	 case 3:TCL(first,last);
	 break;
	 case 4:exit(0);
	}
     }
 }
InCL(node **first,node **last)
 { (*first)=NULL;
    (*last)=NULL;

 }
CLC(node **f,node **l,int n)
 { node *temp,*current;
   int i,item;
   for(i=1;i<=n;i++)
    { printf("\n Enter the data field #%d:",i);
      scanf("%d",&item);
      temp=getnode();
      temp->data=item;
      if(*f==NULL)
       *f=temp;
      else
       (*l)->link=temp;
      (*l)=temp;

    }

  }
TCL(node *first, node *last)
 { if(first==NULL)
    { printf("\n List is empty..");
      return;
    }
   printf("\n Linked list is..\n");
   printf("\n Start->");
   do
    { printf("%d->",first->data);
      first=first->link;
    }while(last->link!=first);
   printf("END\n");

 }
ICL(node **first,node **last,int item, int pos)
 { node *current,*prev,*temp;
   int i;
   temp=getnode();
   if(temp==NULL)
    { printf("\n Unable to create new node...");
      return;
    }
   if((*first==NULL)||(pos==1))
    { temp->data=item;
      temp->link=(*first);
      if(*last==NULL)
       (*last)=temp;
      else
       (*last)->link=temp;
      (*first)=temp;
     return;
     }
   current=(*first);
   i=2;
   while(current->link!=(*first))
    { if(i==pos)
       { temp->data=item;
	 temp->link=current->link;
	 current->link=temp;
	 return;
       }
      else
       { i++;
	 current=current->link;
       }
     }
   temp->data=item;
   temp->link=current->link;
   current->link=temp;
   (*last)=temp;

 }
DCL(node**first,node **last,int pos)
 { node *current,*temp;
   int item,i;
   if(*first==NULL)
    { printf("\n List is empty..");
      return;
    }
   if(pos==1)
    { current=(*first);
      item=current->data;
      if((*first)->link==(*first))
       (*first)=(*last)=NULL;
      else
       { (*first)=(*first)->link;
	 (*last)->link=(*first);
       }
      freenode(current);
      printf("\n Deleted item is:%d",item);
     }
   current=(*first);
   i=2;
   while(current->link!=(*first))
    { if(i==pos)
       { temp=current->link;
	 item=temp->data;
	 current->link=temp->link;
	 freenode(temp);
	 printf("\n Deleted item is:%d",item);
	 return;
	}
       else
	current=current->link;
       i++;
     }
   printf("\n No such node found...");

 }
node *getnode()
 { node *t;
   t=(node *)malloc(sizeof(node));
   return t;
 }
freenode(node *t)
 { free(t);

 }

