/*
 PROBLEM: http://codeforces.com/problemset/problem/368/A
 
 AUTHOR:  Daniel Cañizares Corrales
          Systems Engineer [Professor]
		  Universidad Católica de Oriente
          dacanizares@outlook.com
		  		 
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
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, d, m;
	vector<int> a;
	while(cin >> n >> d)
	{
		// Clear vector to ensure that
		// it's empty
		a.clear();
		
		for(int i = 0; i < n; ++i)
		{
			int ai;
			cin >> ai;
			a.push_back(ai);
		}
		cin >> m;
		
		// Sort vector in order to
		// select cheap hooks first
		sort(a.begin(), a.end());
				
		int profit = 0;
		for(int i = 0; i < m; ++i)
		{
			if(i < a.size())
			{
				profit += a[i];
			}
			else
			{
				profit -= d;
			}
		}
		cout << profit << endl;
	}
}
