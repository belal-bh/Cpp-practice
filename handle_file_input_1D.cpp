#include<iostream>
#include<fstream>

#include<sstream> // to use istringstream

using namespace std;
const int MAX_ARR_SIZE = 10000000;

int main(){
    // FIRST APPROACH
    cout<<"FIRST APPROACH\n";
    fstream inFile_1("input.txt", ios_base::in);

    int n = 0;
    int * nums = new int[MAX_ARR_SIZE];
    std::string line;
    int word;
    if(inFile_1.is_open()){
        while(getline(inFile_1, line, '\n')){
            std::istringstream ss(line);
            while(ss>>word){
                nums[n++] = word;
            }
        }
    }else{
        cout<<"file cannot be opened"<<endl;
    }

    cout<<"Total numbers: "<<n<<endl;
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    inFile_1.close();


    // SECOND APPROACH
    cout<<"SECOND APPROACH\n";
    fstream inFile_2("input.txt", ios_base::in);
    int num;
    n = 0;
    if(inFile_2.is_open()){
        while(inFile_2>>nums[n++]);
    }else{
        cout<<"file cannot be opened"<<endl;
    }

    cout<<"Total numbers: "<<n<<endl;
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;

    inFile_2.close();

    return 0;
}
