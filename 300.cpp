// [재도전] 260722
// v1[i]의 의미를 "i번째를 마지막 원소로 쓰는 LIS의 길이"로 정의하기까지 오래 걸림.
// 이 정의만 잡히면 이중 루프는 따라오는데, 정의를 스스로 세우는 게 어려웠음.
// O(n log n) 이분탐색(lower_bound) 풀이는 따로 연습할 것.

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int tot = nums.size();
        vector<int> v1(tot, 1);
        int Max=1;
        for(int i=1; i<tot; i++){
            for(int j=0; j<i;j++){
                if(nums[i] > nums[j]){
                    v1[i] = max(v1[i], v1[j]+1);
                    Max = max(Max, v1[i]);
                }
            }
        }
        return Max;
    }
};