#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()
#define MAX 1005

using namespace std;

typedef long long int LL;

const int MOD = 1000000007;
const double EPS = 0.0000000001;

vector<int> numbers;
deque<int> polygon;
int N;

string to_str(LL a){
    stringstream ss; string b;
    ss << a; ss >> b;
    return b;
}

LL myop (int a, int b){return (a+b)%100000;}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; ++i){
        int a; cin >> a; numbers.push_back(a);
    }
    sort(ALL(numbers));
    int i=0,j=N-1;
    while(polygon.size() < N){
        if(polygon.size() < N)
            polygon.push_front(numbers[i]);
        if(polygon.size() < N)
            polygon.push_back(numbers[j]);
        if(i > j){--i; ++j;}
        else{++i;--j;}
        swap(i,j);
    }
    LL acumulate[N];
    partial_sum(ALL(polygon), acumulate, myop);

    LL sum = 0;
    for(int i = 0; i < N-2; ++i){
        sum += polygon[i]*((acumulate[N-(i==0 ? 2 : 1)]-acumulate[i+1]+100000)%100000);
        sum %= 100000;
    }

    string ans = to_str(sum);

    int s = ans.size();
    if(s == 1)
        cout << "0000" << ans[s-1] << '\n';
    else if(s == 2)
        cout << "000" << ans[s-2] << ans[s-1] << '\n';
    else if(s == 3)
        cout << "00" << ans[s-3] << ans[s-2] << ans[s-1] << '\n';
    else if(s == 4)
        cout << "0"<< ans[s-4] << ans[s-3] << ans[s-2] << ans[s-1] <<'\n';
    else
        cout << ans[s-5] << ans[s-4] << ans[s-3] << ans[s-2] << ans[s-1] << '\n';

    return 0;
}
