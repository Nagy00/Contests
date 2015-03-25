/*
 PROBLEM: http://acm.javeriana.edu.co/maratones/forum/viewtopic.php?f=817&t=948&sid=3ac0bec2a99c66b79792c7bc226ca65b#p1652

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
	int w,p,a;
	vector<int>particion;
	int respuesta[100+1];
	while(cin>>w>>p){
		memset(respuesta,0, sizeof(respuesta));
		particion.push_back(0);
		for(int i=0; i<p; ++i){
			cin>>a;particion.push_back(a);
		}
		particion.push_back(w);
		for(int i=0; i<particion.size()-1; ++i){
			for(int j=i+1; j<particion.size(); ++j){
				respuesta[particion[j]-particion[i]]=1;
			}
		}
		for(int i=1; i<=w; ++i){
			if(respuesta[i]==1)cout<<i<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
