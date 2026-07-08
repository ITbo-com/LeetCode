#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
    vector<int> v1(n);
    for(int i=0; i<n;i++){
        cin >> v1[i];
    }

    int mn = 0x7FFFFFFF;
    int sum =0;
    int ed = 0;
    for(int st=0; st<n; st++){

        while(ed < n && v1[ed] + sum < s){
            sum += v1[ed++];
        }
        if(ed == n)
            break;
        
        mn = min(mn, ed-st);
        sum -= v1[st];

    }

    if(mn == 0x7FFFFFFF)   
        cout << 0;
    else
        cout << mn + 1;

    return 0;
}

/*
문제 1. ed++을 하고 sum에 넣어서 이상한 값 더해짐
문제 2. ed가 n일 때 브레이크 되는 거? 근데 이건 어차피 ed가 n이 되버리면 OOB라 상관 없을 듯....
문제 3. 예외 처리 mn=0일 수도
*/