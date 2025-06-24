#include <iostream>

using namespace std;

// 최대공약수(GCD)를 구하는 유클리드 호제법
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// 최소공배수(LCM) = (a * b) / gcd(a, b)
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b; // 오버플로 방지
}

int main() {
    long long A, B;
    cin >> A >> B;

    cout << lcm(A, B) << '\n';

    return 0;
}
