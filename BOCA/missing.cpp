/*
 PROBLEM: http://acm.javeriana.edu.co/maratones/forum/viewtopic.php?f=706&t=844&sid=ca13060eb4f374c0c166801002ae43b8
 
 AUTHORS: 
 		Melisa Agudelo		  
          	Systems Engineer [Student]
	  	 Universidad Católica de Oriente

 LICENCE: MIT License
 	
 Copyright (C) 2013 Melisa Agudelo, William Valencia & Crisman Carmona
                    
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
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	int n,p;
	while(cin>>n)
	{
		if(n == 0)
			break;
		cin>>p;
		if(p > n / 2)
		{
			if(p%2==0)
			{
				cout<<n-p+1<<" "<<n-p+2<<" "<<p-1<<endl;
			}
			else
			{
				cout<<n-p<<" "<<n-p+1<<" "<<p+1<<endl;
			}			
		}
		else
		{
			if(p%2==0)
			{
				cout<<p-1<<" "<<n-p+1<<" "<<n-p+2<<endl;
			}
			else
			{
				cout<<p+1<<" "<<n-p<<" "<<n-p+1<<endl;
			}	
		}
	}
}
