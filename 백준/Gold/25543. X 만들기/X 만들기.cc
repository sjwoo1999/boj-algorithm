#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    ll x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Point> pts(N);
    for (int i = 0; i < N; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    // 1) x-오름차순, tie-breaker로 y-오름차순 정렬
    sort(pts.begin(), pts.end(), [](auto &a, auto &b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    // 2) DP 배열 준비
    vector<int> dpRU(N, 0), dpRD(N, 0), dpLU(N, 0), dpLD(N, 0);

    // 3) 오른쪽 위(RU), 오른쪽 아래(RD)
    //    i를 뒤에서부터 내려오며, j>i에 대해서만 본다
    for (int i = N - 1; i >= 0; --i) {
        for (int j = i + 1; j < N; ++j) {
            if (pts[j].x == pts[i].x) continue;  // 같은 x축 점 제외
            if (pts[j].y > pts[i].y) {
                dpRU[i] = max(dpRU[i], 1 + dpRU[j]);
            } else if (pts[j].y < pts[i].y) {
                dpRD[i] = max(dpRD[i], 1 + dpRD[j]);
            }
        }
    }

    // 4) 왼쪽 위(LU), 왼쪽 아래(LD)
    //    i를 앞에서부터 올리며, j<i에 대해서만 본다
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (pts[j].x == pts[i].x) continue;  // 같은 x축 점 제외
            if (pts[j].y > pts[i].y) {
                dpLU[i] = max(dpLU[i], 1 + dpLU[j]);
            } else if (pts[j].y < pts[i].y) {
                dpLD[i] = max(dpLD[i], 1 + dpLD[j]);
            }
        }
    }

    // 5) 최적의 중심 P 탐색
    int best = 0;
    for (int i = 0; i < N; ++i) {
        // 네 사분면에 하나 이상씩 점이 있어야 한다
        if (dpRU[i] > 0 && dpRD[i] > 0 && dpLU[i] > 0 && dpLD[i] > 0) {
            int total = 1 + dpRU[i] + dpRD[i] + dpLU[i] + dpLD[i];
            best = max(best, total);
        }
    }

    // 6) 정답 계산 및 출력
    if (best >= 5) {
        // 남기는 최대 점 개수 = best, 제거해야 할 점 = N - best
        cout << (N - best) << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
