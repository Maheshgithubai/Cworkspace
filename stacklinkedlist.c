#include<stdio.h>
#include<stdlib.h>
struct stack{
    int data;
    struct stack* next;
};
typedef struct stack s;
s*head=NULL;
void push(int val){
    s*nn=(s*)malloc(sizeof(s));
    if(nn==NULL){
        printf("out of stack\n");
        return;
    }
    nn->data=val;
    nn->next=NULL;
    // head=nn;
    if(head==NULL){
        head=nn;
    }
    else{
        s*temp=head;
        nn->next=temp;
        head=nn;
    }
}

void display(){
    if(head==NULL){
        printf("stack is empty\n");
        return;
    }
    else{
        s*temp=head;
        while(temp!=NULL){
            printf("%d<-",temp->data);
            temp=temp->next;
        }
    }
}
void pop(){
    s*temp=head;
    s*prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    printf("popped val is %d\n",temp->data);
    free(temp);
}

int main(){
    push(5);
    push(6);
    push(7);
    
    pop();
    display();
    // peek;
}