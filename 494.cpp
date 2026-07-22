#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum =0;
        for(auto cur  : nums){
            sum += cur;
        }
        if(target > sum)
            return 0;
        vector<int> dp(sum*2 + 1, 0);
        
        for(int i=0; i<nums.size(); i++){
            vector<int> dp1(sum*2 + 1, 0);
            vector<int> dp2(sum*2 + 1, 0);

            dp[sum+nums[i]]+=1;
            dp[sum-nums[i]]+=1;

            for(int j=0; j<=sum*2; j++){
                if(j+nums[i] <= sum*2 && dp[j+nums[i]] > 0){
                    if(j==sum)
                        continue;
                    dp1[j] = dp[j+nums[i]];
                }
            }

            for(int j=sum*2; j>=0; j--){
                if (j-nums[i] >= 0 && dp[j-nums[i]] > 0){
                    if(j==sum)
                        continue;
                    dp2[j] = dp[j-nums[i]];
                }
            }
            for(int j=0; j<sum*2+1; j++){
                dp[j] = dp1[j] + dp2[j];
            }

        }
    return dp[target + sum] + 1;


    }
};