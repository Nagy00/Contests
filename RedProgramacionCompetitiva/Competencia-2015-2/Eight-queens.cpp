/*
 PROBLEM: http://acm.javeriana.edu.co/maratones/forum/viewtopic.php?f=815&t=946&sid=47fbcc6bea172a468ba149bfdde298de#p1650

 AUTHOR:  Melisa Agudelo
          Systems Engineer [Student]
	      Universidad Católica de Oriente

	      Daniel Cañizares
	      Systems Engineer [Professor]
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

char a[8][8];
int direcciones[8][2] =
{
    1,0,
    1,0,
    1,1,
    0,-1,
    -1,0,
    -1,-1,
    1,-1,
    -1,1
};
const int DIRECCIONES = 8;

bool verificar(int f, int c, int dx, int dy){
	while(true){
		f+=dx;
		c+=dy;
		if (f<0 or f>7 or c<0 or c>7) return true;
		if (a[f][c]=='*') return false;
	}
}

bool validar_reina(int f, int c){
    for(int i = 0; i < DIRECCIONES; ++i){
        if(!verificar(f,c,direcciones[i][0], direcciones[i][1]))
            return false;
    }
    return true;
}

int main()
{
	while (cin>>a[0][0]){
		for(int i=0;i<8; ++i){
			for (int j=0; j<8; ++j){
				if(i==0 and j ==0) continue;
				cin>>a[i][j];
			}
		}
		bool valido = true;
		int reinas=0;
		for(int i=0;i<8; ++i){
			for (int j=0; j<8; ++j){
				if(a[i][j] != '*')
                    continue;

				if(!validar_reina(i,j)){
				   	valido = false;
				   	break;
				}
				++reinas;
			}
		}

		if(valido and reinas == 8)
            cout<<"valid\n";
		else
            cout<<"invalid\n";
	}
	return 0;
}
