#include <bits/stdc++.h>

using namespace std;

const int MAX = 100100;
int c, n , m;

vector<int> graph[MAX];
vector<int> topo;
int seen_t[MAX], seen[MAX];

void ini()
{
    for(int i = 0; i <= n; ++i)graph[i].clear();
    memset(seen_t, 0, sizeof seen_t);
    memset(seen, 0, sizeof seen);
    topo.clear();
}

void topo_sort(int u)
{
    seen_t[u]=1;
    for(int i = 0; i < graph[u].size(); ++i){
        if(seen_t[graph[u][i]] != 0)continue;
        topo_sort(graph[u][i]);
    }
    topo.push_back(u);
}

void DotopoSort()
{
    for(int i = 1; i <= n; ++i){
        if(seen_t[i] == 0)topo_sort(i);
    }
    reverse(topo.begin(), topo.end());
}

void dfs(int u)
{
    seen[u]=1;
    for(int i = 0; i < graph[u].size(); ++i){
        if(seen[graph[u][i]] != 0)continue;
        dfs(graph[u][i]);
    }
}

int main()
{
    while(cin>>c){
        for(int t = 0; t < c; ++t){
            cin>>n>>m;
            ini();
            for(int i = 0; i < m; ++i){
                int x,y; cin>>x>>y;
                graph[x].push_back(y);
            }
            DotopoSort();
            int ans = 0;
            for(int i = 0; i < n; ++i){
                if(seen[topo[i]]==0){
                    dfs(topo[i]);ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
