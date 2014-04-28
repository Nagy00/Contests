/*
 PROBLEM SET: http://1drv.ms/1m1QHco
 PROBLEM E
 
 TEAM: Alpha Centauri
 
 AUTHORS: Juan Felipe Cañizares Corrales
          Systems Engineer [Student]
	  	  Universidad Católica de Oriente
          pipecaniza@outlook.com
		  
		  Leidy Melisa Agudelo S.
          Systems Engineer [Student]
	  	  Universidad Católica de Oriente
          magudelo169@gmail.com
		  
		  Brian Giraldo Echeverri
          Systems Engineer [Student]
	  	  Universidad Católica de Oriente
          briangiraldo123@hotmail.com	  

 LICENCE: MIT License
 	
 Copyright (C) 2014 Alpha Centauri
                    
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

map<int,int> col;
int a,b;

void coll(int n)
{
	col[n] = 0;
	int pos = 1;
	while(n != 1)
	{
		if(n % 2 == 0)
		{
			n = n/2;
		}
		else
		{
			n = 3*n+1;
		}
		col[n] = pos;
		pos++;		
	}
}

int main()
{
	while(cin>>a>>b)
	{
		if(a == 0 && b == 0)break;
		coll(a);
		int pos = 0;
		int pos2 = 0;
		int ans = 1;
		int b1 = b;
		while(!col.count(b1))
		{
			if(b1 % 2 == 0)
			{
				b1 = b1/2;
			}
			else
			{
				b1 = 3*b1+1;
			}
			pos++;
		}
		pos2 = col[b1];
		ans = b1;
		cout<<a<<" needs "<<pos2<<" steps, "<<b<<" needs "<<pos<<" steps, they meet at "<<ans<<endl;
		col.clear();
	}
	return 0;
}

