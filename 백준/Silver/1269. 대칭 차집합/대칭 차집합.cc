#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, x;
    cin >> a >> b;

    unordered_set<int> A, B;

    for (int i = 0; i < a; ++i) {
        cin >> x;
        A.insert(x);
    }

    for (int i = 0; i < b; ++i) {
        cin >> x;
        B.insert(x);
    }

    int count = 0;

    // A - B
    for (int val : A) {
        if (B.find(val) == B.end()) {
            ++count;
        }
    }

    // B - A
    for (int val : B) {
        if (A.find(val) == A.end()) {
            ++count;
        }
    }

    cout << count << '\n';
    return 0;
}
