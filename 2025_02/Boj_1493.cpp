#include <bits/stdc++.h>
using namespace std;

int length, width, height;
vector<pair<int, int>> v;
int n;
int ans;
bool impossible = false;

void divide(int l, int w, int h)
{
    if (l == 0 || w == 0 || h == 0 || impossible)
        return;

    for (int i = 0; i < n; i++)
    {
        int size = 1 << v[i].first;

        if (v[i].second > 0 && size <= l && size <= w && size <= h)
        {
            v[i].second--; // 큐브 사용
            ans++;

            divide(l - size, w, h);
            divide(size, w - size, h);
            divide(size, size, h - size);
            return;
        }
    }

    impossible = true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> length >> width >> height;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.first > b.first; });

    divide(length, width, height);

    if (impossible)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}
