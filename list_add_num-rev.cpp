/*  Add two numbers represented by linked lists
Input:
  First List: 5->6->3  // represents number 365
  Second List: 8->4->2 //  represents number 248
Output
  Resultant list: 3->1->6  // represents number 613
*/

#include <iostream>

using namespace std;

struct listNode {
    int data ;
    listNode *next;
};

listNode *create_list(listNode *head,int dt){
    listNode *p;
    p = new listNode;

    p->data = dt;
    p->next = head;
    head = p;

    return head;
}

listNode* append_sum(listNode *head,int sum){
    listNode *p,*current ;
    p = new listNode;
    current = head;
    p->data = sum;
    p->next = NULL;
    if(head==NULL){
        head = p;
    }else{
    while(current->next!=NULL){
        current= current->next;
    }
        current->next = p;
    }
    return head;
}

listNode *add_lists(listNode **l1,listNode **l2){
    listNode *p = *l1,*q=*l2;
    listNode *rst;
    rst =new listNode;
    rst = NULL;
    int carry= 0,sum=0,x=0,y=0;
       while(p!=NULL || q!=NULL ){
             if(p!=NULL){ x = p->data; }
             else { x = 0; }
             if(q!=NULL){ y = q->data; }
             else{ y = 0;}

            sum = x+y+carry;
            cout <<x<<","<<y<<"  ";
            if(sum>=10){
                carry = 1;
                sum = sum%10;
            }else{
                carry = 0;
            }
               rst =  append_sum(rst,sum);
             if(p!=NULL) p = p->next;
             if(q!=NULL) q = q->next;
       }

       if(carry==1){    rst =  append_sum(rst,1);
       }
       return rst;
}

void traverse(listNode *head){
    while(head!=NULL){
        cout << head->data <<" ";
        head = head->next;
    }
}
int main(){

    int val1,val2;
    listNode *list1,*list2,*result;
    list1 = new listNode;
    list1 = NULL;

    list2 = new listNode;
    list2 = NULL;

    list1 = create_list(list1,3);
    list1 = create_list(list1,6);
    list1 = create_list(list1,5);

    list2 = create_list(list2,2);
    list2 = create_list(list2,4);
    list2 = create_list(list2,8);
     traverse(list1);
     cout << "\n";
      traverse(list2);
    cout << "\n";
    cout << "SUM OF LISTS IS :";


    result = new listNode;
    //result = NULL;

    result = add_lists(&list1,&list2);
    cout<<"\n";
    traverse(result);
    return 0;
}
