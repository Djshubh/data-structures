#include <iostream>

using namespace std;

struct listNode {
    int data ;
    listNode *next;
};

void traversal(listNode *current){
 while(current){
        cout << current->data <<"  ";
        current =current->next;
     }
 }

listNode *create_list(int dt,listNode *p){
    listNode *q;
    q = new listNode;
    q->data = dt;
    q->next = p;
    return q;
}

void list_reverse(listNode **head){

    listNode *current,*p,*rev;
   // p = new listNode;
    current = *head;
    rev = new listNode;
    rev = NULL;

    while(current!=NULL){

        p = current;
        current = current->next;
        p->next = rev;
        rev= p;
    }
    *head = rev;
}
int main(){

    listNode *head;
    head = new listNode;
    head = NULL;

    // creating a linked list  :
    for(int i=1;i<=6;i++)
        head = create_list(i*2,head);

    cout << "\nThe linked list is : \n";
    traversal(head);

    list_reverse(&head);

     cout << "\nThe linked list after reversing nodes is : \n";
     traversal(head);
    return 0;
}
