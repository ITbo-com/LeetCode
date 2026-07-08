#include<bits/stdc++.h>
using namespace std;

class Solution {

int const INF = 0x7FFFFFFF;

public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        int n = coins.size();
        vector<int> v1(amount+1, INF);

        v1[0] = 0;

        for(int i=1; i<=amount;i++){
            for(int j=0; j<n;j++){
                if(i - coins[j]>=0 && v1[i-coins[j]] != INF){
                    v1[i] = min(v1[i], v1[i-coins[j]] + 1);
                }
            }
        }
        if (v1[amount] == INF)
            return -1;
        else
            return v1[amount];
    }
};