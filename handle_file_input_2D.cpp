#include<iostream>
#include<fstream>

#include<sstream> // to use istringstream

using namespace std;
const int MAX_ARR_SIZE = 100;
const int MAX_ARR_ROW_SIZE = 100;

int main(){
    fstream inFile("input_2d.txt", ios_base::in);
    int n = 0, m = 0, i=0, j=0, p=0;
    int ** nums_2d = new int*[MAX_ARR_SIZE];
    int * nums = new int[MAX_ARR_SIZE];
    std::string line;
    int word;
    if(inFile.is_open()){
        while(getline(inFile, line, '\n')){
            // cout<<line<<endl;
            std::istringstream ss(line);
            nums_2d[i] = new int[10];
            j = 0;
            // cout<<i<<endl;
            while(ss>>word){
                nums_2d[i][j] = word;
                nums[p++] = word;
                // cout<<word<<" "<<nums_2d[i][j]<<" ";
                j++;
            }
            i++;
        }

        n = i;
        m = j;
    }else{
        cout<<"file cannot be opened"<<endl;
    }

    // close the file
    inFile.close();


    cout<<"2D Array Dimensions: "<<n<<" x "<<m<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<nums_2d[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Flatten 1D array: ";
    for(int i = 0; i<p; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
