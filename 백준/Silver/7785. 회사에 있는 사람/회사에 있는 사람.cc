#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<string> office;

    for (int i = 0; i < n; ++i) {
        string name, action;
        cin >> name >> action;

        if (action == "enter") {
            office.insert(name);
        } else if (action == "leave") {
            office.erase(name);
        }
    }

    // set은 자동 정렬되어 있으므로, 역순 출력 위해 vector로 복사 후 reverse 정렬
    vector<string> result(office.begin(), office.end());
    sort(result.rbegin(), result.rend());  // 사전 역순 정렬

    for (const string& name : result) {
        cout << name << '\n';
    }

    return 0;
}