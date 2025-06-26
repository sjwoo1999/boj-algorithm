#include <iostream>
using namespace std;

// 최대공약수(GCD)를 구하는 함수 (유클리드 호제법)
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1; // 첫 번째 분수 a1/b1
    cin >> a2 >> b2; // 두 번째 분수 a2/b2

    // 분수 덧셈: a1/b1 + a2/b2 = (a1 * b2 + a2 * b1) / (b1 * b2)
    int numerator = a1 * b2 + a2 * b1;    // 분자
    int denominator = b1 * b2;            // 분모

    // 기약분수로 만들기 위해 분자와 분모의 최대공약수로 나눔
    int common = gcd(numerator, denominator);
    numerator /= common;
    denominator /= common;

    cout << numerator << " " << denominator << endl;

    return 0;
}
