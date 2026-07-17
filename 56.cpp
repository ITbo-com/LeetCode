#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> res;
        for(auto cur : intervals){
            for(int i=cur[0]; i<= cur[1]; i++){
                res.push_back(i);
            }
        }
        sort(res.begin(), res.end());

        vector<vector<int>> ret;

        int i=0;
        while(i<res.size()){
            vector<int> temp;
            temp.push_back(res[i]);
            while(i+1 < res.size() && res[i+1] - res[i] <=1)
                i++;
            temp.push_back(res[i++]);
            ret.push_back(temp);
        }

        return ret;
    }
};