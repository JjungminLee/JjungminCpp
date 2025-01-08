#include <bits/stdc++.h>

using namespace std;
int num;

vector<int> v;
unordered_set<int> visited;
void backTracking(int num, int time)
{ // 42 ,1

    if (time == 7 || visited.count(num))
    {
        return;
    }

    int rem = num % 10; // 2

    v.push_back(num);
    visited.insert(num);
    // 420 421
    if (rem > 0)
    {

        for (int j = 0; j < rem; j++)
        {

            backTracking((num * 10) + j, time + 1);
        }
    }
}

int main()
{

    cin >> num;
    int nn = 0;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        if (i >= 1)
        {
            for (int j = 0; j < i; j++)
            {
                backTracking((i * 10) + j, 1);
            }
        }
    }
    sort(v.begin(), v.end());

    if (v.size() < num)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << v[num] << endl;
    }
}
