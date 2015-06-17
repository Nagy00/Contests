#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()
#define MAXN 100005

using namespace std;

typedef long long int LL;

const LL MOD = 1000000007;
const double EPS = 0.0000000001;
const LL INF = 1<<30;

LL N,M;

LL ns [MAXN];
vector<LL> ms;

LL binary(LL _min, LL _max)
{
    if(_min > _max) swap(_min,_max);
    if(_min >= ms[M-1]) return ms[M-1];
    if(_max <= ms[0]) return ms[0];
    bool to_end = _min == _max ? true : false;
    LL top = M-1, bot = 0;
    LL last_min = 0, last_max = 0;

    while(top >= bot){
        LL mid = (top+bot)/2;
        LL val = ms[mid];

        if(to_end and val == _min)
            return val;
        if(!to_end and val >= _min and val <= _max)
            return val;
        if(val < _min){
            last_min = val;
            bot = mid + 1;
        }
        else if(val > _max){
            last_max = val;
            top = mid - 1;
        }
    }
    if(abs(last_min-_min) < abs(last_max-_max))
        return last_min;
    return last_max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> N >> M){
        ms.clear();
        for(LL i = 0; i < N; ++i)
            cin >> ns[i];


        for(LL i = 0; i < M; ++i){
            LL a; cin >> a;
            ms.push_back(a);
        }

        sort(ALL(ms));
        LL a=-1;
        LL ans = 0;
        bool init = true;
        for(LL i = 0; i < N; ++i){
            if(ns[i] != 0 and init){
                if(a != -1)
                    ans += abs(ns[i]-a);
                a = ns[i];
            }
            else if(ns[i] != 0 and !init){
                if(a == -1){
                    LL value = binary(ns[i],ns[i]);
                    ans += abs(ns[i]-value);
                }
                else{
                    LL value = binary(a,ns[i]);
                    ans += abs(ns[i]-value)+ abs(a-value);
                }
                init = true;
                a = -1;--i;
            }
            else if(ns[i] == 0){
                init = false;
            }
        }
        if(ns[N-1] == 0){
            if(a != -1){
                LL value = binary(a,a);
                ans += abs(a-value);
            }
        }


        cout <<ans<<'\n';

    }

    return 0;
}

