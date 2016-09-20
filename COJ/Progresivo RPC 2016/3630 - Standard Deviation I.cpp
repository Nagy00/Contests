#include <bits/stdc++.h>

using namespace std;

long long int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(cin >> n){
        if(n == 0)
            break;
        long double diff = 0.0;
        /*for(int i = n-1; i > 0; i -= 2){
            diff += (double)i*(double)i;
            if(i <= 1)
                break;
        }
        diff *= 2;
        diff /= (n-1);*/
        diff = sqrt(((n*n)-1)/12)*2;
        cout << fixed << setprecision(6) << diff << '\n';
    }

    return 0;
}

