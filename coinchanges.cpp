#include <iostream>
#include <vector>

using namespace std;

int coinExchange(vector<int> coins, int change) {
    int cents;
    vector<int> coinCount(change+1, 0);
    for(cents = 1; cents <= change; cents++) {
        int minCoin;
        minCoin = cents;
        for(int i=0; i<coins.size(); i++) {
            if(coins[i] > cents) continue;
            if(coinCount[cents-coins[i]]+1 < minCoin) {
                minCoin = coinCount[cents - coins[i]] + 1;
            }
        }
        coinCount[cents] = minCoin;
    }
    return coinCount[change];
}

int main(void) {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int change;
        int numOfCoins;
        cin >> change;
        cin >> numOfCoins;
        vector<int> coins;
        int c;
        for(int j=0; j<numOfCoins; j++) {
            cin >> c;
            coins.push_back(c);
        }
        int res = coinExchange(coins, change);
        cout << res << endl;
    }
}