#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int repaint(const vector<string>& board, int x, int y) {
    string pattern1[2] = {"WBWBWBWB", "BWBWBWBW"};
    int count1 = 0; // 시작이 W
    int count2 = 0; // 시작이 B

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[x + i][y + j] != pattern1[i % 2][j])
                count1++;
            if (board[x + i][y + j] != pattern1[(i + 1) % 2][j])
                count2++;
        }
    }

    return min(count1, count2);
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> board(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    int result = 64; // 최대 8x8 모두 칠해야 할 수도 있음
    for (int i = 0; i <= N - 8; ++i) {
        for (int j = 0; j <= M - 8; ++j) {
            result = min(result, repaint(board, i, j));
        }
    }

    cout << result << '\n';
    return 0;
}