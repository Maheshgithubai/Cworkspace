#include<stdio.h>
#include<stdlib.h>
struct lnode{
    int data;
    struct lnode* next;
};
typedef struct lnode node;
node*head=NULL;

void insertAtbegin(int val){
    node* nn=(node*)malloc(sizeof(node));
   
    // node*temp=head;
    nn->data=val;
 
    if(head==NULL){
        nn->next=NULL;
        head=nn;
    }
    else
{
    nn->next=head;
    head=nn;
}
}

void display(){
    if(head==NULL){
        printf("warning list is empty");
        return;
    }
    else{
        node* temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
            
        }
    }
}
void reverse(){
    node*prev=NULL;
    node*current=head;
    node*next=head->next;
    
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head = prev;
}

void append(int val){
    node* nn=(node*)malloc(sizeof(node));
    nn->data=val;
    nn->next=NULL;
    
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
     node* temp=head;
    
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=nn;
    
    
}




int main(){
    int chioce,val;
    while(1){
    printf("\n-------------list menu----------------\n");
    printf("1.insert into begin\n");
    printf("2.display\n");
    printf("3.reverse the list\n");
    printf("4.append\n");
    printf("5.exit\n");
    printf("------------------end-----------------\n");
    printf("Enter the chioce\n");
    scanf("%d",&chioce);
    switch(chioce){
        case 1:printf("Enter the val\n");
        scanf("%d",&val);
        insertAtbegin(val);
        break;
        
        case 2:display();
        break;
        
        case 3:reverse();
        display();
        break;
        
        case 4: printf("Enter the val\n");
        scanf("%d",&val);
        append(val);
        display();
        break;
        
        case 5:exit(0);
        
        default: printf("warning wrong chioce\n");
    }
    }
}