#include <bits/stdc++.h>

using namespace std;

const int MAX=110;

int n,s,t,ca;
vector<int> g [MAX];
int c [MAX][MAX];
int f [MAX][MAX];

int prev [MAX];

void ini()
{
    for(int i = 0; i < MAX; ++i)g[i].clear();
    memset(c,0, sizeof(c[0][0])*MAX*MAX);
    memset(f,0, sizeof(f[0][0])*MAX*MAX);
}

void connect(int i, int j, int cap)
{
    g[i].push_back(j);
    g[j].push_back(i);
    c[i][j] += cap;
    c[j][i] += cap;
}

int maxflow(int s, int t)
{
    for(int i = 0; i <=n; ++i){
        for(int j = 0; j <= n; ++j){
            f[i][j] = 0;
        }
    }

    int flow = 0;
    while(true){
        for(int i = 0; i <= n; ++i) prev[i] = -1;

        queue<int> q;
        q.push(s);
        prev[s] = -2;

        while(q.size() > 0){
            int u = q.front(); q.pop();
            if(u == t) break;
            for(int i = 0; i < g[u].size(); ++i){
                int v = g[u][i];
                if(prev[v] == -1 and c[u][v] - f[u][v] > 0){
                    q.push(v);
                    prev[v] = u;
                }
            }
        }
        if(prev[t] == -1)break;

        int extra = 1 << 30;
        int end = t;
        while(end != s){
            int start = prev[end];
            extra = min(extra, c[start][end] - f[start][end]);
            end = start;
        }
        end = t;
        while(end != s){
            int start = prev[end];
            f[start][end] += extra;
            f[end][start] = -f[start][end];
            end = start;
        }

        flow += extra;
    }
    return flow;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int casein = 1;
    while(cin>>n){
        if(n == 0)break;
        cin>>s>>t>>ca;
        for(; ca > 0 ; --ca){
            int a,b,v; cin>>a>>b>>v;
            connect(a,b,v);
        }
        int solve = maxflow(s,t);
        cout<<"Network "<<casein<<"\n";
        cout<<"The bandwidth is "<<solve<<".\n\n";
        casein++;
        ini();
    }
    return 0;
}
