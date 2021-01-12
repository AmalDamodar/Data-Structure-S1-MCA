#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

typedef struct Node Node;

void main()
{
 struct Node *first ,*last;
 int ch,v,pos,n;
 
 Initialize(&first,&last);
 
 printf("Number of nodes");
 scanf("%d",&n);
 
 create(&first,&last);
 
 while(ch!=4)
 {
     printf("Menu");
     printf("\n 1.Insert");
     printf("\n 2.Delete");
     printf("\n 3.Display");
     printf("\n 4.exit");
     printf("Enter your choice");
     scanf("&d",&ch);
     switch(ch)
     {
         case 1:
                
                    printf("\n Enter item");
                    scanf("%d",&v);
                    printf("\n Enter position");
                    scanf("%d",&pos);
                    insert(&first,&last,v,pos);
                    break;
                
         case 2:
                
                    printf("Enter node to delete");
                    scanf("&d",&pos);
                    delete(&first,&last,pos);
                    break;
                
         case 3:
                
                    traverse(first,last);
                    break;
                
         case 4: exit(0);
     }
 }
}

Initialize(Node *first, Node *last)
{
    first=last=NULL;
}

create(Node *f, Node *l,int n)
{
    Node *t,*c;
    int i,v;
    for(i=1;i<=n;i++)
    {
        printf("Enter the data #%d:",i);
        scanf("%d",&v);
        t=(Node *)malloc(sizeof(Node));
        t->data=v;
        if(f==NULL)
            f=t;
        else
            l->link=t;
        l=t;
    }
}

insert(Node *first,Node *last,int v,int pos)
{
    Node *c,*prev,*t;
    int i;
    t=(Node *)malloc(sizeof(Node));
    if(t==NULL)
    {
        printf("Unable to create");
        return;
    }
    if((first==NULL)||(pos==1))
    {
        t->data=v;
        t->link=first;
        if(last==NULL)
        last=t;
        else
        last->link=t;
        first=t;
        return;
    }
}

delete(Node *first,Node *last,int pos)
{
    Node *c,*t;
    int v,i;
    if(first==NULL)
    {
        printf("Empty");
        return;
    }
    c=first;
    i=2;
    while(c->link!=first)
    {
        if(i==pos)
        {
            t=c->link;
            v=t->data;
            c->link=t->link;
            free(t);
            printf("Deleted item=%d",v);
            return;
        }
        else
        c=c->link;
        i++;
        }
}

traverse(Node *first,Node *last)
{
    if(first==NULL)
    {
        printf("Empty");
        return;
    }
    do
    {
        printf("%d->",first->data);
        first=first->link;
    }
    while(last->link!=first);
}