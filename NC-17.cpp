#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int isP(int a) {
    for(int i = 2; i <= sqrt(a); ++i) {
        if(a % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int c = 1;
    vector<int> p;
    while(true && c <= 100000000) {
        c++;
        if(isP(c)) {
            p.push_back(c);
        }
    }

    for(size_t i = 0; i < p.size(); ++i) {
        cout << p[i] <<"\n";
    }

    return 0;
}