#include<iostream>
#include<sstream> // istringstream

using namespace std;
const int MAX_ARR_SIZE = 10000000;

int main(){
    // FIRST APPROACH: line by line
    cout<<"FIRST APPROACH\n";
    int n = 0;
    int * nums = new int[MAX_ARR_SIZE];
    std::string line;
    int word;

    while(getline(cin, line, '\n')){
        // cout<<line<<endl;
        std::istringstream ss(line);
        while(ss>>word){
            nums[n++] = word;
        }
    }

    cout<<"Total numbers: "<<n<<endl;
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;


    // SECOND APPROACH: all numbers until end
    cout<<"SECOND APPROACH\n";
    int num;
    n = 0;

    while(cin>>nums[n++]);

    cout<<"Total numbers: "<<n<<endl;
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    return 0;
}

