/*
 PROBLEM: http://acm.javeriana.edu.co/maratones/forum/viewtopic.php?f=818&t=949&sid=c82da877f7949eeae38c4dd228ffb8de#p1653

 AUTHOR:  Daniel Cañizares Corrales
          Systems Engineer [Professor]
	      Universidad Católica de Oriente

 LICENCE: MIT License

 Copyright (C) 2015

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

#include<bits/stdc++.h>

using namespace std;

struct State {
    int id;
    vector<vector<bool> > matrix;
    int level;
};

vector<vector<bool> >  start;
bool visited[512];
queue<State> frontier;

int do_hash(vector<vector<bool> > current)
{
    int value = 0;
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            if(current[i][j])
                value += pow(2, i*3+j);
    return value;
}

State action(int r, int c,  vector<vector<bool> > current)
{
    current[r][c] = !current[r][c];
    if(r - 1 >= 0)
        current[r-1][c] = !current[r-1][c];
    if(r + 1 < 3)
        current[r+1][c] = !current[r+1][c];
    if(c - 1 >= 0)
        current[r][c-1] = !current[r][c-1];
    if(c + 1 < 3)
        current[r][c+1] = !current[r][c+1];

    State new_state;
    new_state.id = do_hash(current);
    new_state.matrix = current;
    return new_state;
}

void print(vector<vector<bool> > matrix){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cout<<matrix[i][j];
        }
        cout<<"\n";
    }
    cout<<"\n";
    cout<<"\n";
}

int solve()
{
    State start_state;
    start_state.id = do_hash(start);
    start_state.matrix = start;
    start_state.level = 0;

    frontier.push(start_state);
    memset(visited, 0, sizeof(visited));
    visited[start_state.id] = true;

    while(!frontier.empty()){
        State state = frontier.front();
        frontier.pop();
        //cout<<"Visitando "<<state.id<<" \n";
        //print(state.matrix);

        if(state.id == 0)
            return state.level;

        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                State new_state = action(i,j,state.matrix);
                state.id = do_hash(new_state.matrix);
                //print(new_state.matrix);
                if(!visited[state.id]){
                    //cout<<"Accion "<<state.id<<"\n";
                    new_state.level = state.level + 1;
                    frontier.push(new_state);
                    visited[new_state.id] = true;
                }
            }
        }
    }
    return -1;
}


int main()
{
    int n;
    while(cin >> n) {
        for(int TEST = 0; TEST < n;++TEST){
            for(int i = 0; i < 3; ++i){
                vector<bool> row;
                for(int j = 0; j < 3; ++j){
                    char c;
                    cin >> c;
                    row.push_back(c == '*' ? 1 : 0);
                }
                start.push_back(row);
            }
            cout<<solve()<<'\n';
            start.clear();
            while(!frontier.empty())
            frontier.pop();
        }
    }
    return 0;
}
