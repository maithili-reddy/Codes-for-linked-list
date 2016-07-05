
/* Given a linked list and two keys in it, swap nodes for two given keys.
   Nodes should be swapped by changing links. */
#include<stdio.h>
typedef struct{
int data;
struct node *link;
}node;
void insert(node **first,int n){
node *temp,*temp1;
temp1=(node*)malloc(sizeof(node));
temp1->data=n;
temp1->link=NULL;
if(*first){
    temp=*first;
    while(temp->link)
        temp=temp->link;
    temp->link=temp1;
}
else
    *first=temp1;
}
void display(node *first){
node *temp;
temp=first;
while(temp){
    printf("%d ",temp->data);
    temp=temp->link;
}
}
void swap(node **first,int a,int b){
node *u=NULL,*v=NULL,*x=NULL,*y=NULL,*p=NULL,*q=NULL;
node *temp;
temp=*first;
while(temp && (temp->data!=a)){
    u=temp;
    temp=temp->link;
}
p=temp;
v=temp->link;
temp=*first;
while(temp && (temp->data!=b)){
    x=temp;
    temp=temp->link;
}
q=temp;
y=temp->link;
if(u){
if(p->data==x->data && q->data==v->data){
  u->link=q;
  q->link=p;
  p->link=y;
}
else{
u->link=q;
q->link=v;
x->link=p;
p->link=y;
}
}
else{
    *first=q;
    q->link=v;
    x->link=p;
    p->link=y;
}
display(*first);
}
int main(){
node *first=NULL;
int ch,n,a,b;
while(1){
    printf("Enter 1.insert 2.display 3.swap 4.exit\n");
    scanf("%d",&ch);
    switch(ch){
case 1: printf("Enter the data\n");
        scanf("%d",&n);
        insert(&first,n);
        break;
case 2:display(first);
       break;
case 3:printf("Enter the two nodes to be swaped\n");
       scanf("%d %d",&a,&b);
       swap(&first,a,b);
       break;
case 4:break;
    }
    if(ch==4)
        break;
}
}
