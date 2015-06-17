#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;
    while(cin >> s){
        if(s == 0)
            break;
        int val = floor((-1+sqrt(1+8*s))/2.0)+1;
        int sum = val*(val+1)/2;
        cout << sum - s << " " << val << '\n';
    }

    return 0;
}
