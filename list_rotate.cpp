/*
Given a singly linked list, rotate the linked list counter-clockwise by k nodes.
 Where k is a given positive integer.
 For example, if the given linked list is '10->20->30->40->50->60' and 'k is 4',
 the list should be modified to '50->60->10->20->30->40'.
  Assume that k is smaller than the count of nodes in linked list.
*/

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

void list_rotate(listNode **head, int key){
    int i = 1;
    listNode *current = *head , *temp;

    while(i<key && current!=NULL){
        current = current->next;
        i++;
    }
    temp = *head ;
   // cout<<current->data<<" "<<i;          // for testing purpose
    *head = current->next;
    current->next = NULL;
    current = *head ;

    while(current->next!=NULL){
        current= current->next;
    }
    if(current->next==NULL){
        current->next=temp;
    }
}

int main(){

    int x;
    listNode *head;
    head = new listNode;
    head = NULL;

    // creating a linked list  :
    for(int i=1;i<=6;i++)
        head = create_list(i*10,head);

    cout << "\nThe linked list is : \n";
    traversal(head);

    cout << "\nEnter the key  \n";
    cin >> x ;

    list_rotate(&head,x);

     cout << "\nThe linked list after swapping nodes is : \n";
     traversal(head);
    return 0;
}
