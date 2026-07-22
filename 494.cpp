// [재도전] 260722
// +/- 분할을 sum(P) = (sum + target) / 2 로 바꾸는 발상이 핵심인데 스스로 못 떠올림.
// 곁들여서 어려웠던 부분:
//   - (sum + target)이 홀수면 정수 부분집합이 없으므로 0 (가지치기)
//   - 원소 0은 부분합을 안 바꾸므로 dp[0]을 따로 2배 (내부 루프는 i>=1이라 안 건드림)

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