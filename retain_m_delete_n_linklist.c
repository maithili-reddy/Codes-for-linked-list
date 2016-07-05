/*Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes,
 continue the same till end of the linked list. */

#include<stdio.h>
typedef struct{
int data;
struct node* link;
}node;
void display(node *first){
node *temp;
temp=first;
while(temp){
    printf("%d ",temp->data);
    temp=temp->link;
}
printf("\n");
}
void modify(node *head,int m,int n){
node *temp,*x;
int c=1;
temp=head;
while(temp){
        c=1;
while(c<m&&temp){
    temp=temp->link;
    c++;
}
c=0;
x=temp;
while(c<n&&temp){
    temp=temp->link;
    c++;

}
if(temp)
x->link=temp->link;
else
    x->link=NULL;
if(temp)
temp=temp->link;
}
display(head);
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
    (*first)=temp;
}
main(){
node **first=NULL;
int opt,n,m;
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
printf("Enter the values of m and n\n");
scanf("%d %d",&m,&n);
modify(first,m,n);
}
