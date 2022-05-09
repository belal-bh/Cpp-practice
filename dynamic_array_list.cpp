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

    void print(){
        Node* cur = head;
        while(cur){
            cout<<cur->data<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
};

int main(){
    cout<<"Enter array list size: ";
    int n, k, data;
    cin>>n;
    LinkedList* alist = new LinkedList[n];
    cout<<"Enter each list size and elements"<<endl;
    for(int i=0; i<n; i++){
        cin>>k;
        for(int j=0; j<k; j++){
            cin>>data;
            alist[i].append(data);
        }
    }
    for(int i=0; i<n; i++){
        cout<<i<<" : ";
        alist[i].print();
    }
    return 0;
}
