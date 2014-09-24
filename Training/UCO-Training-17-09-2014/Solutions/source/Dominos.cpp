/*PROBLEM: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2499

AUTHOR:  Juan Felipe Cañizares Corrales
         Systems Engineer [Student]
         Universidad Católica de Oriente
         pipecaniza@outlook.com

LICENCE: MIT License

Copyright (C) 2013 Daniel Cañizares Corrales

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:


The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.
*/

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
