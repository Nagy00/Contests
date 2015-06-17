#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int i = 0; i < T; ++i){
        long long int n; cin >> n;
        string s; cin >> s;
        n = n % s.size();

        cout << s.substr(s.size()- n) << s.substr(0,s.size()- n) <<'\n';
    }
    return 0;
}
