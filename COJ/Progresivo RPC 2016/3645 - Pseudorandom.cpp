#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int a,c,m,x0;
int numbers[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(cin >> a >> c >> m >> x0){
        memset(numbers, -1, sizeof numbers);
        int xn = x0, i = 1, t = 0, s = 0, r = 0;
        numbers[xn] = 0;
        while(true){
            int cur = (a*xn + c)%m;
            if(numbers[cur] == -1){
                numbers[cur] = i++;
            }
            else{
                t = i;
                s = numbers[cur];
                r = i - numbers[cur];
                break;
            }
            xn = cur;
        }
        cout << (t >= m ? "YES " : "NO ") << t << " " << s << " " << r << '\n';

    }


    return 0;
}


