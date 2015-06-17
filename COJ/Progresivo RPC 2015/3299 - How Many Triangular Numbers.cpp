#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()

using namespace std;

typedef long long int LL;

const int MOD = 1000000007;
const double EPS = 0.0000000001;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL a,b;
    while(cin >> a >> b){
        if(a == b and b == 0) return 0;
        LL va = ceil((-1+sqrt(1+8*a))/2)-1;
        LL vb = (-1+sqrt(1+8*b))/2;

        cout << vb-va << '\n';
    }

    return 0;
}

