// deleting a node from linked list : as data

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

void list_delete(int data , listNode **head){

    listNode *q;
    q = new listNode;
    int found=0;
    listNode *current;
    current = new listNode;
    current = *head;
    if(current->data == data){
        *head = current->next;
        found = 1;
    }
    while(current!=NULL && found ==0){

        if(current->data == data){
            found =1;
            q->next = current->next;
            delete current;
            break;
        }
        else {
              q = current ;
              current = current->next;
        }
    }

    if(found == 1) cout << "node deleted\n ";
    else           cout << "node not found in the list\n";

}


int main(){

    int val, ctr, no;
    listNode *head;
    head = new listNode;
    head = NULL;
    cout << "\nEnter the list size ";
    cin >> no;
    cout << "enter values : ";
    for(int i = 0; i<no; i++){
        cin >> val;
        head = create_list(val,head);

    }

    traversal(head);

    cout << "\nEnter data to be deleted ";
    cin  >> val;

    list_delete(val, &head);

    cout << "list after deletion " ;
    traversal(head);

}


