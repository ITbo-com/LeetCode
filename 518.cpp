# include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);

        dp[0] = 1;
        for(int j=0; j<coins.size(); j++){
            for(int i=0; i<= amount; i++){
                if(i-coins[j] >= 0 && dp[i-coins[j]] > 0){
                    if (dp[i] == dp[i-coins[j]])
                        dp[i] += dp[i-coins[j]]+1;
                    else
                        dp[i] += dp[i-coins[j]];
                }
            }
        }

        return max(0, dp[amount]==1? 1:dp[amount] - 1);
    }
};