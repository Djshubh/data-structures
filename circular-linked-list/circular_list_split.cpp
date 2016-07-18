// Circular linked list implementation : insert at begining.
// middle pointer by size of list
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

void list_split(listNode **head ,listNode **cll1,listNode **cll2){
    listNode *cur= *head,*ptr1;
     *cll1 = *head;
    int listSize = 0,i=0;
    if(*head!=NULL){
        do{
            cur = cur->next;
            listSize++;
        }while(cur->next!=*head);

      //  Reassigning current to head
        cur = *head;
        while(i<listSize/2){
            cur = cur->next;
            i++;
        }
        // copying middle pointer (cur) to cll2
        *cll2 = cur->next;
        cur->next = *cll1;
        // reassigining cur to (head of) cll2 to find end of list
        cur = *cll2;
        while(cur->next!=*head){
            cur= cur->next;
        }
        cur->next = *cll2;
        // cout << (*cll2)->data;

    }
    else
        cout<<"head empty";

}
int main(){

    listNode *list1 = NULL;
    listNode *list2 = NULL;
    listNode *head = NULL;

   for(int i=1;i<7;i++)
        push(&head,i*3-2);

    circular_traverse(head);
   list_split(&head,&list1,&list2);

    circular_traverse(list1);
    circular_traverse(list2);

    return 0;
}
