
/*This is a C code to separate a given linked list with respect to its alternate nodes.
e.g Given a linked list 10->20->30->40->50, the output generated would be:
10->30->50 and 20->40.*/
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
temp->link=NULL;
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
    temp->link=NULL;
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
void sep(node *first){
node *fir1,*fir2,*temp,*temp1,*tem;
node *x,*m;
fir1=first;
fir2=first->link;
temp=(node*)malloc(sizeof(node));
temp->data=fir1->data;
temp->link=NULL;
x=temp;
tem=(node*)malloc(sizeof(node));
tem->data=fir2->data;
tem->link=NULL;
m=tem;
if(fir1->link){
    fir1=fir1->link;
    fir1=fir1->link;
}
if(fir2->link){
    fir2=fir2->link;
    fir2=fir2->link;
}
while(fir1){
    temp1=(node*)malloc(sizeof(node));
    temp1->data=fir1->data;
    temp1->link=NULL;
    temp->link=temp1;
    if(fir1->link)
        fir1=fir1->link;
        fir1=fir1->link;
temp=temp->link;
}
while(fir2){
    temp1=(node*)malloc(sizeof(node));
    temp1->data=fir2->data;
    temp1->link=NULL;
    tem->link=temp1;
    if(fir2->link)
        fir2=fir2->link;
        fir2=fir2->link;
    tem=tem->link;
}
display(x);
display(m);
}

void merge(node *x,node *m){
node *mer,*me,*temp;
if(x&&m){
  mer=(node*)malloc(sizeof(node));
  if(x->data<m->data)
  {
      mer->data=x->data;
      mer->link=NULL;
      x=x->link;
  }
  else{
    mer->data=m->data;
     mer->link=NULL;
    m=m->link;
  }
  me=mer;
}
while(x&&m){
    temp=(node*)malloc(sizeof(node));
    temp->link=NULL;
    if(x->data<m->data){
        temp->data=x->data;
        x=x->link;
    }
    else{
        temp->data=m->data;
        m=m->link;
    }
    mer->link=temp;
    mer=mer->link;
}
while(x){
    temp=(node*)malloc(sizeof(node));
    temp->data=x->data;
    temp->link=NULL;
    x=x->link;
    mer->link=temp;
    mer=mer->link;
}
while(m){
    temp=(node*)malloc(sizeof(node));
    temp->data=m->data;
    temp->link=NULL;
    m=m->link;
    mer->link=temp;
    mer=mer->link;
}
display(me);
}
main(){
    node **first=NULL;
    int opt,d,n;
    while(1){
        printf("Enter 1.insert 2.display 3.exit\n");
        scanf("%d",&opt);
        switch(opt){
        case 1:printf("Enter the element to be inserted and after which element\n");
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
    sep(first);
}
