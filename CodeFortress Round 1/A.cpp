/*
 PROBLEM SET: http://1drv.ms/1m1QHco
 PROBLEM A
 
 TEAM: Alpha Centauri
 
 AUTHORS: Juan Felipe Cañizares Corrales
          Systems Engineer [Student]
	  	  Universidad Católica de Oriente
          pipecaniza@outlook.com
		  
		  Leidy Melisa Agudelo S.
          Systems Engineer [Student]
	  	  Universidad Católica de Oriente
          magudelo169@gmail.com
		  
		  Brian Giraldo Echeverri
          Systems Engineer [Student]
	  	  Universidad Católica de Oriente
          briangiraldo123@hotmail.com	  

 LICENCE: MIT License
 	
 Copyright (C) 2014 Alpha Centauri
                    
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

int p, d;

int main()
{
	while(cin>>p>>d)
	{
		int ans = d/p;
		int ans2 = d%p;
		cout<<ans<<" LAPS "<<ans2<<" EXTRA METERS"<<endl;
	}
	return 0;
}

