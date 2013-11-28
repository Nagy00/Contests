/*
 PROBLEM: http://codeforces.com/problemset/problem/363/C
 
 NOTES:   Based on this solution: http://codeforces.com/blog/entry/9537
 		  I tried another algorithm but it got time limit error.
 
 AUTHOR:  Daniel Cañizares Corrales
          Systems Engineer [Professor]
		  Universidad Católica de Oriente
          dacanizares@outlook.com
		  		 
 LICENCE: MIT License
 	
 Copyright (C) 2013 Daniel Cañizares Corrales
                    
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

using namespace std;

int main()
{
	string word;
	while(cin >> word)
	{
		string ans = "";
		for(int i = 0; i < word.size(); ++i)
		{
			char ch = word[i];
			int p  = ans.size()-1;
			if(p >= 1 && ch == ans[p] && ch == ans[p-1])
				continue;
			if(p >= 2 && ch == ans[p] && ans[p-1] == ans[p-2])
				continue;
			ans += ch;			
		}
		cout << ans << endl;
	}
	return 0;
}
