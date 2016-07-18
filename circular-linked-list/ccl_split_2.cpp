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

void list_split(listNode **head ,listNode **cll1,listNode **cll2){
    listNode *ptr1,*ptr2;
    ptr1=ptr2 =*head;
     int i=1;
    if(*head!=NULL){
        while(ptr2->next!=*head){

            ptr2 = ptr2->next;
            if(i%2==0){  ptr1 =ptr1->next;}
            i++;
           //   cout <<ptr1->data <<" "<<ptr2->data <<endl;
        }
        // copy head pointer to list1
        *cll1 = *head;
        // set head pointer of list2
        *cll2 = ptr1->next;
        // pointing middle pointer of head to list1 header
        ptr1->next = *cll1;
        //pointing end pointer of head to list2 header
        ptr2->next = *cll2;
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
    cout << "Initial list :";
    circular_traverse(head);
   list_split(&head,&list1,&list2);
    cout << "Lists after splits:\n";
    circular_traverse(list1);
    circular_traverse(list2);

    return 0;
}
