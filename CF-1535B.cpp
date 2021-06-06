#include <iostream>
#include <string>
#include <vector>

#define flp(i, j) for (i = 0; i < j; ++i)

void srt(int a[], int len)
{
    int i = 0;
    flp(i, len)
    {
        for (int j = i + 1; j < len; ++j)
        {
            if (a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int s(void)
{
    int t;
    std::cin >> t;
    int ans = 0;
    int stp[t];
    while (t--)
    {
        int s;
        std::cin >> s;
        int p = 0;
        stp[t] = s;
    }
    unsigned int len = sizeof(stp)/sizeof(stp[0]);
    srt(stp, len);

    for (unsigned int i = 0; i < len; ++i)
    {
        for (unsigned int j = i + 1; j < len; ++j)
        {
            int c = 0;
            int MOD = 1;
            while (MOD < stp[i])
            {
                MOD++;
                if (stp[i] % MOD == 0 && (2 * stp[j]) % MOD == 0)
                {
                    c++;
                    break;
                }
            }
            ans += c;
        }
    }

    std::cout << ans;

    return 0;
}

int main()
{
    return s();
}