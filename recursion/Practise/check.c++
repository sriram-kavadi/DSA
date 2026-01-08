#include<iostream>
#include<algorithm>
using namespace std;
static const long long MOD = 1e9 + 7;

long long modPow(long long base, long long exp) {
    long long res = 1;
    base %= MOD;

    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int countGoodNumbers(long long n) {
    long long even = (n + 1) / 2;
    long long odd  = n / 2;

    long long ans = (modPow(5, even) * modPow(4, odd)) % MOD;
    return (int)ans;
}

int main(){
    cout<<countGoodNumbers(806166225460393);
    return 0;
}