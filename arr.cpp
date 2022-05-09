#include<iostream>

using namespace std;

int main(){
    int arr[100];
    for(int i = 0; i< 100; i++){
        arr[i] = i + 10;
    }
    for(int i = 0; i<100; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
