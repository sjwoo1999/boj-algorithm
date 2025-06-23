#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, num;
    unordered_map<int, int> card_count;

    // N개의 숫자 카드 입력
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        card_count[num]++;
    }

    // M개의 찾고자 하는 숫자 입력
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> num;
        cout << card_count[num] << ' ';
    }

    return 0;
}
