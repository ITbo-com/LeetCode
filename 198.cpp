#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[101][2];
        int tot = nums.size();
        dp[0][0] = 0;
        dp[0][1] = 0;

        for(int i=1; i<= tot; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i-1];
        }

        return max(dp[tot][0], dp[tot][1]);
    }
};