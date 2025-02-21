#include <bits/stdc++.h>
using namespace std;
int n;
int arr[17][17];
int dp_down[17][17];
int dp_right[17][17];
int dp_diag[17][17];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    dp_right[0][1] = 1;
    for (int i = 2; i < n; i++)
    {
        if (arr[0][i] == 0)
        {
            dp_right[0][i] = dp_right[0][i - 1];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                continue;
            }
            if (arr[i - 1][j] == 0)
            {
                dp_down[i][j] = dp_down[i - 1][j] + dp_diag[i - 1][j];
            }
            if (arr[i][j - 1] == 0)
            {
                dp_right[i][j] = dp_right[i][j - 1] + dp_diag[i][j - 1];
            }
            if (arr[i - 1][j - 1] == 0 && arr[i - 1][j] == 0 && arr[i][j - 1] == 0)
            {
                dp_diag[i][j] = dp_right[i - 1][j - 1] + dp_diag[i - 1][j - 1] + dp_down[i - 1][j - 1];
            }
        }
    }
    cout << dp_diag[n - 1][n - 1] + dp_down[n - 1][n - 1] + dp_right[n - 1][n - 1] << endl;
}