#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()
#define MAX 1050

using namespace std;

typedef long long int LL;

const int MOD = 1000007;
const double EPS = 0.0000000001;

LL DP [MAX];

LL mPow(LL ex)
{
    LL c = 1, e = 1;
    for(; e <= ex; ++e)
        c = (c*2)%MOD;
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    DP[0] = 0;
    DP[1] = 1;
    for(int i = 2; i <= 1002; ++i){
        DP[i] = (DP[i-1] + (LL)(mPow(i-1)))%MOD;
    }

    int n,m;
    while(cin >> n >> m){
        if(n == m and m == -1) return 0;
        cout << ((DP[m+1]-DP[n])+MOD)%MOD << '\n';
    }

    return 0;
}

