#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int capacity;
    cin >> capacity;
    int n;
    cin >> n;
    vector<vector<int>> artifacts(n);
    for (int i = 0; i < n; i++) artifacts.push_back(vector<int>());
    vector<float> valueperweight(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        artifacts[i].push_back(x);
        artifacts[i].push_back(y);
        valueperweight[i] = artifacts[i][1] / artifacts[i][0];
    }
    int currentWeight = 0;
    int profit = 0;
    while (currentWeight < capacity)
    {
        vector<float>::iterator i = max_element(valueperweight.begin(), valueperweight.end());
        valueperweight.erase(i);
        vector<vector<int>>::iterator it = artifacts.begin();
        artifacts.erase(it);
        if (currentWeight + artifacts[i - valueperweight.begin()][0] > capacity) break;
        currentWeight += artifacts[i - valueperweight.begin()][0];
        profit += artifacts[i - valueperweight.begin()][1];
    }
    cout << currentWeight << " " << profit;
}
