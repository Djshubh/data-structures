// sorted insert in a circular linked list
 //  2 -> 3 -> 6 -> 8  --( insert 5 )-- 2 -> 3 -> 5 -> 6 -> 8


 // Circular linked list implementation : insert at begining.
// Using turtle and Hare algorithm.
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
        while(current->next!=*head)
            current = current->next;
        current->next=p;
    }
    else
       p->next = p;

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
        cout<<"\n";
    }
    else
        cout << "list Empty";

}

void sorted_insert(listNode **head,int val){
    listNode *ptr,*cur;
    cur = *head;
    ptr = new listNode;
    ptr->data = val;
    if(*head!=NULL){
        if((*head)->data >val){
            while(cur->next!=*head){
                cur = cur->next;
            }
            ptr->next = *head;
            cur->next = ptr;
            *head =ptr;
        }
        else{
            while(cur->next!= *head && val >= cur->next->data){
                cur = cur->next;
            }

            ptr->next = cur->next;
            cur->next = ptr;
        }


    }
    else {
        ptr->next = ptr;
        *head = ptr;
    }

}

int main(){

    listNode *head = NULL;

   for(int i=7;i>1;i--)
        push(&head,i*3-2);

    circular_traverse(head);

     cout<<"values inserted : 3 , 9, 24 \n";
    sorted_insert(&head,3);
     circular_traverse(head);
     sorted_insert(&head,9);
      circular_traverse(head);
      sorted_insert(&head,24);
     circular_traverse(head);

    return 0;
}


