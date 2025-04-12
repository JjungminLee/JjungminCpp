#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[13][13];

struct State
{
    int r, c, d;
};
vector<State> v;

int dx[4] = {0, 0, -1, 1}; // →, ←, ↑, ↓
int dy[4] = {1, -1, 0, 0};
vector<int> boardStacks[13][13]; // vector 사용

int switchDir(int d)
{
    if (d == 0)
        return 1;
    if (d == 1)
        return 0;
    if (d == 2)
        return 3;
    return 2;
}

void moveWhite(int r, int c, int nr, int nc, int idx)
{
    auto it = find(boardStacks[r][c].begin(), boardStacks[r][c].end(), idx);
    vector<int> moving(it, boardStacks[r][c].end());
    boardStacks[r][c].erase(it, boardStacks[r][c].end());

    for (int m : moving)
    {
        v[m].r = nr;
        v[m].c = nc;
        boardStacks[nr][nc].push_back(m);
    }
}

void moveRed(int r, int c, int nr, int nc, int idx)
{
    auto it = find(boardStacks[r][c].begin(), boardStacks[r][c].end(), idx);
    vector<int> moving(it, boardStacks[r][c].end());
    boardStacks[r][c].erase(it, boardStacks[r][c].end());
    reverse(moving.begin(), moving.end());

    for (int m : moving)
        boardStacks[nr][nc].push_back(m); // ✅ 먼저 push해서 쌓이는 순서 보존

    for (int m : moving)
    {
        v[m].r = nr;
        v[m].c = nc;
    }
}

bool checkFinish()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (boardStacks[i][j].size() >= 4)
                return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int i = 0; i < k; i++)
    {
        int r, c, d;
        cin >> r >> c >> d;
        boardStacks[r - 1][c - 1].push_back(i);
        v.push_back({r - 1, c - 1, d - 1});
    }

    for (int turn = 1; turn <= 1000; turn++)
    {
        for (int i = 0; i < k; i++)
        {
            int r = v[i].r, c = v[i].c;
            int d = v[i].d;
            if (boardStacks[r][c].front() != i)
                continue;

            int nr = r + dx[d], nc = c + dy[d];

            if (nr < 0 || nr >= n || nc < 0 || nc >= n || arr[nr][nc] == 2)
            {
                d = switchDir(d);
                v[i].d = d;
                nr = r + dx[d];
                nc = c + dy[d];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n || arr[nr][nc] == 2)
                    continue;
            }

            else if (arr[nr][nc] == 0)
            {
                moveWhite(r, c, nr, nc, i);
            }

            else if (arr[nr][nc] == 1)
            {
                moveRed(r, c, nr, nc, i);
            }
        }

        if (checkFinish())
        {
            cout << turn << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}
