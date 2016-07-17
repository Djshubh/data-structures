// Circular linked list implementation : Insert at begining and traversal.

#include <iostream>

using namespace std;

struct listNode{
    int data ;
    listNode* next;
};

void push(listNode **head,int val){
    listNode *p,*current=*head;
    p = new listNode;

    p->data = val;
    p->next = *head;
    if(*head!=NULL){
         cout <<"hi ";
        while(current->next!=*head)
            current = current->next;

        current->next=p;

    }
    else {
       cout << "NULL ";
       p->next = p;
    }

     *head = p;
}

void circular_traverse(listNode *head){
    listNode *current;
    current = head;

    if(head!=NULL){
        do{
            cout << " -> "<<current->data;
            current = current->next;

        }while(current!=head);
    }
    else{
        cout << "list Empty";
    }
}
int main(){

    listNode *head = NULL;
    push(&head,3);
   push(&head,5);
    push(&head,6);
    push(&head,8);

    circular_traverse(head);

    return 0;
}
