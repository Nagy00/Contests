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
int const MAXN = 4100;
int arreglo[MAXN];
int solucionar2(int actual,int a)
{
	if(actual<a)
	{
		return 0;
	}
	else if(actual==a)
	{
		return 1;
	}
	else if(arreglo[actual-a]==0)
	{
		return 0;
	}
	else
	{
		return arreglo[actual-a]+1;
	}
}
int solucionar(int n,int a,int b,int c)
{
	for(int i=1;i<=n;i++)
	{
		arreglo[i] = max(max(solucionar2(i,a),solucionar2(i,b)),solucionar2(i,c));
	}
	return arreglo[n];
}
int main()
{
	int n,a,b,c;
	while(cin>>n>>a>>b>>c)
	{
		for(int i=0;i<MAXN;i++)
		{
			arreglo[i] = 0;
		}
		cout<<solucionar(n,a,b,c)<<endl;;
	}
	return 0;
}

