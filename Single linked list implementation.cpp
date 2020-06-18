//single linked list all operation

#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int info;
    struct node *link;
};
struct node *START=NULL;
void append();
void Print();
void insertbegin();
int length();
int len;
void del();
void insert_after();

void revers();

int main()
{
    int ch;

    while(1)
    {
        printf("single linked list operation: \n");
        printf("1.Append\n");
        printf("2.insert begin\n");
        printf("3.insert_after\n");
        printf("4.length\n");
        printf("5.Print\n");
        printf("6.delete\n");
        cout<<"7.reverse"<<endl;
        printf("8.quit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            append();
            break;
        case 2:
            insertbegin();
            break;
        case 3:
            insert_after();
            break;
        case 4:
            len = length();
            printf("%d\n",len);
            break;

        case 5:
            Print();
            break;
        case 6:
            del();
            break;
        case 7:
            revers();
            break;
        case 8:
            exit(1);

        default:
            printf("Invalid choice\n");
        }
    }
}

void append()
{
    struct node *NEW;
    NEW= new node;
    printf("Enter node data:");
    scanf("%d",&NEW->info);
    NEW->link=NULL;

    if(START==NULL)
    {
        START=NEW;
    }

    else
    {
        struct node *PTR;

        PTR=START;

        while(PTR->link!=NULL)
        {
            PTR = PTR->link;
        }
        PTR->link=NEW;
    }
}

void Print()
{
    struct node *PTR;

    PTR=START;

    if(PTR==NULL)
    {
        printf("List is empty.\n");
    }
    else
    {

        while(PTR!=NULL)
        {
            printf("%d ",PTR->info);
            PTR=PTR->link;

        }
        printf("\n");
    }

}

void insertbegin()
{
    struct node *NEW;

    NEW = new node;
    printf("enter the data: ");
    scanf("%d",&NEW->info);

    NEW->link=NULL;
    if(START==NULL)
    {
        START=NEW;

    }

    else
    {
        NEW->link=START;
        START=NEW;
    }
}

int length()
{
    struct node *p;
    int c=0;
    p=START;

    while(p!=NULL)
    {
        p=p->link;
        c++;
    }
    return c;

}

void del()
{
    int loc;
    printf("Enter locaton to delete:");
    scanf("%d",&loc);
    struct node *New;

    if(loc>length()||loc==0)
    {
        printf("invalid location\n");
    }
    else if(loc==1)
    {
    START = START->link;
    }
    else
    {
        struct node *p,*q;
        p=START;

        int i=1;

        while(i<loc-1)
        {
            p = p->link;
            i++;
        }
        q = p->link;

        p->link = q->link;

        q->link = NULL;

        free(q);

    }

}

void insert_after()
{
    struct node *NEW,*p;
    int loc;
    int i=1;
    printf("Enter location:");
    scanf("%d",&loc);

    len=length();

    if(loc>len)
    {
        printf("Invalid equation.\n");
        printf("currently list has %d nodes.\n",len);
    }

    else
    {
        p=START;
        while(i<loc)
        {
            p=p->link;
            i++;
        }

        NEW= new node;

        printf("enter node data:");
        scanf("%d",&NEW->info);
        NEW->link = p->link;
        p->link=NEW;
    }
}


void revers()
{
    struct node *p,*q;

   p = START;
   q = START;

   int i,j ;

   i=0;
   len = length();
   j=len-1;

   while(i<j)
   {
      int k=0;

       while(k<j)
       {
           q= q->link;
           k++;
       }

      int temp;

      temp = p->info;

      p->info = q->info;

      q->info = temp;

       i++;
       j--;

    p=p->link;
    q= START;
   }
}

