// Inserting in a linked list at end .
// a -> b  -> c -> d-> null   <- e (insert)

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
void list_insert(int dt,listNode **p){
    listNode *q;
    q = new listNode ;
    listNode *current;
    current = new listNode ;
    current = *p;
    if(*p==NULL)
    {
         q->data = dt;
          q->next = NULL;
          *p = q;
//error
    }
    else{

    while(current->next!=NULL){
        current =current->next;
    }
    q->data = dt;
    q->next = NULL;
    current->next = q;
    }
}

int main(){

    listNode *head;
    head = new listNode;
    head = NULL;
    int val, choice=1;

    while(choice){
         cout <<"\n Enter data :";
        cin>>val ;
        list_insert(val,&head);
        cout << " MORE ? 1 or 0 ";
        cin>>choice;

     }

     while(head){
        cout << head->data <<"  ";
        head =head->next;
     }

delete head;
 return 0;
}
