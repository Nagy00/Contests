/*
 PROBLEM: http://codeforces.com/problemset/problem/365/A

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
#include <sstream>
#include <vector>

using namespace std;

// Adds v to ns avoiding
// repeated values
void add(int v, vector<int> &ns)
{
	for(int i = 0; i < ns.size(); ++i)
	{
		if(v == ns[i])
			return;
	}
	ns.push_back(v);
}

// Checks if n is a good number
bool kgood(long long int n, int k, vector<int> ns)
{
	int v = n % 10;	
	if(n == 0)
	{
		return ns.size() == k + 1;
	}
	if(v <= k)
	{	
		add(v,ns);			
	} 
	return kgood(n/10,k,ns);
}

int main()
{
	int n, k;
	while(cin>> n >> k)
	{
		int c = 0;
		long long int value;
		for(int i = 0; i < n; ++i)
		{
			cin >> value;
			if((value == 0 && k == 0) || kgood(value, k, vector<int>()))
			{			
				c++;
			}
		}
		cout << c << endl;		
	}	
	return 0;
}
