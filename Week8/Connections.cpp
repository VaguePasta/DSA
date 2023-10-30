#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool visitedAll(vector<bool>  &visited)
{
	for (bool i: visited) if (!i) return false;
	return true;
}
bool order(vector<int> &v1, vector<int> &v2)
{
    if (v1[2]<v2[2]) return true;
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> connection_cost;
    for (int i = 0;i < m;i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        connection_cost.push_back({u, v, d});
    }
    sort(connection_cost.begin(), connection_cost.end(), order);
    vector<vector<int>> minimum_span_tree;
    vector<bool> visited(n, false);
    minimum_span_tree.push_back({connection_cost[0][0], connection_cost[0][1], connection_cost[0][2]});
    visited[connection_cost[0][0]] = true;
    visited[connection_cost[0][1]] = true;
    visited[0] = true;
    int total_cost = connection_cost[0][2];
    while (!visitedAll(visited))
    {
        for (vector<int> edge : connection_cost)
        {
            if (visited[edge[0]] && !visited[edge[1]])
            {
                minimum_span_tree.push_back({edge[0], edge[1], edge[2]});
                visited[edge[1]] = true;
                total_cost += edge[2];
                break;
            }
            if (!visited[edge[0]] && visited[edge[1]])
            {
                minimum_span_tree.push_back({edge[0], edge[1], edge[2]});
                visited[edge[0]] = true;
                total_cost += edge[2];
                break;
            }
        }
    }
    cout << total_cost << endl;
    for (vector<int> edge : minimum_span_tree)
    {
        cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
    }
}
