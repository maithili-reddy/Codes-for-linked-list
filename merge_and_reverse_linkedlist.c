
/* This is a code to merge two given linked lists and finally reverse the merged linked-list.
e.g list1 is: 10->20->30 and list2 is: 40->50->60.The the merged linked list will be 10->20->30->40->50->60.
And finally the reverse of the linked list will be 60->50->40->30->20->10.

NOTE: Please enter 0 for the very first element.That is for 1.Enter the element and after which element to be entered,then
Enter 10 0 as input if your first element is 10.*/
#include<stdio.h>
typedef struct node* listptr;
typedef struct{
   int data;
   listptr link;
}node;
void insert(listptr *first,int d,int n){
    node *temp,*x;
    temp=(node*)malloc(1*sizeof(node));
    temp->data=d;
    temp->link=NULL;
    x=*first;
if(*first){
while(x->data!=n){
    x=x->link;
}
temp->link=x->link;
x->link=temp;
}
else{
temp->link=NULL;
*first=temp;
}
}
node* reverse(node *first){
node *middle,*trail,*lead;
lead=first;
middle=NULL;
while(lead){
    trail=middle;
    middle=lead;
    lead=lead->link;
    middle->link=trail;
}
return middle;
}
void display(node *first){
    node *temp;
    temp=first;
    while(temp){
        printf("%d ",(temp)->data);
        temp=(temp)->link;
    }
}
void merge(node **first,node **fir){
node *temp,*temp1,*temp2,*m;

if((*first)&&(*fir)){
   temp=(node*)malloc(sizeof(node));
    if((((*first)->data)<((*fir)->data))){
       temp->data=(*first)->data;
       temp->link=NULL;
       (*first)=(*first)->link;
       }
       else{
        temp->data=(*fir)->data;
        temp->link=NULL;
       (*fir)=(*fir)->link;
       }
}
temp1=temp;
while((*first)&&(*fir)){
        temp2=(node*)malloc(sizeof(node));
    if((((*first)->data)<((*fir)->data))){
       temp2->data=(*first)->data;
       temp2->link=NULL;
       (*first)=(*first)->link;
       }
       else{
        temp2->data=(*fir)->data;
        temp2->link=NULL;
       (*fir)=(*fir)->link;
       }
       temp->link=temp2;
       temp=temp->link;
}
if(*first){
    while(*first){
        temp2=(node*)malloc(sizeof(node));
        temp2->data=(*first)->data;
         temp2->link=NULL;
        printf("%d ",(*first)->data);
        temp->link=temp2;
        temp=temp->link;
        (*first)=(*first)->link;
    }
}
if(*fir){
    while(*fir){
        temp2=(node*)malloc(sizeof(node));
        temp2->data=(*fir)->data;
        temp2->link=NULL;
         temp->link=temp2;
        temp=temp->link;
        (*fir)=(*fir)->link;
    }
}
printf("After merging the two linked lists\n");
display(temp1);
m=reverse(temp1);
printf("\nAfter reversing the merged linked-list\n");
display(m);
}
int main(){
    int opt,d,n;
listptr *first=NULL,*fir=NULL,*m;
printf("Enter for list1\n");
while(1){
    printf("Enter 1.insert1 2.display 3.exit\n");
    scanf("%d",&opt);
    switch(opt){
    case 1:printf("Enter the element and after which element\n");
           scanf("%d %d",&d,&n);
           insert(&first,d,n);
           break;
    case 2:display(first);
           break;
    case 3:break;
    }
    if(opt==3)
    break;
}
printf("Enter for list2\n");
while(1){
    printf("Enter 1.insert2 2.display 3.exit\n");
    scanf("%d",&opt);
    switch(opt){
    case 1:printf("Enter the element and after which element\n");
           scanf("%d %d",&d,&n);
           insert(&fir,d,n);
           break;
    case 2:display(fir);
           break;
    case 3:break;
    }
    if(opt==3)
    break;
}
merge(&first,&fir);
return 0;
}
