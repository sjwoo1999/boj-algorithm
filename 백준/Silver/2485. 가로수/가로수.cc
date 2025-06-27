#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // for gcd

using namespace std;

// 유클리드 호제법 GCD
int getGCD(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> trees(N);
    for (int i = 0; i < N; ++i) {
        cin >> trees[i];
    }

    // 가로수 간 간격
    vector<int> diffs;
    for (int i = 1; i < N; ++i) {
        diffs.push_back(trees[i] - trees[i - 1]);
    }

    // 간격들의 GCD 구하기
    int gcd = diffs[0];
    for (int i = 1; i < diffs.size(); ++i) {
        gcd = getGCD(gcd, diffs[i]);
    }

    // 전체 길이 / gcd 간격 - 1 사이에 심어야 할 나무 개수
    int total = 0;
    for (int i = 0; i < diffs.size(); ++i) {
        total += (diffs[i] / gcd) - 1;
    }

    cout << total << '\n';
    return 0;
}
