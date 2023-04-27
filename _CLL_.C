#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	struct node *link;
}*first=NULL,*temp,*nn,*last;
struct node* createSLL(struct node *f)
{
    char ch ;
    do
    {
        nn = (struct node*)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d",&nn->x);
        if(f==NULL)
        {
            f=nn;
            temp=nn;
        }
        else
        {
            temp->link=nn;
            temp=nn;
        }
        printf("continue (y/n)");
        fflush(stdin);
        ch=getchar();
    }while(ch=='y');
    temp->link=NULL;
    last=nn;
    return (f);
}
void insertbeg()
{
    nn= (struct node*)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d",&nn->x);
    if(first =NULL)
    {
        first = nn;
        nn->link = NULL;
    }
    else{
    nn->link =first;
    first = nn;
    }
}
void insertend()
{
    nn= (struct node*)malloc(sizeof(struct node));
    printf("enter data");
    scanf("%d",&nn->x);
    if(first =NULL)
    {
        first = nn;
        nn->link = NULL;
        last =nn;
    }
    else
    {
        last->link=nn;
        nn->link=NULL;
        last = nn;
    }
}
int count()
{
    int cnt = 0;
    if(first =NULL)
         return cnt;
    else
    {
        temp = first;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->link;
        }
        return cnt;
    }
}
void insertpos()
{
    int pos,c,i;
    c=count();
    printf("enter position ");
    scanf("%d",&pos);
    if(pos==1&&c==0)
        insertbeg();
    else if(pos==c+1)
        insertend();
    else if(pos > c+1)
        printf("Invalid choice");
    else
    {
        nn= (struct node*)malloc(sizeof(struct node));
        scanf("%d",&nn->x);
        temp = first;
        i=1;
        while(i<pos-1)
        {
            temp=temp->link;
            i++;
        }
        nn->link=temp->link;
        temp->link=nn;
    }
}
void insert()
{
    int ch;
    char c ;
    do
    {
        printf("1.insertbeg 2.insertend 3.insertpos\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :insertbeg();
                break;
            case 2: insertend();
            break;
            case 3:insertpos();
            break;
            default:printf("invalid choice");
        }
        printf("continue (y/n)");
        c=getchar();
    }while(c=='y');
}


void deletebeg()
{
    struct node *t;
    if(first ==NULL)
        printf("LL is empty");
    else
    {
        t=first;
        first=first->link;
    }
        t->link=NULL;
        free(t);
}

void deleteend()
{
    struct node *t;
    if(first==NULL)
            printf("SLL is empty");
    else
    {
        temp =first;
        while(temp->link->link!=NULL)
        {
            temp=temp->link;
        }
        t=temp->link;
        temp->link=NULL;
        free(t);
}
}

void deletepos()
{
    struct node *t;
    int i,c,pos;
    c=count();
    scanf("%d",&pos);
    if(c==0)
            printf("SLL is empty ");
    else if (pos ==1 )
        deletebeg();
    else if(pos ==c)
        deleteend();
    else if(pos>c)
        printf("Invalid pos");
    else
    {
        i=1;
        temp=first;
        while(i<pos-1)
        {
            temp=temp->link;
            i++;
        }
        t=temp->link;
        temp->link=t->link;
        t->link=NULL;
        free(t);
    }
}
void delete1()
{
    int ch;
    char c;
    do
    {
        printf("1.deletebeg 2. deleteend 3.deletepos \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :deletebeg();
            break;
            case 2 :deleteend();
            break;
            case 3 :deletepos();
            break;
            default:printf("Invalid choice");
        }
        printf("Continue (y/n)");
        c=getchar();
    }while(c=='y');
}


int search()
{
    int ele,flag;
    printf("enter element to be searched ");
    scanf("%d",&ele);
    if(first==NULL)
        return 0;
    else
    {
        temp=first;
        flag=1;
        while(temp!=NULL)
        {
            if(ele==temp->x)
            {
                flag=2;
                break;
            }
            temp=temp->link;
        }
    }
    return flag;
}

void display(struct node *f)
{
    if(f==NULL)
        printf("LL is empty");
    else
    {
        printf("content of SLL is \n");
        temp=f;
        while(temp!=NULL)
        {
            printf("%d",temp->x);
            temp=temp->link;
        }
    }
}



main()
{
    int ch,f;
    char c;
    do
    {
        printf("1.create 2. insert 3.delete 4.search 5.display \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:first=createSLL(first);
            break;
            case 2:insert();
            break;
            case 3:delete1();
            break;
            case 4:f=search();
                if(f==0)
                    printf("LL is empty");
                else if(f==1)
                    printf("element not found");
                else
                    printf("element found");
                break;
            case 5:display(first);
                break;
            default:printf("Invalid choice");
        }
        printf("continue (y/n)");
        fflush(stdin);
        c=getchar();
    }while(c=='y');
}
