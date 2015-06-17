#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()
#define MAX 500005

using namespace std;

const int MOD = 1000000007;
const double EPS = 0.0000000001;

typedef long long int LL;

vector<LL> ans [15];
bool used [MAX];
LL l;

bool backtracking(LL p, LL& s, LL& sum, LL& n)
{
    for(LL i = l; i > 0; --i){
        if(sum + i > s or used[i])continue;
        used[i] = true;
        ans[p].push_back(i);
        sum = sum +i;
        if(i == l-1)l--;
        if(sum == s)
            return true;
    }

    assert(s == sum);
}

inline void prLL(LL k)
{
    for(LL i = 0; i < k;++i){
        cout << ans[i].size() << '\n';
        for(LL j = ans[i].size()-1; j >= 0; --j)
            cout << ans[i][j] << " ";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL N,K;
    cin >> N >> K;
    double sum = (double)(N*(N+1)/2)/(double)K;

    if(sum != (LL)sum){
        cout << "NO\n";return 0;
    }
    LL value = (LL)sum;
    LL psum = 0;
    l = N;
    for(LL i = 0; i < K; ++i){
        psum = 0;
        backtracking(i, value,psum,N);
    }
    prLL(K);

    return 0;
}

