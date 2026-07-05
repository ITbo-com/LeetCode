#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int const INF = 1e9;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for (auto cur : times){
            adj[cur[0]].push_back({cur[2], cur[1]});
        }
        for (int i = 1; i<adj.size(); i++){
            sort(adj[i].begin(), adj[i].end());
        }
        /*
        뭔가 작은 순으로 나열하는 느낌이었는데 까먹어서 sort를 써버림.
        원래는 큐를 그냥 우선순위 큐로 선언하면 됐었다.
        애초에 sort 자체가 아무것도 해줄 수 있는 게 없음. 그냥 내 주변에서 제일 빠른 간선부터 큐에 넣는 거임
        우선순위 큐를 써야 dist(cost + now dist)가 가장 작은 애들부터 갈 수 있음
        즉, 계산이 많이 줄어든다~ sort로 해버리면 아무 의미 없이 bfs마냥 엄청 많이 하게됨
        */

        queue<pair<int,int>> q1;
        vector<int> dist(n+1, INF);
        dist[0]=0;
        dist[k]=0;
        
        q1.push({dist[k], k});

        while(!q1.empty()){
            auto cur = q1.front();
            q1.pop();

            int now = cur.second;
            int now_dist = cur.first;

            if(now_dist > dist[now])
                continue;
            
            for (auto nxt : adj[now]){
                if(nxt.first + now_dist >= dist[nxt.second])
                    continue;
                
                dist[nxt.second] = now_dist + nxt.first;
                q1.push({dist[nxt.second], nxt.second});
            }
        }

        int cnt = 0;
        for(int k : dist){
            if(k == INF)
                return -1;
            cnt = max(cnt, k);
        }

        return cnt;


    }
};