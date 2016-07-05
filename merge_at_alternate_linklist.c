
/* This program is to merge linked-list at alternate positions given two linked-lists
e.g Given list1 as 10->20->30->40 and list2 as 15->25->35->45, the output generated will be 10>15->20->25->30->35->40->45 */

#include<stdio.h>
typedef struct{
int data;
struct node* link;
}node;
void merge(node *head1,node *head2){
node *temp,*temp1,*temp2;
temp=head1;
temp1=head1->link;
temp2=head2->link;
temp->link=head2;
temp=temp->link;
while(temp1&&temp2){
    temp->link=temp1;
    temp=temp->link;
    temp1=temp1->link;
    temp->link=temp2;
    if(temp2){
        temp2=temp2->link;

    }
     temp=temp->link;
}

if(temp1){
    temp->link=temp1;
    temp1=temp1->link;
    temp=temp->link;
}
temp->link=NULL;
if(temp2)
    head2=temp2;
    printf("Merged linked list is\n");
display(head1);
}
void insert(node**first,int d){
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
main(){
node **head1=NULL;
node **head2=NULL;
int opt,d;
printf("list1\n");
while(1){
    printf("Enter 1.insert 2,display 3.exit\n");
    scanf("%d",&opt);
    switch(opt){
    case 1:printf("Enter data\n");
           scanf("%d",&d);
           insert(&head1,d);
           break;
    case 2:display(head1);
           break;
    case 3:break;
    }
    if(opt==3)
        break;
}
printf("list2\n");
while(1){
    printf("Enter 1.insert 2,display 3.exit\n");
    scanf("%d",&opt);
    switch(opt){
    case 1:printf("Enter data\n");
           scanf("%d",&d);
           insert(&head2,d);
           break;
    case 2:display(head2);
           break;
    case 3:break;
    }
    if(opt==3)
        break;
}
merge(head1,head2);
}
