/*
 PROBLEM: http://acm.javeriana.edu.co/maratones/forum/viewtopic.php?f=823&t=954&sid=92a902d0d0a953bab9cfd04b0de686ab#p1658

 AUTHOR:  Melisa Agudelo
          Systems Engineer [Student]
	      Universidad Católica de Oriente

          Brian Giraldo
          Systems Engineer [Student]
	      Universidad Católica de Oriente

	      Carlos Vergara
          Systems Engineer [Student]
	      Universidad Católica de Oriente

 LICENCE: MIT License

 Copyright (C) 2015

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

#include<bits/stdc++.h>

using namespace std;


int n;
long long int a,b,maxi,mini;

int main()
{
	while(cin>>n){
		int cont=0;
		for (int i=0; i<n; ++i){
			int cont=0;
			cin>>a>>b;
			maxi=max(a,b);
			mini=min(a,b);
			long long int j=1;
			for (; j<=maxi+1; j=j*2){
				if (mini+1>=j){
					cont+=j;
				}
				else {
					cont+=mini+1;
				}


			}
			long long int corte= -maxi+j-1;
			if(corte<=mini)cont+=mini-corte+1;
			cout<<cont<<"\n";
		}

	}

	return 0;
}
