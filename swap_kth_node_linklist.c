
/* Given a singly linked list, swap kth node from beginning with kth node from end.
Swapping of data is not allowed, only pointers should be changed.*/
#include<stdio.h>
typedef struct{
int data;
struct node *link;
}node;
int t=0;
void swapk(node *first,int k){
node *temp,*temp1,*u,*v,*a,*b;
node *res1,*res2;
int c,m;
m=t-k;
c=1;
temp=first;
temp1=temp;
printf("swapk\n");
while(c<k&&temp){
    temp1=temp;
    temp=temp->link;
    c++;
}
u=temp1;
res1=temp;
v=temp->link;
while(c<(m+1)&&temp){
    temp1=temp;
    temp=temp->link;
    c++;
}
a=temp1;
b=temp->link;
res2=temp;
printf("u=%d v=%d a=%d b=%d\n",u->data,v->data,a->data,b->data);
printf("\ntotal = %d\n",t);
if(t%2==0){
        if(k==((t/2)+1)){
            a->link=res1;
        res1->link=res2;
        res2->link=v;
        }
    else if(k>((t/2)+1)){
        u->link=res2;
        res2->link=v;
        a->link=res1;
        res1->link=b;
    }
    else if(k==((t/2))){
        u->link=res2;
        res2->link=res1;
        res1->link=b;
    }
    else{
u->link=res2;
res2->link=v;
a->link=res1;
res1->link=b;
}
}
else{
if(k>((t/2)+1)){
        u->link=res2;
        res2->link=v;
        a->link=res1;
        res1->link=b;
    }
else if(k<((t/2)+1)){
u->link=res2;
res2->link=v;
a->link=res1;
res1->link=b;
}
else{}
}
display(first);
}
void insert(node **first,int n){
node *temp,*x;
temp=(node*)malloc(sizeof(node));
temp->data=n;
temp->link=NULL;
if(*first){
    x=*first;
    while(x->link)
        x=x->link;
    x->link=temp;
}
else
    *first=temp;
}
void display(node *first){
node *temp;
temp=first;
while(temp){
    printf("%d ",temp->data);
    temp=temp->link;
}
printf("\n");
}
void len(node *first){
node *temp;
temp=first;
while(temp){
    t++;
    temp=temp->link;
}
}
main(){
node **first=NULL;
int opt,n,k;
while(1){
    printf("Enter 1.insert 2.display 3.exit\n");
    scanf("%d",&opt);
    switch(opt){
    case 1:printf("Enter data\n");
           scanf("%d",&n);
           insert(&first,n);
           break;
    case 2:display(first);
           break;
    case 3:break;
    }
    if(opt==3)
        break;
}
printf("Enter k\n");
scanf("%d",&k);
len(first);
swapk(first,k);
}
