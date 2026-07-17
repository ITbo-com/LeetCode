#include<bits/stdc++.h>

using namespace std;

class Solution {

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ret;

        sort(intervals.begin(), intervals.end());

        for(const auto& cur : intervals){
            if(ret.size() != 0 && cur[0] <= ret.back()[1]){
                ret.back()[1] = max(ret.back()[1], cur[1]);
            }
            else
                ret.push_back(cur);
        }

        return ret;
    }
};