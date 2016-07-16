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

void node_swap(listNode **head,int x,int y){

     listNode *curX = *head,*pX = NULL;

        while(curX!=NULL && curX->data!=x){
            pX = curX;
            curX = curX->next;
        }

          listNode *curY = *head,*pY = NULL;

        while(curY!=NULL && curY->data!=y){
            pY = curY;
            curY = curY->next;
        }
          listNode *temp;
        if(curX->data==x && curY->data==y){

       if(pX!=NULL) {   pX->next = curY;
            }
            else {           *head = curY;
            }

       if(pY!=NULL){     pY->next = curX;
            }
            else{            *head = curX;
            }

            temp = curX->next;
            curX ->next = curY->next;
            curY->next = temp;

        }

    //}
}
int main(){

    int x,y;
    listNode *head;
    head = new listNode;
    head = NULL;

    // creating a linked list  :
    for(int i=1;i<=6;i++)
        head = create_list(i*2,head);

    cout << "\nThe linked list is : \n";
    traversal(head);

    cout << "\nEnter the datas to be swapped \n";
    cin >> x >> y;

    node_swap(&head,x,y);

     cout << "\nThe linked list after swapping nodes is : \n";
     traversal(head);
    return 0;
}
