#include<iostream>

using namespace std;

int main(){
    int n,m;
    cout<<"Enter 2D array dimensions:";
    cin>>n>>m;
    int num;
    int ** arr_2d = new int*[n];
    for(int i=0; i<n; i++){
        // arr_2d[i] = new int[m]; // working
        int* row = new int[m];
        arr_2d[i] = row;
        for(int j=0; j<m; j++){
            cin>>arr_2d[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr_2d[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
