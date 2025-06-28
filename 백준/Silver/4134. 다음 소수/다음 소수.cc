#include <iostream>
#include <cmath>
using namespace std;

// 소수 판정 함수
bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        while (true) {
            if (isPrime(n)) {
                cout << n << "\n";
                break;
            }
            n++;
        }
    }
    return 0;
}
