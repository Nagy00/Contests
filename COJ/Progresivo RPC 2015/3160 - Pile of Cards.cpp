#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()
#define MAX 1005

using namespace std;

const int MOD = 1000000007;
const double EPS = 0.0000000001;

int N;
string a,b;
string ans = "";

int dp [MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> a >> b;
    dp[0][0] = 0;
    #define o(x) (x=='1' ? 1 : -1)

    for(int i = 1; i <=N; ++i){
        dp[0][i] = o(a[i-1]) + dp[0][i-1];
        dp[i][0] = o(b[i-1]) + dp[i-1][0];
    }

    for(int i = 1; i <=N; ++i){
        for(int j = 1; j <=N; ++j){
            if(dp[i-1][j] < 2 and dp[i-1][j] > -2)
                dp[i][j] = o(b[i-1]) + dp[i-1][j];
            else if (dp[i][j-1] < 2 and dp[i][j-1] > -2)
                dp[i][j] = o(a[j-1]) + dp[i][j-1];
            else
                dp[i][j] = 2;
        }
    }
    #undef o

    find(N,N);
    reverse(ALL(ans));

    cout << ans << '\n';

    return 0;
}
