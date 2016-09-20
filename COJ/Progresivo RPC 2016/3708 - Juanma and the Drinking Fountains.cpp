#include <bits/stdc++.h>

using namespace std;

int n,c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> c;
    for(int i = 0; i < c; ++i){
        cin >> n;
        int s=(n*n*n*n-6*n*n*n+23*n*n-18*n+24)/24;
        cout << s << '\n';
    }


    return 0;
}


