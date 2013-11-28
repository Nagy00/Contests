/*
 PROBLEM: http://codeforces.com/problemset/problem/349/A
 
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
int n;


int pos (int n)
{
	if(n == 25)return 0;
	if(n == 50)return 1;
	return 2;
}

bool devolver(int dinero, int rublos [3])
{
	if(dinero == 25)
	{
		return true;
	}
	if(dinero == 50)
	{
		rublos[0]--;
		if(rublos[0] < 0)return false;	
		return true;
	}
	if(dinero == 100)
	{
		if(rublos[0] > 0 && rublos[1] > 0)
		{
			rublos[0]--;
			rublos[1]--;
			return true;
		}
		if(rublos[0]>=3)
		{
			rublos[0]-=3;
			return true;
		}
		else
		{
			return false;
		}
	}
	return true;
}


int main()
{
	while(cin>>n)
	{
		bool p = true;
		int rublos [3] = {0,0,0};
		for(int i = 0; i < n; ++i)
		{
			int dinero;
			cin>>dinero;
			rublos[pos(dinero)]++;
			if(devolver(dinero,rublos) == false)
			{
				p = false;
			}
		//	ans += 25;
		}
		if(p)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
