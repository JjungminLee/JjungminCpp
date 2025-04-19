#include <bits/stdc++.h>
using namespace std;

long long n, m;
vector<long long> v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int left = 0;
    int mid = 0;
    int right = m * v[v.size() - 1];
    while (left <= right)
    {
        int cnt = 0;

        mid = (left + right) / 2;

        for (int i = 0; i < v.size(); i++)
        {
            cnt += (mid / v[i]);
        }
        // cout << "mid " << mid << "cnt " << cnt << endl;
        if (cnt >= m)
        {
            right = mid - 1;
        }
        else if (cnt < m)
        {
            left = mid + 1;
        }
        else if (cnt == m)
        {
            break;
        }
    }
    cout << mid << endl;
}