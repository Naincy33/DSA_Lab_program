#include<stdio.h>
#include<stdlib.h>

struct Node{
   int data;
   struct Node *next;
};
struct Node *head= NULL, *temp = NULL, * last= NULL, *new_node =NULL;

void create_Node(int val){

   new_node= (struct Node*)malloc(sizeof(struct Node));
   new_node->data= val;
   new_node->next= NULL;
}

void insert_at_first(int val){
   create_Node(val);
       if(head== NULL){
           head = new_node;
       }
       else{
           new_node->next = head;
           head = new_node;
       }
}

void insert_at_end(int val){
    create_Node(val);
      if (head==NULL){
        head = new_node;
      }
      else{
        last= head;
        while(last->next != NULL){
            last= last->next;
        }
        last->next= new_node;
      }
}

void insert_at_position(int val, int pos){
    create_Node(val);
     if (pos == 1 || head == NULL) {
        insert_at_first(val);
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

void display(){
    temp = head;
    while(temp != NULL){
        printf("%d-> ", temp->data);
        temp= temp->next;
    }
    printf("NULL\n");
}

int main(){

   struct Node *prev = NULL;

   insert_at_end(10);
   insert_at_end(45);
   insert_at_first(33);
   insert_at_position(15,2);
   display();

   return 0;
}
