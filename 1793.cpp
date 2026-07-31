#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int tot = nums.size();
        int i=k, j=k;
        priority_queue<int> pq;
        int mn = nums[k];

        for(int t = 0; t < tot; t++){

            int res = (j - i + 1) * mn;
            pq.push(res);

            if(i != 0 && (j == tot -1 || nums[i-1] > nums[j + 1])){
                i--;
                mn = min(mn, nums[i]);
            }
            else if (j != tot - 1 && (i == 0 || nums[i-1] <= nums[j + 1])){
                j++;
                mn = min(mn, nums[j]);
            }

        }
        return pq.top();
    }
};