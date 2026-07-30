#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int tot = nums.size();
        vector<int> pr(tot*2);
        for(int i=0; i<tot; i++){
            pr[i] = nums[i];
            pr[i+tot] = nums[i];
        }

        vector<int> ans(tot, -1);
        stack<int> s1;

        for(int i=0; i<tot * 2; i++){
            
            while(!s1.empty() && pr[i] > pr[s1.top()]){
                if(ans[s1.top()%tot] == -1){
                    ans[s1.top() % tot] = pr[i];
                }
                s1.pop();
            }

            s1.push(i);

        }

        return ans;
    }
};