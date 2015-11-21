/*
 PROBLEM: http://codeforces.com/problemset/problem/589/J

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

#define MAX 15

using namespace std;

int w,h;
char matrix[MAX][MAX];
int visited[MAX][MAX];

struct robot{
    int x,y;
    char d;

    robot(int x, int y, char d): x(x), y(y), d(d){}
};

#define o(w) if(w == 0) return robot(x,--y,'U'); \
            if(w == 1) return robot(++x,y,'R'); \
            if(w == 2) return robot(x,++y,'D'); \
            if(w == 3) return robot(--x,y,'L'); \

robot fw(char a, int x, int y, int where)
{
    if(a == 'U'){
        o(where)
    }
    if(a == 'R'){
        o((where+1)%4)
    }
    if(a == 'D'){
        o((where+2)%4)
    }
    if(a == 'L'){
        o((where+3)%4)
    }
}
#undef o

int dfs(char dir, int x, int y)
{
    int sum = 0;
    if(visited[y][x] == 0)
        sum++;

    visited[y][x]++;

    for(int i = 0; i < 4; ++i){
        robot u = fw(dir, x, y, i);
        if(u.x < 0 or u.y < 0 or u.x >= h or u.y >= w)
            continue;
        if(matrix[u.y][u.x] != '*' and visited[u.y][u.x] <4){
            sum += dfs(u.d, u.x, u.y);
            break;
        }
        if(matrix[u.y][u.x] != '*' and visited[u.y][u.x] >= 4)
            break;
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> w >> h;
    pair<int,int> pi;
    for(int i = 0; i < w; ++i){
        for(int j = 0; j < h; ++j){
            char a; cin >> a;
            matrix[i][j] = a;
            if(a != '.' and a != '*')
                pi = make_pair(j,i);
        }
    }
    cout << dfs(matrix[pi.second][pi.first], pi.first, pi.second) << '\n';

    return 0;
}
