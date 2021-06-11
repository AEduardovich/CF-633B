//C. Ray Tracing
//time limit per test2 seconds
//memory limit per test256 megabytes
//inputstandard input
//outputstandard output
#include <iostream>
#include <vector>

#define flp(i, j) for (i = 0; i < j; ++i)
#define pb push_back
#define ll long long

int main()
{
    int m, n, k, p;
    int x = 1, y = 1, a =1;
    int pos_x = 1, pos_y = 1;

    std::vector<std::vector<int> > sensor;
    std::vector<std::vector<int> > sequence;

    std::cin >> n >> m;
    std::cin >> k;

    unsigned int g = 0;
    int i = 0;
    int j = 0;

    flp(i, k)
    {
        std::vector<int> r;
        flp(j, 2)
        {
            std::cin >> p;
            r.pb(p);
        }
        sensor.pb(r);
        sequence.pb(r);
    }

    if (sensor[0][0] == 1 && sensor[0][1] == 1)
    {
        sensor[0][0] = 0;
    }

    bool peak = true;
    while (peak)
    {
        x += pos_x;
        y += pos_y;
        a++;

        if (x == n)
        {
            pos_x = -1;
        }
        if (x == 0)
        {
            pos_x = 1;
        }
        if (y == m)
        {
            pos_y = -1;
        }
        if (y == 0)
        {
            pos_y = 1;
        }
        flp(g, sensor.size())
        {
            if (x == 1 && x == sensor[g][0] && y == 1 && y == sensor[g][1])
            {
                sensor[g][0] = 0;
            }
            if (x == sensor[g][0] && y == sensor[g][1])
            {
                sensor[g][0] = a - 1;
            }
        }
        if ((x == n && y == 0) || (x == 0 && y == m) || (x == n && y == m))
        {
            peak = false;
        }
    }

    unsigned int h = 0;
    unsigned int e = 0;

    flp(h, sensor.size())
    {
        flp(e, sensor[h].size())
        {
            if (sensor[h][e] == sequence[h][e])
            {
                sensor[h][e] = -1;
            }
        }
    }

    flp(h, sensor.size())
    {
        flp(e, sensor[h].size())
        {
            if (sensor[h][e] >= 0)
            {
                sensor[h][e] = sensor[h][e] + 1;
            }
        }
        std::cout << sensor[h][0] << std::endl;
    }

    return 0;
}
