#include <bits/stdc++.h>

using namespace std;

#define MAX 10010

vector<int> graph[MAX];
bool used [MAX];

void dfs(int u){
    if(used[u])
        return;
    used[u] = true;
    for(int i = 0; i < graph[u].size();++i){
        int v = graph[u][i];
        if(!used[v])
            dfs(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for(int test = 0; test < T; ++test){
        int n,m;
        cin >> n >> m;
        for(int i = 0; i < m; ++i){
            int a,b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        memset(used, false, sizeof used);
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            if(!used[i]){
                dfs(i);
                ans++;
            }
        }
        cout << (ans*(ans-1)/2)<<'\n';
        for(int i = 1; i <= n; ++i)
            graph[i].clear();
    }

    return 0;
}
