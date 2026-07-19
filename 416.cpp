#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
        }
        if (sum % 2 == 1)
            return false;
        sum /= 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;

        for(int i=0 ; i<nums.size(); i++){
            for(int j=sum; j>=nums[i]; j--){
                if(dp[j - nums[i]] == true)
                    dp[j] = true;
            }
        }
        return dp[sum];

    }
};