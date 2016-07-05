#include<stdio.h>
typedef struct{
int data;
struct node* link;
}node;
void insert(node **first,int d,int n){
node *temp,*x;
x=*first;
temp=(node*)malloc(sizeof(node));
temp->data=d;
if(*first){
while(x){
    if(x->data==n)
        break;
    x=x->link;
}
temp->link=x->link;
x->link=temp;
}
else{
    *first=temp;
    (*first)->link=NULL;
}
}
void display(node *first){
node *x;
x=first;
while(x){
    printf("%d ",x->data);
    x=x->link;
}
}
void del(node **first,int d){
node *x,*temp;
temp=*first;
if((*first)->data==d)
    (*first)=(*first)->link;
else{
x=temp->link;
while(x){
if(x->data==d)
    break;
x=x->link;
temp=temp->link;
}
temp->link=x->link;
free(x);
}
}
node* reverse(node *temp){
node *lead,*middle,*trail;
lead=temp;
middle=NULL;
while(lead){
    trail=middle;
    middle=lead;
    lead=lead->link;
    middle->link=trail;
}
return middle;
}
int main(){
node **first=NULL;
node *m,*temp;

int opt,d,n;
while(1){
    printf("Enter 1.insert 2.del 3.display 4.reverse 5.exit\n");
    scanf("%d",&opt);
    switch(opt){
    case 1: printf("Enter the element to be inserted and after which element\n");
            scanf("%d %d",&d,&n);
            insert(&first,d,n);
            break;
    case 2:printf("Enter the element to be deleted\n");
           scanf("%d",&d);
           del(&first,d);
           break;
    case 3:display(first);
           break;
    case 4:temp=first;
           m=reverse(temp);
           display(m);
           break;
    case 5:exit(1);
    }
}
return 0;
}
