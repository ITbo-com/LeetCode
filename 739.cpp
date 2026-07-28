#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int tot = temperatures.size();
        vector<int> ans(tot, 0);
        stack<int> s1;

        for(int i=0; i<tot; i++){
            while(!s1.empty() && temperatures[s1.top()] < temperatures[i]){
                ans[s1.top()] = i - s1.top();
                s1.pop();
            }
            s1.push(i);
        }

        return ans;
    }
};


/* (중복된 것 같은 걸 뺀 코드. 시간 더 짧아짐. 여기서 gemini랑 얘기하다가 중간에 틀린 코드 바꾸면서 int j,k 뺀 거까지 위에가 최종)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int tot = temperatures.size();
        vector<int> ans(tot, 0);
        stack<int> s1;

        for(int i=0; i<tot; i++){
            int j = i - 1;
            int k = 1;
            while(!s1.empty() && temperatures[s1.top()] < temperatures[i]){
                ans[s1.top()] = i - s1.top();
                s1.pop();
            }
            s1.push(i);
        }

        return ans;
    }
};
*/


/* 1차 제출 (같은 값일 때 판단 하는 걸 잊은 것 빼곤 잘 했음. 이건 수정 후 정답 코드)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int tot = temperatures.size();
        vector<int> ans(tot, 0);
        stack<int> s1;

        for(int i=0; i<tot; i++){
            if(s1.empty() || temperatures[s1.top()] >= temperatures[i]){
                s1.push(i);
            }
            else{
                int j = i - 1;
                int k = 1;
                while(!s1.empty() && temperatures[s1.top()] < temperatures[i]){
                    ans[s1.top()] = i - s1.top();
                    s1.pop();
                }
                s1.push(i);
            }
        }

        return ans;
    }
};
*/