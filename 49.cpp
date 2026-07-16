#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> m1;

        for (auto cur : strs){
            
            auto curkey = cur;
            sort(curkey.begin(), curkey.end());


            m1[curkey].push_back(cur);
        }
        vector<vector<string>> res;
        for(auto cur : m1){
            res.push_back(cur.second);
        }

        return res;

    }
};