#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp(amount + 1, 0);

        dp[0] = 1;
        for(int j=0; j<coins.size(); j++){
            vector<bool> used(amount+1, false);
            used[0] = true;
            for(int i=0; i<= amount; i++){
                
                if(i-coins[j] >= 0 && dp[i-coins[j]] > 0){
                    dp[i] += dp[i-coins[j]];
                    
                    used[i] = true;
                }
            }
        }

        return dp[amount];
    }
};