
/* This is a code to swap linked list pairwise.That is,if the linked list is 1->2->3->4->5->6->7 then the function should change
 it to 2->1->4->3->6->5->7, and if the linked list is 1->2->3->4->5->6 then the function should change it to 2->1->4->3->6->5 */

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
void insert(node **first,int d){
node *temp,*x;
temp=(node*)malloc(sizeof(node));
temp->data=d;
temp->link=NULL;
if(*first){
    x=*first;
    while(x->link)
        x=x->link;
x->link=temp;
}
else{
    (*first)=temp;
}
}
void sep(node **head1){
node *temp1,*temp2,*head2;
temp1=*head1;
temp2=(*head1)->link;
head2=temp2;
while(temp1&&temp2){
    temp1->link=temp2->link;
    temp1=temp1->link;
    if(temp1){
        temp2->link=temp1->link;
        temp2=temp2->link;
    }
}
if(temp1)
temp1->link=NULL;
display(*head1);
display(head2);
swap(head2,*head1);
}
void swap(node *head1,node *head2){
node *temp1,*temp2,*temp;
temp=head2;
temp1=head1->link;
head1->link=temp;

temp2=head2->link;
while(temp&&temp1&&temp2){
    temp->link=temp1;
    temp1=temp1->link;
    temp=temp->link;
    temp->link=temp2;
    temp=temp->link;
    temp2=temp2->link;
}
if(temp1){
    temp->link=temp1;
    temp=temp->link;
}
if(temp2){
    temp->link=temp2;
     temp=temp->link;
}
temp->link=NULL;
display(head1);
}

int main(){
node **first=NULL;
int opt,d;
while(1){
    printf("Enter 1.insert 2.display 3.exit\n");
    scanf("%d",&opt);
    switch(opt){
    case 1:printf("Enter data\n");
           scanf("%d",&d);
           insert(&first,d);
           break;
    case 2:display(first);
           break;
    case 3:break;
    }
    if(opt==3)
        break;
}
sep(&first);
return 0;
}
