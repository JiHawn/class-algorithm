#include <iostream>
#include <vector>

using namespace std;

int countCointExchanges(vector<int> coins, int change) {
    int N[11][1001] = {0};
    for(int i=1; i<=coins.size(); i++) {
        N[i][0] = 1;
    }
    for(int i=1; i<=change; i++) {
        N[0][i] = 0;
    }
    
    int num;
    for(int n=1; n<=coins.size(); n++) { // coins index는 항상 n-1
        for(int k=1; k<=change; k++) {
            num = N[n-1][k];
            if(k - coins[n-1] >= 0)
                num += N[n][k-coins[n-1]];
            N[n][k] = num;
        }
    }
    return N[coins.size()][change];
}

int main (void) {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int change;
        int numOfCoins;
        cin >> change;
        cin >> numOfCoins;
        vector<int> coins;
        for(int j=0; j<numOfCoins; j++) {
            int coin;
            cin >> coin;
            coins.push_back(coin);
        }
        int res = countCointExchanges(coins, change);
        cout << res << endl;
    }
}