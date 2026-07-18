#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 0)
            return 0;
        vector<int> dp(nums.size(), 1);
        int res=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] - nums[i-1] == 1)
                dp[i] = dp[i-1] +1;
            else if (nums[i] == nums[i-1])
                dp[i] = dp[i-1];
            res = max(res, dp[i]);
        }
        return res;
    }
};