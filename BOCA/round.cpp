/*
 PROBLEM: http://acm.javeriana.edu.co/maratones/forum/viewtopic.php?f=702&t=840&sid=ca13060eb4f374c0c166801002ae43b8
 
 AUTHORS: Juan Felipe Cañizares Corrales
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

int n,t;
vector<int> players;
int positions[110];

void ini()
{
	for(int i = 0; i < n; ++i)
	{
		positions[i] = i;
	}
}

int finish()
{
	int value = players[0];
	for(vector<int>::iterator it = players.begin(); it != players.end(); ++it)
	{
		if(*it != value || *it == 0)
			return -1;		
	}
	return value;
}


int main()
{
	while(cin>>n)
	{
		if(n == 0)break;
		cin>>t;
		
		int pos = 0;
		
		for(int i = 0; i < n; ++i)
		{
			players.push_back(0);
		}
		while(finish() == -1)
		{
			for(int i = 1; i < t; ++i)
			{
				players[pos]++;
				pos = (pos+1)%n;				
			}
			players.erase(players.begin()+pos);
			n--;
			pos = pos%n;			
		}
		
		cout<<n<<" "<<finish()<<endl;
		players.clear();
	}
	return 0;
}
