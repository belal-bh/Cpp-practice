#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
  public:
    struct Node* head;
    LinkedList(){
        head = NULL;
    }
    LinkedList(int data){
        head = new Node;
        head->data = data;
        head->next = NULL;
    }

    void append(int data){
        if(head!=NULL){
            struct Node* cur = head;
            while(cur && cur->next){
                cur = cur->next;
            }
            struct Node* newnode = new Node;
            newnode->data = data;
            newnode->next = NULL;
            cur->next = newnode;
        }else{
            head = new Node;
            head->data = data;
            head->next = NULL;
        }
    }
};

int main(){
    LinkedList llist = LinkedList();
    int n, data;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>data;
        llist.append(data);
    }

    struct Node* cur = llist.head;
    while(cur!=NULL){
        cout<<cur->data<<" ";
        cur = cur->next;
    }
    return 0;
}
