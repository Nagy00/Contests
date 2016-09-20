#include <bits/stdc++.h>

using namespace std;

int M,W;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    for(int c=0; c < n; ++c)
    {
        cin >> M >> W;
        vector<int> w;
        for(int i = 0; i < M; ++i){
            int w_i; cin >> w_i;
            w.push_back(w_i);
        }
        sort(w.begin(), w.end());
        int ans = 0, i = 0;
        for(; i < M; ++i){
            if(w[i] + ans > W)
                break;
            ans += w[i];
        }
        cout << i << '\n';

    }
    return 0;
}

