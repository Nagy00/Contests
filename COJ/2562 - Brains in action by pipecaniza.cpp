/*
 PROBLEM: http://coj.uci.cu/24h/problem.xhtml?abb=2562
 
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
#include <map>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

map<int,int> mapa;

void FactoresPrimos(int n)
{
     int z = 2;

     while (z * z <= n){
        if (n % z == 0)
        {
                  if(!mapa.count(z)){
                      mapa.insert(pair<int,int>(z,1));}
                  else{
                      mapa[z]++;}
                  
                  n=n/z;
        }

        else
            z++;
            }
    if (n > 1)
    {
          if(!mapa.count(n)){
               mapa.insert(pair<int,int>(n,1));}
          else{
              mapa[n]++;}
    }
     
}

int main()
{
     int numero;
     while(cin >> numero)
     {
            FactoresPrimos(numero);
            map<int,int>::iterator it;
            string ans="";
            
  
            for (map<int,int>::iterator it=mapa.begin(); it!=mapa.end(); ++it)       
            {      
                string a="",b="";
                stringstream ss;
                stringstream ss1;
                ss << it->first;
                ss>>a;
                ss1 << it->second;
                ss1>>b;
                
                ans+="("+ a+"("+ b +")"+")";
            }

            cout<<ans<<endl;  
            mapa.clear();
     }
    
    return 0;
}
