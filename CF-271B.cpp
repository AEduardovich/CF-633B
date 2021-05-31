#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//Given Matrix[n,m] - (1<=n,m<=500)
//Each number in (n,m) is positive integer
//We can consider the Matrix is prime if:
//1.exist such a row where each number is prime
//2.exist such a col where each number is prime
//All numbers are less or eq to 10^5
//Return single integer - for the min steps
//for converting such a matrix to prime one
//where each number can be increase by 1.
//time: 2 sec;
//space: 256 mb;

int isP(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int sol(void)
{
    vector<vector<int> > matrix;
    int n;
    int m;
    int v;
    cout << "Declare the Matrix size:";
    cin >> n >> m;
    vector<int> p;
    vector<int> d;
    for (int i = 0; i < n; ++i)
    {
        vector<int> sub;
        for (int j = 0; j < m; ++j)
        {
            cin >> v;
            sub.push_back(v);
        }
        matrix.push_back(sub);
    }

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            if (isP(matrix[i][j]) == true)
            {
                matrix[i][j] = 0;
            }
            else
            {
                int nP = matrix[i][j];
                int c = 0;
                while (isP(nP) != 1)
                {
                    nP++;
                    c++;
                    matrix[i][j] = c;
                }
            }
        }
    }

    int trans[n][m];

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            trans[j][i] = matrix[i][j];
        }
    }

    for (size_t i = 0; i < matrix.size(); ++i)
    {
        int sum = 0;
        for (size_t j = 0; j < matrix[i].size(); ++j)
        {
            sum += matrix[i][j];
        }
        p.push_back(sum);
    }

    for (size_t i = 0; i < sizeof(trans) / sizeof(trans[0]); ++i)
    {
        int sum = 0;
        for (size_t j = 0; j < sizeof(trans) / sizeof(trans[i]); ++j)
        {
            sum += trans[i][j];
        }
        d.push_back(sum);
    }

    for (size_t i = 0; i < p.size(); ++i)
    {
        for (size_t j = 0; j < p.size(); ++j)
        {
            if (p[i] < p[j])
            {
                int temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }

    for (size_t i = 0; i < d.size(); ++i)
    {
        for (size_t j = 0; j < d.size(); ++j)
        {
            if (d[i] < d[j])
            {
                int temp = d[j];
                d[j] = d[i];
                d[i] = temp;
            }
        }
    }

    return d[0] > p[0] ? p[0] : d[0];
}

int main()
{
    cout << sol();
    return 0;
}