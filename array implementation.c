#include<stdio.h>
#include<stdlib.h>
#define maxsize 50
int a[maxsize];
int size=0;

void display(){
    if(size==0){
        printf("array is empty\n");
    }
    for(int i=0;i<size;i++){
        printf("%d\n",a[i]);
    }
}

void insertval(int pos,int val){
    for(int i=size-1;i>=pos;i--){
        a[i+1]=a[i];
    }
    a[pos]=val;
    size++;
    
    printf("the insert value %d and%d\n",pos,val);
}

void deleteval(int pos){
    int del=a[pos];
    for(int i=pos;i<size;i++){
        a[i]=a[i+1];
    }
    size--;
    printf("the deleteval is %d  and %d\n",del,pos);
}
int main(){

int choice,val,pos;

while(1){
printf("=============================array=============================\n");
printf("1.add at end\n");
printf("2.insert at pos\n");
printf("3.delete at pos\n");
printf("4.dispaly\n");
printf("5.exit\n");
printf("==========================end============================\n");

printf("enter the choice:\n");
scanf("%d",&choice);

switch(choice){
    // enter val to insert into end of array
    case 1:printf("enter the value\n");
            scanf("%d",&val);
            a[size++]=val;
            break;
    
    // insert val into particular position
    case 2:if(size==maxsize){
        printf("array is full\n");
        break;
    }
    printf("enter the pos:\n");
    scanf("%d",&pos);
    
    if(pos<0||pos>size){
        printf("Invalid [[pos]]\n");
        break;
    }
    printf("enter the val:\n");
    scanf("%d",&val);
    
    insertval(pos,val);
    break;
    
    // delete the val in the array from given poosition
    case 3:
    if(size==0)
    {
        printf("array is empty\n");
        break;
    }
    printf("enter the pos:\n");
    scanf("%d",&pos);
    
    if(pos<0||pos>=size){
        printf("WARNING INVAILD\n");
        break;
    }
    deleteval(pos);
    break;
    
    // dispaly
    case 4:display();
        break;
    // exists array
    case 5: exit(0);
    default: printf("WARNING wrong INPUT\n");
    }
} 
}
    