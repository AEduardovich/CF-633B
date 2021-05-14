#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

int solve()
{
    long long a;
    std:: cin >> a;
    int res = (a * 5) - a + 5;
    std:: vector < int > ans;
    std:: vector < int > sol;
    std:: vector < int > mod;
    std:: vector < int > str;
    std:: vector < int > dll;
    int sum = 0;
    int e_cache = 0;
    int f_cache = 0;
    int c = 0;
    int y = 0;
    int ll = res;

    int len = 0;

    for (int i = 5; res / i >= 1; i *= 5)
    {
        c += res / i;
        y++;
        mod.push_back(res / i);
    }

    e_cache = mod[mod.size() - 1];
    f_cache = mod[0];

    if (c != a) {
        res = res + 5;
        c = 0;
        for (int jk = 5; res / jk >= 1; jk *= 5)
        {
            c += res / jk;
        }
        f_cache = mod[0] + 1;
    }

    if (c != a) {
        res = res + 5;
        c = 0;
        for (int jk = 5; res / jk >= 1; jk *= 5)
        {
            c += res / jk;
        }
        f_cache = mod[0] + 2;
    }

    if (c != a) {
        res = res + 5;
        c = 0;
        for (int jk = 5; res / jk >= 1; jk *= 5)
        {
            c += res / jk;
        }
        f_cache = mod[0] + 3;
    }

    if (c != a) {
        a = 0;
    }

    int max = res + 15;
    int min = res - 15;

    if (a > 0 && c == a) {
        while (res > min) {
            ans.push_back(res--);
        }
        while (ll < max) {
            ans.push_back(ll++);
        }
    }

    sum = pow(5, y);

    for (size_t ii = 0; ii < ans.size(); ++ii)
    {
        if (ans[ii] / 5 == f_cache && ans[ii] / sum == e_cache) {
            str.push_back(ans[ii]);
        }
    }

    for (size_t ij = 0; ij < str.size(); ++ij)
    {
        for (size_t jk = ij + 1; jk < str.size(); ++jk)
        {
            if (str[ij] > str[jk]) {
                int temp = str[ij];
                str[ij] = str[jk];
                str[jk] = temp;
            }
        }
    }

    for (size_t si = 0; si < str.size(); ++si)
    {
        if (str[si] != str[si + 1]) {
            dll.insert(dll.end(), str[si]);
        }
    }

    len = dll.size();

    std:: cout << len << "\n";

    for (size_t pi = 0; pi < dll.size(); ++pi)
    {
        std:: cout << dll[pi] << " ";
    }

    return 0;
}

int main(void)
{
    solve();
}
