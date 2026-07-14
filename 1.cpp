#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um1;
        for(int i=0; i<nums.size(); i++){
            if(um1.find(target - nums[i]) != um1.end()){
                return {i, um1[target-nums[i]]};
            }
            um1[nums[i]] = i;
        }
        return {};
    }
};