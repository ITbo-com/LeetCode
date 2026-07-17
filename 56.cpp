#include<bits/stdc++.h>

using namespace std;

class Solution {

    struct Compare{
        bool operator()(const vector<int>& a, const vector<int>& b) const{
            return a[0] < b[0];
        }
    };

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ret;

        sort(intervals.begin(), intervals.end(), Compare());

        for(const auto& cur : intervals){
            bool pass = false;
            for(int i=0; i<ret.size();i++){
                if(cur[1] <= ret[i][1] || cur[0] <= ret[i][1]){
                    ret[i][1] = max(ret[i][1], cur[1]);
                    pass = true;
                    break;
                }
            }
            if(!pass)
                ret.push_back(cur);
        }

        return ret;
    }
};