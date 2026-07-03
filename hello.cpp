#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "C++ 환경 설정 성공!" << endl;

    vector<int> v = {5, 2, 8, 1, 9};
    sort(v.begin(), v.end());
    cout << "정렬 결과: ";
    for (int x : v) cout << x << ' ';
    cout << endl;

    return 0;
}
