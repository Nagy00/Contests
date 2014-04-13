/*
 PROBLEM: http://acm.javeriana.edu.co/maratones/forum/viewtopic.php?f=708&t=846&sid=ca13060eb4f374c0c166801002ae43b8
 
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

int n;
string alfabeto;
int pos [100];
string strings[25];

void ini()
{
	for(int i = 0; i < alfabeto.size();++i)
	{
		pos[alfabeto[i]-'A'] = i;
	}
}

bool comparar(string s1, string s2)
{
	int tam = min(s1.size(),s2.size());
	for(int i = 0; i < tam; ++i)
	{
		if(pos[s1[i]-'A'] < pos[s2[i]-'A'])		
			return false;
		if(pos[s1[i]-'A'] > pos[s2[i]-'A'])
			return true;
	}
	if(s1.size()> s2.size())
		return true;
	return false;
}

int main()
{
	int year= 1;
	while(cin>>n)
	{
		if(n == 0) break;
		cin>>alfabeto;
		
		ini();
		
		for(int i = 0; i < n; ++i)
		{
			cin>>strings[i];
		}
		
		for(int i = 0; i < n; ++i)
		{
			for(int j = i+1; j < n; ++j)
			{
				if(comparar(strings[i], strings[j]))
				{
					string a = strings[i];
					strings[i] = strings[j];
					strings[j] = a;
				}
			}
		}
		cout<<"year "<<year<<endl;
		for(int i = 0; i < n; ++i)
		{
			cout<<strings[i]<<endl;
		}
		year++;
	}
	return 0;
}
