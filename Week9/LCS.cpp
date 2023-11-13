#include <iostream>
using namespace std;
int main()
{
    string first, second;
    cin >> first >> second;
    int n = first.length(), m = second.length();
    int** dp = new int*[n + 1];
    for (int i = 0;i<n+1; i++)
    {
        dp[i] = new int[m + 1];
        for (int j = 0;j<m+1;j++) dp[i][j] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if(first[i - 1] == second[j - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout << dp[n][m];
}
