/*
 PROBLEM: http://acm.javeriana.edu.co/maratones/forum/viewtopic.php?f=820&t=951&sid=fab36adecb51b45023e8264dbd6e5c74

 AUTHOR:  Melisa Agudelo
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

int main()
{
	long long int x,y;
	while (cin>>x>>y ){
		if (x==0 and y==0)break;
		long long int ent = x/y;
		long long int num = x-(y*ent);
		cout<<ent<<" "<<num<<" / "<<y<<"\n";
	}
	return 0;
}
