/*
 PROBLEM: http://acm.javeriana.edu.co/maratones/forum/viewtopic.php?f=707&t=845&sid=ef7785f5caf041bebb47fdbd9d54f83f
 
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
vector<vector<char> > table;
char pos;
int pos2;
vector<int> positions;

void paint(int i, int j, char target)
{
	if(table[i][j] != target || table[i][j] == '0')
		return;
	if(table[i][j] == target)
	{
		positions.push_back(i);
		positions.push_back(j);
		table[i][j] = '0';
	}
	for(int k = -1; k <=1;++k)	
	{
		if(k == 0)continue;
		if(k+i >= 0 && k+i < 12)
			paint(k+i, j, target);
		if(k+j >= 0 && k+j < 10)
			paint(i, k+j, target);
	}
}

void eraseElement(int j)
{
	for(int i = 11; i >= 0; --i)
	{
		for(int t = j+1; t < 10;++t)
		{
			table[i][t-1] = table[i][t];
		}
		table[i][9] = '0';
	}
}

void gravity(int i, int j)
{
	for(int t = i; t >=0; --t)
	{
		if(table[t][j] != '0')
		{
			table[i][j] = table[t][j];
			table[t][j] = '0';
		}		
	}	
}

int contar()
{
	int c = 0;
	for(int i = 0; i < table.size();++i)
	{
		for(int j = 0; j < table[i].size();++j)
		{
			if(table[i][j]!= '0')
				c++;
		}
	}
	return c;
}

int main()
{
	while(cin>>n)
	{
		if(n == 0)break;
		int tamano = 9;
		for(int i = 0; i < 12; ++i)
		{
			string as;
			cin>>as;
			vector<char> a;
			for(int j = 0; j < 10; ++j)
			{
				a.push_back(as[j]);			
			}
			table.push_back(a);
			a.clear();
		}
		
		
		for(int i = 0; i < n;++i)
		{
			cin>>pos>>pos2;	
			
			int pos1 = pos - 'a';
			pos2= table.size()-(pos2);
			
			positions.clear();
			
			char color = table[pos2][pos1];
			
			if(color == '0') continue;
			
			paint(pos2,pos1,table[pos2][pos1]);
			
			if(positions.size() <= 4)
			{
				table[positions[0]][positions[1]] = color;
				table[positions[2]][positions[3]] = color;	
				continue;			
			}
			
			
			for(int j = 0; j < 10;++j)
			{
				for(int k = 11; k >= 0; --k)
				{					
					if(table[k][j] == '0')
						gravity(k,j);					
				}
				
				if(table[11][j] == '0')
				{
					if(j < tamano)
					{
						eraseElement(j)	;
						tamano--;
						j--;
					}
				}	
			}		
		}
	
		cout<<contar()<<endl;
		table.clear();	
	}
	return 0;
}
