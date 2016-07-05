/*Given a linked list of co-ordinates where adjacent points either form a vertical line or a horizontal line.
 Delete points from the linked list which are in the middle of a horizontal or vertical line.

 Input:  (0,10)->(1,10)->(5,10)->(7,10)
                                  |
                                (7,5)->(20,5)->(40,5)
Output: Linked List should be changed to following
        (0,10)->(7,10)
                  |
                (7,5)->(40,5)
The given linked list represents a horizontal line from (0,10)
to (7, 10) followed by a vertical line from (7, 10) to (7, 5),
followed by a horizontal line from (7, 5) to (40, 5).

Input:     (2,3)->(4,3)->(6,3)->(10,3)->(12,3)
Output: Linked List should be changed to following
    (2,3)->(12,3)
There is only one vertical line, so all middle points are removed. */


#include<stdio.h>
typedef struct{
int d1;
int d2;
struct node* link;
}node;
void insert(node **first,int d1,int d2){
node *temp,*x;
temp=(node*)malloc(sizeof(node));
temp->d1=d1;
temp->d2=d2;
temp->link=NULL;
if(*first){
x=*first;
while(x->link){
    x=x->link;
}
x->link=temp;
}
else{
    *first=temp;
}
}
void modified(node **head){
node *temp,*temp1,*first;
temp=*head;
temp1=*head;
temp=temp->link;

if(temp->d1==(*head)->d1){

    while(temp&&(temp->d1==(*head)->d1)){
        temp1=temp;
        temp=temp->link;
    }
}
else{

    while(temp&&(temp->d2==(*head)->d2)){
        temp1=temp;
        temp=temp->link;
    }
}
(*head)->link=temp1;
while(temp){

    first=temp1;
    if(temp->d1==(first)->d1){
    while(temp&&(temp->d1==(first)->d1)){
        temp1=temp;
        temp=temp->link;

    }
}
else{
    while(temp&&(temp->d2==(first)->d2)){
        temp1=temp;
        temp=temp->link;

    }
}

first->link=temp1;
}
display(*head);
}
void display(node *first){
node *temp;
temp=first;
while(temp){
    printf("%d ",temp->d1);
    printf("%d ",temp->d2);
    printf("    ");
    temp=temp->link;
}
printf("\n");
}
main(){
    node **first=NULL;
    int opt,d1,d2;
    while(1){
printf("Enter 1.insert 2.display 3.exit\n");
scanf("%d",&opt);
switch(opt){
case 1:printf("Enter d1 and d2\n");
        scanf("%d %d",&d1,&d2);
        insert(&first,d1,d2);
        break;
case 2: display(first);
        break;
case 3:break;
}
if(opt==3)
    break;
}
modified(&first);
}
