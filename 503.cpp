#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int tot = nums.size();
        vector<int> ans(tot, -1);

        for(int i=0; i<tot; i++){
            int j = i+1;
            while(true){
                if (j==tot)
                    j=0;
                if(j==i)
                    break;
                if(nums[j] > nums[i]){
                    ans[i]= nums[j];
                    break;
                }
                
                j++;
            }

        }

        return ans;
    }
};