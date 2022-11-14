#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    srand(time(0));
    int l, r;
    cin >> l >> r;
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (r - l + 1) + l;
    }
    int m;
    cin >> m;
    vector<vector<double>> v(m);
    vector<double> g(m), sum(m);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> g[i];
    }

    for (int _ = 0; _ < n / 2; _++)
    {
        v.clear();
        sum.clear();
        v.resize(m);
        sum.resize(m);
        for (int i = 0; i < m; i++)
        {
            v[i].push_back(g[i]);
            sum[i] = g[i];
        }
        for (int i = 0; i < n; i++)
        {
            int closest = 0;
            double value = INT_MAX;
            for (int j = 0; j < m; j++)
            {
                if (abs(v[j][0] - arr[i]) < value)
                {
                    value = abs(v[j][0] - arr[i]);
                    closest = j;
                }
            }

            sum[closest] += arr[i];
            v[closest].push_back(arr[i]);
            v[closest][0] = sum[closest] / v[closest].size();
        }

        bool flag = true;
        for (int j = 0; j < m; j++)
        {
            if (abs(g[j] - v[j][0]) > 0.1)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            break;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl
             << endl;
    }
    cout << endl;
}
