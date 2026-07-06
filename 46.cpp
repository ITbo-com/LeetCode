#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    vector<int> res1;
    vector<vector<int>> res2;
    vector<bool> used;

    void bt(vector<int>& num, int k){
        if (k== num.size()){
            res2.push_back(res1);
            return;
        }

        for(int i=0; i<num.size(); i++){
            if(used[i] == true)
                continue;
            res1.push_back(num[i]);
            used[i] = true;
            bt(num, k+1);
            res1.pop_back();
            used[i] = false;
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
            used.resize(nums.size(), 0);
            bt(nums, 0);

            return res2;
    }
};