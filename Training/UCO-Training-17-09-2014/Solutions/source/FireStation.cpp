#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> dist_node;
typedef pair <int, int> edge;

const int MAXF=110;
const int MAX = 510;
const int INF = 1 << 30;
int run, fire, inter;

vector<int> station;
vector<edge> g [MAX];
vector<edge> maxm;

int d[MAX]; //distancias;
int sta[MAX];

void connect(int a, int b, int we)
{
    g[a].push_back(edge(b,we));
    g[b].push_back(edge(a,we));
}

void ini()
{
    station.clear();maxm.clear();  memset(d,0,sizeof d);  memset(sta,0,sizeof sta);
    for(int i = 0; i < MAX; ++i)g[i].clear();
}

void dijkstra(int s)
{
    int n = inter;
    int d1[MAX];
    for(int i = 0; i <= n; ++i){
        d1[i] = INF;
    }

    priority_queue<dist_node, vector<dist_node>, greater<dist_node> > q;
    d1[s] = 0;
    q.push(dist_node(0, s));
    while(!q.empty()){
        int dist = q.top().first;
        int cur = q.top().second;
        q.pop();

        if(dist > d1[cur]) continue;
        for(int i = 0; i < g[cur].size(); ++i){
            int next = g[cur][i].first;
            int w_extra = g[cur][i].second;
            if(d1[cur] + w_extra < d1[next]){
                d1[next] = d1[cur] + w_extra;
                q.push(dist_node(d[next],next));
            }
        }
    }

    for(int i = 0; i <= n; ++i){
        d[i] = min(d[i],d1[i]);
    }


}

void dijkstra2(int s)
{
    int n = inter;
    int d1[MAX];
    for(int i = 0; i <= n; ++i){
        d1[i] = INF;
    }

    priority_queue<dist_node, vector<dist_node>, greater<dist_node> > q;
    d1[s] = 0;
    q.push(dist_node(0, s));
    while(!q.empty()){
        int dist = q.top().first;
        int cur = q.top().second;
        q.pop();

        if(dist > d1[cur]) continue;
        for(int i = 0; i < g[cur].size(); ++i){
            int next = g[cur][i].first;
            int w_extra = g[cur][i].second;
            if(d1[cur] + w_extra < d1[next]){
                if(d[next] > d1[cur] + w_extra)
                    d1[next] = d1[cur] + w_extra;
                else
                    d1[next] = d[next];
                q.push(dist_node(d1[next],next));
            }
        }
    }
    int ma = -INF;
    for(int i = 0; i < n; ++i){
        if(ma < d1[i]){
            ma=d1[i];
        }
    }
    maxm.push_back(edge(ma,s));

}

int maxstation ()
{
    int pos=-1, tam = INF;
    for(int i = 0; i < maxm.size(); ++i){
        //cout<<maxm[i].first<<endl;
        if(tam> maxm[i].first){
            pos = maxm[i].second;
            tam = maxm[i].first;
        }
    }
    return pos;
}

int main()
{
    ios_base::sync_with_stdio(false);

    while(cin>>run){
        for(; run > 0; --run){
                ini();
            cin>>fire>>inter;
            for(int t = 0; t < fire; ++t){
                int f; cin>>f; station.push_back(f-1);
                sta[f-1] = 1;
            }
            string l;getline(cin,l);
            while(getline(cin,l))
            {
               // cout << l;
                if(l == "")break;
                int a,b,we;
                stringstream ss(l);
                ss>>a>>b>>we; connect(a-1,b-1,we);
            }
            /*for(int t = 0; t < inter; ++t){
                int a,b,we ; cin>>a>>b>>we; connect(a-1,b-1,we);
            }*/
            for(int i = 0; i <= inter; ++i){
                d[i] = INF;
            }

            for(int i = 0; i < fire; ++i){
                dijkstra(station[i]);
            }

            for(int i = 0; i < inter; ++i){
                if(sta[i] == 1)continue;
                dijkstra2(i);
            }

            int ans = maxstation()+1;
            if(ans == 0)ans = 1;
            cout<<ans<<"\n";
            if(run != 1)cout<<"\n";
        }
    }
    return 0;
}
