/*
 PROBLEM: http://codeforces.com/problemset/problem/598/D

 AUTHOR:  Juan Felipe Cañizares Corrales
          Systems Engineer
		  Universidad Católica de Oriente
          pipecaniza@outlook.com

 LICENCE: MIT License

 Copyright (C) 2015 Juan Felipe Cañizares Corrales

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

#define ALL(x) x.begin(), x.end()
#define MAXX 1005
#define MAXY 1005

using namespace std;

typedef long long int LL;

int n,m,k;
char matrix [MAXY][MAXX];
int sol [MAXY][MAXX];
bool visited [MAXY][MAXX];
vector<pair<int,int> > add;

int dfs(int x, int y)
{
    visited[y][x] = true;
    add.push_back(make_pair(x,y));
    int sum = 0;
    for(int i = -1; i <=1; i +=2){
        if(y+i >= 0 and y+i < n){
            if(matrix[y+i][x] == '*')
                sum++;
            else if(matrix[y+i][x] == '.' and !visited[y+i][x])
                sum += dfs(x,y+i);
        }
        if(x+i >= 0 and x+i < m){
            if(matrix[y][x+i] == '*')
                sum++;
            else if(matrix[y][x+i] == '.' and !visited[y][x+i])
                sum += dfs(x+i,y);
        }
    }
    return sum;
}

void putvalue(int value)
{
    for(int i = 0; i < add.size(); ++i)
        sol[add[i].second][add[i].first] = value;
    add.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> matrix[i][j];

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(matrix[i][j] != '*' and !visited[i][j])
                putvalue(dfs(j,i));




    for(int i = 0; i < k; ++i){
        int a,b;
        cin >> a >> b; a--; b--;
        cout << sol[a][b] << '\n';
    }

    return 0;
}
