#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    set<string> substrings;

    for (int i = 0; i < S.size(); ++i) {
        string temp = "";
        for (int j = i; j < S.size(); ++j) {
            temp += S[j];
            substrings.insert(temp);
        }
    }

    cout << substrings.size() << '\n';
    return 0;
}
