#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()
#define MAX 1000010

using namespace std;

typedef long long int LL;

const int MOD = 1000000007;
const double EPS = 0.0000000001;

LL n;
LL p = 9;
int memo[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(memo, -1, sizeof memo);
    memo[0]=memo[1]=memo[2]=memo[3]=memo[4]=memo[5]=memo[6]=memo[7]=0;
    memo[8] = 1;
    while(cin >> n){
        if(n == 0)
            break;
        if(memo[n] != -1)
            cout <<memo[n]<< '\n';
        else{
            for(;p<= n; ++p){
                double test = sqrt((p*p+p)/2.0);
                memo[p] = memo[p-1];
                if(test == (LL)(test+EPS)){
                    memo[p]++;
                }
            }
            assert(memo[n] != -1);
            cout << memo[n]<< '\n';
        }
    }

    return 0;
}
