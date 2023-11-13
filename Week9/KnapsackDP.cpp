#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int W ; cin >> W;
    int n ; cin >> n;
    vector<int[2]> artifacts(n+1);
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> artifacts[i][0];
        cin >> artifacts[i][1];
    }
    int maxValue[n+1][W+1];
    for (int i = 0 ; i <= n ; i++)
    {
        maxValue[i][0] = 0;
    }

    for (int i = 0 ; i <= W ; i++)
    {
        maxValue[0][i] = 0;
    }
    for (int i = 1 ; i <= n ; i++){
        for (int L = 1 ; L <= W ; L++)
        {
            maxValue[i][L] = maxValue[i-1][L];
            if ( L >= artifacts[i][1] && (maxValue[i-1][L-artifacts[i][1]] + artifacts[i][0] > maxValue[i-1][L]))
            {
                maxValue[i][L] = maxValue[i-1][L-artifacts[i][1]] + artifacts[i][0];
            }
        }
    }
    cout << maxValue[n][W];
    return 0;
}
