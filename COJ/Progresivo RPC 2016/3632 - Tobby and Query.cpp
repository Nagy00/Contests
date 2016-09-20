#include <bits/stdc++.h>
/*
Dado un arreglo de numeros de 0 a 9, y un rango, decir cuantos no repetidos hay en dicho rango
*/


using namespace std;

#define MAXN 100005

int n,q,l,r;
int numbers[MAXN];
bool rep[10];
vector<int> ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(cin >> n){
        for(int i = 0; i < n; ++i)
            ans[i].clear();

        for(int i = 0; i < n; ++i)
            cin >> numbers[i];
        for(int i = 0; i < n; ++i){
            memset(rep, false, sizeof rep);
            int nrep = 0;
            ans[i].push_back(0);
            for(int j = i; j < n and nrep < 10; ++j){
                if(!rep[numbers[j]]){
                    rep[numbers[j]] = true;
                    ans[i].push_back(ans[i][ans[i].size()-1]+1);
                    nrep++;
                }
                else
                    ans[i].push_back(ans[i][ans[i].size()-1]);
            }
        }
        cin >> q;
        for(int i = 0; i < q; ++i){
            cin >> l >> r;
            int sol = 0;
            if(ans[l-1].size() <= (r-l))
                sol = 10;
            else
                sol = ans[l-1][(r-l)+1];

            cout << sol <<'\n';
        }
    }


    return 0;
}


