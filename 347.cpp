#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        for(auto cur : nums){
            if(m.find(cur) == m.end()){
                m[cur] = 1;
            }
            else{
                m[cur]++;
            }
        }

        priority_queue<pair<int,int>> pq;

        for(auto& cur : m){
            pq.push({cur.second, cur.first});
        }

        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};