#include<stdio.h>
#include<stdlib.h>
#define max_size 20
struct stack{
    int a[max_size];
    int top;
};
struct stack*createstack(){
   struct stack*p =(struct stack*)malloc(sizeof(struct stack));
   p->top=-1;
   return p;
}
void push(struct stack* stack,int val){
    if(stack->top==max_size-1){
        printf("stack is full\n");
        return;
    }
    stack->a[++stack->top]=val;
    if(stack->top==-1){
        printf("stack is empty\n");
        return;
    }
    
}
int pop(struct stack *stack){
    if(stack->top==-1){
        printf("stack is empty\n");
        return -1;
    }
    return stack->a[stack->top--];
}
int peek (struct stack*stack){
    if(stack->top==-1){
        printf("stack is empty\n");
        return -1;
    }
    return stack->a[stack->top];
}
int main(){
    struct stack*s=createstack();
    struct stack*s1=createstack();
    push(s,4);
    push(s,5);
    push(s1,1);
    printf("popped %d\n",pop(s));
    printf("peeked %d\n",peek(s1));
    printf("peeked %d",peek(s));
}