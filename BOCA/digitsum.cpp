/*
 PROBLEM: http://acm.javeriana.edu.co/maratones/forum/viewtopic.php?f=706&t=844&sid=ca13060eb4f374c0c166801002ae43b8
 
 AUTHORS: Juan Felipe Cañizares Corrales 		  
          Systems Engineer [Student]
	  	  Universidad Católica de Oriente
          pipecaniza@outlook.com	  
          
          Brian Giraldo Echeverri
          Systems Engineer [Student]
	  	  Universidad Católica de Oriente

 LICENCE: MIT License
 	
 Copyright (C) 2013 Juan Felipe Cañizares Corrales & Brian Giraldo Echeverri
                    
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
vector<string> numero;

void change(int ini)
{
	for(int i=ini; i < n; i+=2)
	{
		if(numero[i]!= "0")
		{
			numero[ini] = numero[i];
			numero[i] = "0";
			break;
		}
	}
}

int main()
{
	while(cin>>n)
	{
		if(n == 0)break;
		for(int i = 0; i < n; ++i)
		{
			string s;
			cin>>s;
			numero.push_back(s);
		}
		
		sort(numero.begin(),numero.end());
		if(numero[0] == "0")
		{
			change(0);
		}
		if(numero[1] == "0")
		{
			change(1);
		}
		
		string num1,num2;
		
		for(int i = 0; i < n; ++i)
		{
			if(i % 2 == 0)
			{
				num1+= numero[i];
			}
			else
			{
				num2+= numero[i];
			}
		}
		
		int a = atoi(num1.c_str());
		int b = atoi(num2.c_str());
		
		cout<<a+b<<endl;
		numero.clear();		
	}
	return 0;
}
