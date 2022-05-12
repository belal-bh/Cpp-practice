#include<iostream>

using namespace std;

bool check_cycle(int v, int** adj, bool* visited, bool* dfs_called){
    visited[v] = true;
    dfs_called[v] = true;
    for(int i=1; i<=adj[v][0]; i++){
        if(!visited[adj[v][i]]){
            if(check_cycle(adj[v][i], adj, visited, dfs_called)) return true;
        } else if(dfs_called[adj[v][i]]){
            return true;
        }
    }
    dfs_called[v] = false;
    return false;
}

bool is_cyclic(int n, int** adj){
    bool* visited = new bool[n];
    bool* dfs_called = new bool[n];

    for(int i=0; i<n; i++){
        visited[i] = false;
        dfs_called[i] = false;
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            if(check_cycle(i, adj, visited, dfs_called)) return true;
        }
    }
    return false;
}

int main(){
    cout<<"Enter number of nodes:";
    int n, k, x;
    cin>>n;
    int** adj = new int* [n];

    cout<<"Enter adj list size and then corresponding values"<<endl;
    for(int i=0; i<n; i++){
        cout<<i<<" : ";
        cin>>k;
        adj[i] = new int[k+1];
        adj[i][0] = k;
        for(int j=1; j<=k; j++){
            cin>>x;
            adj[i][j] = x;
        }
    }

    for(int i=0; i<n; i++){
        cout<<"["<<i<<"] : ";

        for(int j=1; j<=adj[i][0]; j++){
            cout<<adj[i][j]<<" ";
        }

        cout<<endl;
    }
    cout<<"Is cyclic: "<<is_cyclic(n, adj)<<endl;
    return 0;
}

/*
Test Cases 1:
IN:
9
1 1
1 2
2 3 5
1 4
0
1 4
2 1 7
1 8
1 6

OUT: true

Test Cases 2:
IN:
9
1 1
1 2
2 3 5
1 4
0
1 4
2 1 7
1 8
0

OUT: false

*/
