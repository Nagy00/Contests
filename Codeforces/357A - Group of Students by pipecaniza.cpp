/*
 PROBLEM: http://codeforces.com/problemset/problem/357/A
 
 AUTHOR:  Juan Felipe Cañizares Corrales
          Systems Engineer [Student]
          Universidad Católica de Oriente
          pipecaniza@outlook.com

 LICENCE: MIT License
 	
 Copyright (C) 2013 Juan Felipe Cañizares Corrales
                    
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
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>
#include <stack>
#include <map>
#include <set>

using namespace std;
int m,x,y;
int puntajes [100];

int analizar(int tam1, int tam2, int num)
{
     if(tam2+num >= x && tam2+num <= y && tam1 >= x && tam1 <= y)
                 return 1;
     if(tam1+num >= x && tam1+num <= y && tam2 >= x && tam2 <= y)
                 return 0;
     return -1;
}

int solve(int ini, int fin, int tam1, int tam2)
{
    if(ini > fin)
    {
           int ans = analizar(tam1, tam2, 0);
           if(ans == -1)return -1;
           return ini;
    }
    if(ini == fin)
    {
           int ans = analizar(tam1, tam2, puntajes[fin]);
           if(ans == -1)return -1;
           if(ans == 1) return fin;
           return fin + 1;           
    }
    int s=0;
    if(tam1 + puntajes[ini] <= y) 
    {
            tam1 += puntajes[ini];
            s++;
    }
    int k = 0;
    if(tam2 + puntajes[fin] <= y) 
    {
            tam2 += puntajes[fin];
            k++;
    }   
    if(k == 0 && s == 0) return -1;
    return solve(ini+s, fin-k, tam1, tam2);
    
}

int main()
{
    while(cin>>m)
    {
         for(int i = 0; i < m; ++i)
         {
                 cin>>puntajes[i];
         }
         cin>>x>>y;
         int ans = solve(0,m-1,0,0);
         if(ans == -1)
                cout<<0<<endl;
         else
             cout<<ans+1<<endl;
                         
    }    
    return 0;
    
}
