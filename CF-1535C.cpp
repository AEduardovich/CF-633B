#include <iostream>
#include <string>

#define fpl(i,j) for(i = 0; i < j; ++i)

int c(void) {
    int k;
    std::cin>>k;
    while(k--) {
        int r = 0;
        int l = 0;
        int ans = 0;
        unsigned int i = 0;
        int f = 0;
        std::string s;
        std::cin>>s;
        fpl(i, s.length()) {
            if(s[i]-'0' == f || s[i] == '?') {
                l++;
            }
            else {
                l=0;
            }
            if(s[i]-'0'== 1-f || s[i] == '?') {
                r++;
            }
            else {
                r=0;
            }
            ans+=std::max(l,r);
            f=1-f;
        }
        std::cout <<ans;
    }
    return 0;
}

int main() {
    return c();
}