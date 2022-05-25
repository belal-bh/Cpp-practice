// https://youtu.be/xOlhR_2QCXY

#include<iostream>


#define IN(n) cin>>n;
#define OUT(n) cout<<n;
#define OUT_NL(n) cout<<n<<endl;

#define MAX_NCOIN 100
#define MAX_COIN_VAL 500

#define ALLOC_1D_INT(p, n) p = new int[n]
#define ALLOC_2D_INT(p, d1, d2) {p = new int*[d1]; for(int i=0; i<d1; i++) p[i] = new int[d2];}
#define DELLOC_2D_INT(p, d1, d2) {for(int i=0; i<d1; i++) delete[] p[i]; delete[] p;}


using namespace std;

int knapsack(int* coins, int nCoins, int balance){
    if(nCoins == 0 || balance == 0) return 0;

    int** ks;
    int i, j;

    ALLOC_2D_INT(ks, nCoins+1, balance+1);

    for(i = 0; i<=nCoins; i++) ks[i][0] = 0;
    for(i = 0; i<=balance; i++) ks[0][i] = 0;

    for(i=1; i<=nCoins; i++){
        for(j=1; j<=balance; j++){
            if(coins[i-1] > j) ks[i][j] = ks[i-1][j];
            else{
                ks[i][j] = max(ks[i-1][j], coins[i-1]+ks[i-1][j - coins[i-1]]);
            }
        }
    }
    int res = ks[nCoins][balance];

    DELLOC_2D_INT(ks, nCoins+1, balance+1);

    return res;
}

int main(){
    int n, m, sum, res;

    int* coins;

    IN(n);
    while(n--){
        IN(m);
        ALLOC_1D_INT(coins, m);
        sum = 0;
        for(int i=0; i<m; i++){
            IN(coins[i]);
            sum += coins[i];
        }

        res = sum - 2 * knapsack(coins, m, sum/2);

        OUT_NL(res);
    }

    return 0;
}

