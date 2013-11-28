/*
 PROBLEM: http://codeforces.com/contest/368/problem/B

 NOTES:   I used use maps to avoid time limit exceptions.
 
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
#include <map>

using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		int a[n];		
		for(int i = 0; i < n; ++i)
		{
			int value;
			cin >> value;	
			a[i] = value;
		}
		
		// Calculate solution
		int  solution[n];
		// We use a map to count just distinct numbers
		map<int,bool> different;
		for(int i = n - 1; i >= 0; i--)
		{				
			different[a[i]] = true;
			solution[i] = different.size();
		}
		
		for(int i = 0; i < m; ++i)
		{
			int value;
			cin >> value;			
			cout << solution[value - 1] << endl;
		}
	}
}
