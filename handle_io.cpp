#include<iostream>
#include<fstream>

#include<sstream> // to use istringstream

using namespace std;
const int MAX_ARR_SIZE = 10000000;

int main(){
    fstream myfile("input.txt");
    // take list of numbers from users
    int n = 0;
    int * nums = new int[MAX_ARR_SIZE];
    int num;
    std::string line;
    int word;
    while(getline(myfile, line, '\n')){
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

    return 0;
}
