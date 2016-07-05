/*Given a linked list, reverse alternate nodes and append them to end of list.*/

#include<stdio.h>
typedef struct{
int data;
struct node* link;
}node;
node* reverse(node *lead){
node *middle,*trail;
middle=NULL;
printf("reverse\n");
while(lead){
    trail=middle;
    middle=lead;
    lead=lead->link;
    middle->link=trail;
}
return middle;
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
void display(node *first){
node *temp;
temp=first;
while(temp){
    printf("%d ",temp->data);
    temp=temp->link;
}
printf("\n");
}
void append(node **first){
node *head1,*head2,*temp1,*temp2;
head1=(*first);
head2=(*first)->link;
temp1=head1;
temp2=head2;
printf("in append func\n");
while(temp1&&temp2){
        printf("in while\n");
    temp1->link=temp2->link;
    if(temp1->link)
    temp1=temp1->link;
    if(temp1)
        {temp2->link=temp1->link;
    temp2=temp2->link;
        }
}
printf("out\n");
head2=reverse(head2);
temp1->link=head2;
display(head1);

}
main(){
node **first=NULL;
int opt,d;
while(1){
    printf("Enter 1.insert 2.display 3.exit\n");
    scanf("%d",&opt);
    switch(opt){
    case 1:printf("Enter the data\n");
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
append(&first);
}
