#include<stdio.h>
// dynamic_cast lib
#include<stdlib.h>
// create a struct of Llist
struct lnode{
    int data;
    struct lnode* next;
};
// define the name of node
typedef struct lnode node;
// create a haed for store the address of node of struct
node*head=NULL;

// add at begin()
void insertAtbegin(int val){
  node* nn=(node*)malloc(sizeof(node));
  if(nn==NULL){
      printf("Warning out of memory\n");
      return;
  }
  nn->data=val;
  if(head==NULL){
      nn->next=NULL;
      head=nn;
  }
  else{
  nn->next=head;
  head=nn;
  }
  printf("the val insert %d\n",val);
}

// display fun()
void display(){
    if(head==NULL){
        printf("LIST IS EMPTY");
        return;
    }
    else{
        node* temp=head;
        printf("The list are\n");
        while(temp!=NULL){
            printf("%d ",temp->data);

            temp=temp->next;
        }
    }
}
// insert the val in particular position
void insertAtpos(int pos,int val){
    if(pos<0){
        printf("warning invalid position");
        return;
    }
    node* nn=(node*)malloc(sizeof(node));
    node*temp=head;
    
    if(nn==NULL){
        printf("Warning node is NULL");
        return;
    }
    nn->data=val;
    
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
        if(temp==NULL){
            printf("list is EMPTY");
            free(nn);
            return;
        }
    }
    
    nn->next=temp->next;
    temp->next=nn;
}

// del the val at particular position
void deleteAtpos(int pos){
    
    if(head==NULL){
        printf("List is EMPTY");
        return;
    }
    if(pos<0){
        printf("Warning invalid position");
        return;
    }
    
    node*temp=head;
    
    if(pos==0){
        head=head->next;
        printf("val is %d",temp->data);
        free(temp);
        return;
    }
    // it for store the position of prev node
    node* prev;
    
    for(int i=0;i<pos;i++){
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    // display the val is del
    printf("val is %d",temp->data);
    
    // free memory
    free(temp);
}

int main(){
    int choice,val,pos;
    while(1){
    printf("\n----------------------list menu---------------------\n");
    printf("1.insert at beginning\n");
    printf("2.display\n");
    printf("3.insert into particular position\n");
    printf("4.delete into particular position\n");
    printf("5.exit\n");
    printf("-------------------end--------------------------------\n");
    printf("Enter the choice\n");
    scanf("%d",&choice);
    switch(choice){
        
        // add at begin 
        case 1:printf("Enter the val to insert at begin\n");
                scanf("%d",&val);
                insertAtbegin(val);
                break;
                
        // display the val in list
        case 2:display();
                break;
        
        // add at particular position
        case 3:printf("Enter the position\n");
                scanf("%d",&pos);
                
                printf("Enter the value\n");
                scanf("%d",&val);
                if(pos==0){
                    insertAtbegin(val);
                }
                else{
                    insertAtpos(pos,val);
                }
                // insertAtpos(pos,val);
                break;
                
        // delete at particular position
        case 4:printf("Enter the position to del\n");
                scanf("%d",&pos);
                deleteAtpos(pos);
                break;
                
        //exit from the list
        case 5:exit(0);
        
        default :printf("Warning wrong input\n");
        
    }
    }  
}