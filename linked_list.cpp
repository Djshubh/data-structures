// inserting in a linked list @ beginning
//  e (insert) -> a -> b  -> c -> d-> null

#include <iostream>

using namespace std;

struct listNode {
    int data;
    listNode *next;
};

listNode *create_list(int dt,listNode *p){
    listNode *q;
    q = new listNode;
    q->data = dt;
    q->next = p;
    return q;
}
int main(){

     int val, choice=1;
     listNode *current;
     current = new listNode;
     current =NULL;
     while(choice){
         cout <<"\n Enter data :";
        cin>>val ;
        current = create_list(val,current);
        cout << " MORE ? 1 or 0 ";
        cin>>choice;

     }

     while(current){
        cout << current->data <<"  ";
        current =current->next;
     }

     delete current;
    return 0;
}

