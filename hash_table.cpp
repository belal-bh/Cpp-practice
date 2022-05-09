#include<iostream>
using namespace std;

const int HASH_MAP_SIZE = 3;
const int MAX_KEY_SIZE = 10;

bool mystrcmp(int s1_size, char* s1, int s2_size, char* s2){
    if(s1_size!=s2_size) return false;
    for(int i=0; i<s1_size; i++){
        if(s1[i] != s2[i]) return false;
    }
    return true;
}

struct Node{
    int key_size;
    char* key;
    int data;
    Node* next;
};

Node* create_node(int key_size, char* key, int data){
    Node* node = new Node;
    node->key_size = key_size;
    node->key = key;
    node->data = data;
    node->next = NULL;

    return node;
}

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

    void append(Node* newnode){
        if(head!=NULL){
            struct Node* cur = head;
            while(cur && cur->next){
                cur = cur->next;
            }
            cur->next = newnode;
        }else{
            head = newnode;
        }
    }

    void update(Node* newnode){
        struct Node* cur = head;
        while(cur){
            if(cur->key_size==newnode->key_size && mystrcmp(cur->key_size, cur->key, newnode->key_size, newnode->key)){
                cur->data = newnode->data;
                delete newnode;
                return;
            }
            cur = cur->next;
        }
        // not found
    }

    void print(){
        Node* cur = head;
        while(cur){
            cout<<cur->key<<" : "<<cur->data<<endl;
            cur = cur->next;
        }
    }
};

class Dict{
  public:
    LinkedList* map;

    Dict(){
        map = new LinkedList[HASH_MAP_SIZE];
    }

    int hash_key(int key_size, char* key){
        int x = 0;
        for(int i=0; i<key_size; i++){
            x = (x + key[i] * 37)%HASH_MAP_SIZE;
        }
        cout<<key<<"=="<<x<<endl;
        return x;
    }

    void add(int key_size, char* key,int value){
        int id = hash_key(key_size, key);
        if(!find(key_size, key)){
            map[id].append(create_node(key_size, key, value));
        }else{
            // key exists. so just update data
            map[id].update(create_node(key_size, key, value));
        }
    }

    bool find(int key_size, char* key){
        int id = hash_key(key_size, key);
        Node* cur = map[id].head;
        while(cur){
            if(cur->key_size==key_size && mystrcmp(cur->key_size, cur->key, key_size, key)){
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    Node* get(int key_size, char* key){
        int id = hash_key(key_size, key);
        Node* cur = map[id].head;
        while(cur){
            if(cur->key == key){
                return cur;
            }
            cur = cur->next;
        }
        return NULL;
    }

    void print(){
        for(int i=0; i<HASH_MAP_SIZE; i++){
            if(map[i].head){
                cout<<i<<" : ";
                map[i].print();
            }
        }
    }
};

int main(){
    cout<<"Enter map size: ";
    int n, key_size, data;
    cin>>n;
    Dict map = Dict();
    cout<<"Enter key string size and string then value"<<endl;
    for(int i=0; i<n; i++){
        cin>>key_size;
        char* key = new char[key_size];
        cin>>key;
        cin>>data;

        map.add(key_size, key, data);
    }
    map.print();
    return 0;
}
