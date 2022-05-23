/*
Using 2D dynamic array and input with undefined size of numbers...test
Link: https://codeforces.com/problemset/problem/231/A
Status: succes
*/

#include <iostream>
#include<sstream>
using namespace std;

int main(){
    int a,b,c,k = 0, j = 0, n = 0;
    std::cin>>a; // it will not take '\n'...so next we need to use cin.get() to clear this '\n'
    cin.get(); // important...it will take '\n'...so that next getline work properly
    int** nums_2d = new int*[a];
    int num;
    int i = 0;
    std::string line;
    while(getline(cin, line, '\n')){
        std::istringstream ss(line);
        int * row = new int[3];
        if(!row){
            cout<<"Memory error"<<endl;
        }
        // nums_2d[i] = new int[3];
        nums_2d[i] = row;
        // cout<<line<<endl;
        j = 0;
        while(ss>>num){
            nums_2d[i][j++] = num;
            // cout<<num<<" "<<nums_2d[i][j-1]<<", ";
        }
        // cout<<endl;
        i++;
    }
    n = i;
    /*
    while(std::cin>>nums[i]){
        if((i+1)%3==0){
            if((nums[i-2]+nums[i-1]+nums[i])> 1)k++;
        }
        i++;
    };
    */
    // cout<<"Showing 2d arr"<<endl;
    // cout<<"n = "<<n<<" i = "<<i<<endl;
    for(int i = 0; i<n; i++){
        // cout<<i<<" : "<<nums_2d[i][0]<<" "<<nums_2d[i][1]<<" "<<nums_2d[i][2]<<" sum = "<<(nums_2d[i][0] + nums_2d[i][1] + nums_2d[i][2])<<endl;
        if((nums_2d[i][0] + nums_2d[i][1] + nums_2d[i][2]) > 1) k++;
    }
    std::cout<<k;
    return 0;
}
