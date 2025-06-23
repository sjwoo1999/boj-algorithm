#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false); // 입출력 속도 향상
    cin.tie(nullptr); // cin과 cout 분리

    int N, M;
    cin >> N >> M;

    unordered_set<string> S;
    string input;

    for (int i = 0; i < N; ++i) {
        cin >> input;
        S.insert(input); // 집합에 삽입
    }

    int count = 0;

    for (int i = 0; i < M; ++i) {
        cin >> input;
        if (S.find(input) != S.end()) {
            ++count; // 집합에 포함돼 있으면 카운트 증가
        }
    }

    cout << count << '\n';

    return 0;
}