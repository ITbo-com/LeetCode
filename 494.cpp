#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum =0;
        for(auto cur  : nums)
            sum += cur;

        if((sum+target)%2 == 1 || abs(target) > sum)
            return 0;

        int temp = (sum+target)/2;

        vector<int> dp(temp+1);
        dp[0]=1;
        for(int j=0; j<nums.size(); j++){
            if(nums[j] == 0){
                dp[0] *=2;
            }
            for(int i=temp; i>=1; i--){
                if(i-nums[j] >= 0 && dp[i-nums[j]] > 0)
                    dp[i] += dp[i-nums[j]];
            }
        }
        return dp[temp];
    }
};