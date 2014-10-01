#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> node;
const int MAXN = 5055;
const int INF = 1 << 30;
int n;
vector<node> g[MAXN];
int d[MAXN];
int p[MAXN];

void ini()
{
    for(int i = 0; i < MAXN; ++i)g[i].clear();
    memset(d, 0, sizeof d);
    memset(p, 0, sizeof p);
}

int bfs(int s, int first)
{
    bool ex [MAXN];
    for(int i = 0; i < s; ++i){
        d[i] = -INF; p[i] = -1;ex[i]=false;
    }
    d[0] = first;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(ex[cur] == true)continue;
        for(int i = 0; i < g[cur].size(); ++i){
            int v = g[cur][i].first;
          //  cout<<"from: "<<cur<<" to "<<v<<endl;
            int dist = d[cur]+g[cur][i].second;
            q.push(v);
            if(d[v] < dist){
                d[v] = dist;
                p[v] = cur;
            }
        }
        ex[cur] = true;
    }
    int pos = -1, vmax = -INF;
    for(int i = 0; i < s; ++i){
        //    cout<<d[i]<<endl;
        if(d[i] > vmax){pos = i; vmax = d[i];}
    }
    return pos;
}

void contruct_graph(vector<int> values)
{
    int j = 1;
    for(int i = 0; i < values.size()-n; ++i){
         //   cout<<values[i*j+1]<<endl;
        g[i].push_back(node(i+j,values[i+j]));
        //cout<<i*j+1 << " " << i*j+1<<endl;
        g[i].push_back(node(i+j+1,values[i+j+1]));
        if((j)*(j+1)/2 == i+1)j++;
    }
}

long long int reconstruct(int pr, int first)
{
    //cout<<"recon:"<<endl;
    long long int sol = first;
    int pant = pr;
    pr = p[pr];
    while(pr != -1){
        int v;
        if(g[pr][0].first == pant)
            v = g[pr][0].second;
        else
            v = g[pr][1].second;
          //  cout<<pr<<endl;
        sol += (v*v);
        pant = pr;
        pr = p[pr];
    }
    return sol;
}

int main()
{
    while(cin >> n){
        ini();
        string l; getline(cin,l);getline(cin,l);int k;
        stringstream ss(l);
        vector<int> values;
        while(ss >> k)values.push_back(k);
        //for(int i = 0; i < values.size(); ++i)cout<<values[i]<<endl;
        contruct_graph(values);//cout<<"paso";
        int pos = bfs(values.size(),values[0]);
      //  cout<<pos<<endl;
        long long int solv = reconstruct(pos, values[0]*values[0]);
        char a1 = 'a'+d[pos]%26;
        char a2 = 'a'+solv%26;
        cout << solv << " " << d[pos] <<"\n";
        cout << a2 << a1 <<"\n";
    }

    return 0;
}
