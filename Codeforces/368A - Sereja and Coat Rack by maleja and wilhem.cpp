/*
 PROBLEM: http://codeforces.com/problemset/problem/368/A

 AUTHORS: Maria Alejandra Ocampo
          Systems Engineer [Student]
		  Universidad Católica de Oriente
		  
		  Wiliam Valencia
		  Systems Engineer [Student]
		  Universidad Católica de Oriente
		 
 LICENCE: MIT License
 	
 Copyright (C) 2013 Maria Alejandra Ocampo, Wiliam Valencia
                    
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
 #include <vector>
 #include <algorithm>
 using namespace std;
 int main ()
 {
 	int ganchos,personas,pierde,gana,multa;
 	vector<int> precio;
 	while(cin >> ganchos >> multa)
 	{
 		precio.clear();
 		for (int i = 0; i < ganchos; ++i)
 		{	
			int a;
 			cin >> a;
 			precio.push_back(a);
 		
 		}
 		cin >> personas;
 		sort(precio.begin(),precio.end());
 		if (ganchos < personas)
 		{
 			pierde = (personas - ganchos) * multa; 		
 		}
 		else
 		{
 			pierde = 0;
 		}
 		gana = 0;
 		for (int i = 0; i < personas; ++i)
 		{ 	
			if (i >= ganchos)
 				break;
 			
 			gana += precio[i];
 		}
 		cout<<gana - pierde<<endl;
 	}
 }
