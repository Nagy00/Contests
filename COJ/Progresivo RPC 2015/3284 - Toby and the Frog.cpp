#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()
#define MAX 5005

using namespace std;

const int MOD = 1000000007;
const double EPS = 0.0000000001;

double ev [MAX];

double solve (int X)
{
    for(int i = X-1; i >= 0; --i){
        ev[i] = 1;
        int to = min(X - i,10);
        double dist = 1.0/to;
        for(int j = 1; j <= to; ++j){
            ev[i] += ev[i+j]*dist;
        }
    }
    return ev[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for(int test = 0; test < T; ++test){
        int X; cin >> X;
        memset(ev, 0, sizeof ev);
        cout <<fixed << setprecision(10)<<solve(X)<<'\n';
    }

    return 0;
}
