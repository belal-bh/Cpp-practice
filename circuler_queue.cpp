#include<iostream>
using namespace std;

class Queue{
private:
    int* q;
    int front;
    int rear;
    int size;
    int MAX_Q_SIZE;
public:
    Queue(int max_size){
        front = -1;
        rear = -1;
        size = 0;
        MAX_Q_SIZE = max_size;
        q = new int[MAX_Q_SIZE];
    }

    void enqueue(int item){
        if(is_empty()){
            front = rear = 0;
        }else if(is_full()){
            cout<<"Q full! enqueue failed!"<<endl;
            return;
        }else{
            rear = (rear + 1)%MAX_Q_SIZE;
        }
        q[rear] = item;
        size++;
    }
    int dequeue(){
        int x = 0;
        if(is_empty()){
            cout<<"Q empty!! dequeue failed!"<<endl;
        }else if(front==rear){
            x = q[front];
            front = rear = -1;
            size = 0;
        }else{
            x = q[front];
            front = (front+1)%MAX_Q_SIZE;
            size--;
        }
        return x;
    }
    bool is_full(){
        if((rear+1)%MAX_Q_SIZE == front) return true;
        return false;
    }
    bool is_empty(){
        if(front==-1 && rear==-1)return true;
        return false;
    }
    int count(){
        return size;
    }

    void print(){
        cout<<"Q size: "<<count()<<endl;
        if(!is_empty()){
            cout<<"Q => ";
            for(int i=0; i<size; i++){
                cout<<q[(front+i)%MAX_Q_SIZE]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n, x, choice;
    cout<<"Enter maximum Queue size: ";
    cin>>n;
    Queue* q = new Queue(n);
    cout<<"Choices: \n1 = enque, \n0 = dequeue\nothers for exit\n";
    while(true){
        cout<<"Enter choice:";
        cin>>choice;
        if(choice==1){
            // enque
            cin>>x;
            q->enqueue(x);
            q->print();
        }else if(choice==0){
            // dequeue
            q->dequeue();
            q->print();
        }else{
            cout<<"Bye!"<<endl;
            break;
        }
    }
    return 0;
}
