#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const double EPS = 0.0000000001;
static int values [] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
static int ones [] =   {0,1,1,2,1,2,2,3,1,2,2 ,3 ,2 ,3 , 3, 4, 1, 2};
int ans;

void solve (int u, int val, int max, int k)
{
    int v = values[u];
    int new_val = v ^ val;

    if(u+1 <= max){
        solve(u+1, val, max, k);
    }else if(ones[val] == k) ans++;
    if(u+1 <= max){
        solve(u+1, new_val, max, k);
    }else if(ones[new_val] == k) ans++;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    while(cin >> n >> k){
        ans = 0;
        int max = (int)(pow(2,n)+EPS);
        solve(0,0,max-1,k);
        cout << ans << '\n';
    }

    return 0;
}
