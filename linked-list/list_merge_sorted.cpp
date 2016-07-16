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

listNode* merge_list(listNode *x,listNode *y){
   listNode *head,*q,*p;
   q = new listNode;
   q = NULL;
   head = new listNode;
   while(x!=NULL && y!=NULL){
        // intializing a new node to be added.
       // listNode *p;
       // p = new listNode;
        if(x->data < y->data){
           p = x;
           x= x->next;
        }
        else {
            p = y;
            y = y->next;
        }
        if(q == NULL){
           q = head = p;   // for head position.
        }else {
        // for postions other than head.
            q->next = p;
            q = q->next;
        }
   }

   return head;
}

int main(){

    int x,y;
    listNode *list1,*list2,*head;
    list1 = new listNode;
     list1 = NULL;
    list2 = new listNode;
     list2 = NULL;

    head = new listNode;
    head = NULL;

    // creating a linked list  :
    for(int i=9;i>=1;i--)
        list1 = create_list(i*4,list1);

    for(int i=8;i>=1;i--)
        list2 = create_list(i*5-4,list2);

    cout << "\n Two linked list are : \n";
    traversal(list1);
    cout << "\n";
    traversal(list2);
    cout << "\n Merged linked list  : \n";
    head = merge_list(list1,list2);
    traversal(head);


    return 0;
}
