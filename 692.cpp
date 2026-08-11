#include<bits/stdc++.h>

using namespace std;

// top k임을 고려해서, 지금 난 최대힙으로 작성했으나, 최소힙을 k개 유지한 상태로 만들어서 메모리를 약간 절약하는 것도 가능

class Solution {
public:

    struct Compare{
        bool operator()(pair<int, string>p1, pair<int, string>p2){
            if(p1.first == p2.first){
                return p1.second > p2.second;
            }
            return p1.first < p2.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m1;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq1;

        for(auto cur : words){
            m1[cur]++;
        }

        for(auto cur : m1){
            pq1.push({cur.second, cur.first});
        }

        vector<string> res;
        for(int i=0; i<k; i++){
            res.push_back(pq1.top().second);
            pq1.pop();
        }

        return res;
    }
};


