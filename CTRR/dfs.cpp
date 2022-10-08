#include <bits/stdc++.h>
using namespace std;

    int n, m;
    vector<int> adj[1001];
    bool visited[1000];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
void dfs(int u)
{
    cout << u << " ";
    // Danh dau la u da duoc tham
    visited[u]= true;
    for(int v : adj[u])
    { 
        // Neu dinh v chua duoc tham
        if (!visited[v])
        {
            dfs(v);
        }
        
    }
}
int main()
{
    input();dfs();
    return 0;
}
Đường đi : 
c -> e -> a -> b -> e -> d
Ko có chu trình