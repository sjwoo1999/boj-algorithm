#include <iostream>
#include <vector>

using namespace std;

// 에라토스테네스의 체로 소수를 미리 구함
vector<bool> sieve(int max_num) {
    vector<bool> is_prime(max_num + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max_num; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_num; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int count_goldbach_partition(int n, const vector<bool>& is_prime) {
    int count = 0;
    for (int i = 2; i <= n / 2; ++i) {
        if (is_prime[i] && is_prime[n - i]) {
            count++;
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;

    vector<int> nums(T);
    int max_n = 0;
    for (int i = 0; i < T; ++i) {
        cin >> nums[i];
        if (nums[i] > max_n) {
            max_n = nums[i];
        }
    }

    vector<bool> is_prime = sieve(max_n);

    for (int i = 0; i < T; ++i) {
        cout << count_goldbach_partition(nums[i], is_prime) << '\n';
    }

    return 0;
}