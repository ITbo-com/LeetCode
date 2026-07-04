#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q1;
        vector<int> ind(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int>(0));
        for (auto i : prerequisites){
            ind[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }
        for (int i=0; i<numCourses; i++){
            if(ind[i] == 0)
                q1.push(i);
        }
        int cnt =0;

        while(!q1.empty()){

            cnt++;
            int cur = q1.front();
            q1.pop();

            for(int i : adj[cur]){
                ind[i]--;
                if (ind[i]==0)
                    q1.push(i);
            }

        }

        if (cnt == numCourses)
            return true;
        else
            return false;

    }
};