#include <iostream>
using namespace std;
int main()
{
    int n; cin >> n;
    int *a = new int[n];
    for (int i=0;i<n;i++) cin >> a[i];
    int countf = 0;
    for (int i=0;i<n-1;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (a[i]==a[j]) countf++;
        }
    }
    cout<<countf<<endl;
}
