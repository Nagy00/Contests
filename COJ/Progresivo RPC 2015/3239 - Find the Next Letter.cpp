#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()
#define MAX 30

using namespace std;

typedef long long int LL;

const int MOD = 1000007;
const double EPS = 0.0000000001;

vector <int> v[MAX];

int binary (int& p, int obj)
{
    int last = -1;
    int min = 0, max = v[p].size()-1;
    while(min <= max){
        int mid = (max-min)/2+min;
        int item = v[p][mid];
        if(item == obj)
            return mid;
        if(item > obj){
            last = item;
            max = mid - 1;
        }
        else
            min = mid + 1;
    }
    return last;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;cin >> T;
    for(int t = 0; t < T; ++t){
        int n;
        string s;
        cin >> n >> s;
        assert(n == s.size());
        for(int i = 0; i < n; ++i){
            int p = s[i] - 'a';
            for(int j = 0; j < p; ++j)
                v[j].push_back(i+1);
        }

        for(int i = 0; i < n; ++i){
            int p = s[i] - 'a';
            cout << binary(p,i+1)<<" ";
        }
        cout << '\n';

        for(int i = 0; i < MAX; ++i)
            v[i].clear();
    }

    return 0;
}

