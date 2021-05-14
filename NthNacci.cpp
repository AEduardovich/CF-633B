#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MOD 10000000007;
long long int a,b,c,d;

void fast_fib(long long int n, long long int t[]) {
    if(n == 0) {
        t[0] = 0;
        t[1] = 1;
        return;
    }
    fast_fib((n/2), t);
    a = t[0];
    b = t[1];
    c = 2 * b - a;
    if(c < 0)
        c+= MOD;
    c = (a * c) % MOD;
    d = (a * a + b * b) % MOD;
    if(n % 2 == 0) {
        t[0] = c;
        t[1] = d;
    }
    else {
        t[0] = d;
        t[1] = c + d;
    }
}

int main() {
    long long int n;
    scanf("%lld", &n);
    long long int t[2]={0};
    fast_fib(n, t);
    printf("%lld\n", t[0]);
    return 0;
}