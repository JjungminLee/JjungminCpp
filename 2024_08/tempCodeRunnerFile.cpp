#include <bits/stdc++.h>
using namespace std;
int n;
int m;

int parent[101];
int find(int a)
{
    if (a == parent[a])
    {
        return a;
    }
    return parent[a] = find(parent[a]);
}
void unions(int a, int b)
{
    int x = find(a);
    int y = find(b);
    if (x < y)
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
    }
}
int main()
{
    cin >> n;
    cin >> m;
    for (int i = 0; i <= n; i++)
    {
        parent[i + 1] = i + 1;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        unions(a, b);
    }
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        cout << parent[i] << " ";

        if (parent[i] == 1)
        {
            ans++;
        }
    }
    cout << endl;

    cout << ans << "\n";
}