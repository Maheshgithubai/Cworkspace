#include<stdio.h>
#include<stdlib.h>

struct que{
  int data;
  struct que* next;
//   int first;
};

typedef struct que q;


q*head=NULL;

void enqueue(int val){
   q* nn= (q*)malloc(sizeof(q));
   if(nn==NULL){
       printf("out of std::queue<T> ;");
       return;
   }
//   nn->first=-1;
   nn->data=val;
   nn->next=NULL;
   if(head==NULL)
   {

   head=nn;
//   first++;
   }
   else{
       q*temp=head;
       while(temp->next!=NULL){
           temp=temp->next;
       }
       temp->next=nn;
       
    //   first++;
   }
//   nn->first++;
}
void display(){
    if(head==NULL){
        printf("queue is empty\n");
        return;
    }
    q*temp=head;
    while(temp!=NULL){
    printf("%d->",temp->data);
    temp=temp->next;
    
    }
    printf("NULL\n");
}
void dequeue(){
    if(head==NULL){
        printf("queue is empty");
        return;
    }
    q*temp=head;
    printf("the first value of queue %d\n",temp->data);
    head=head->next;
    // printf("%d",t)
    free(temp);
}
int main(){
    enqueue(5);
    enqueue(8);
    enqueue(1);
    dequeue();
    display();
    // dequeue();
}