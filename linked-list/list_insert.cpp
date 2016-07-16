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
void list_insert(int data ,int pos , listNode **head){
    int cur=1;
    listNode *q;
    q = new listNode;
     q->data = data;

    listNode *current;
    current = new listNode;
    current = *head;
    if(pos==1){

      q->next = *head;
      *head = q;
    }
    else{
            while(cur<pos-1 && current->next!=NULL){
              current=current->next;
               cout << "Next ";
               cur++;
            }

            if(current->next==NULL)
            {
                current->next =q;
                q->next =NULL;
                cout << "LAST ";
            }
            else{
                q->next = current->next;
                current->next=q;
                cout << "Center ";

            }
        }
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

    cout << "\nEnter data to be added ";
    cin  >> val;
    cout << "\n Enter the position ";
    cin  >> no;

    list_insert(val, no, &head);

    cout << "list after insertion " ;
    traversal(head);

}


