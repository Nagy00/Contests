#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()
#define MAX 105

using namespace std;

typedef long long int LL;

const int MOD = 1000000007;
const int INF = 1<<30;
const double EPS = 0.0000000001;

int n;
int key[MAX];
double p[MAX];             // probability
double e[MAX][MAX];        // cost of subtree
int r[MAX][MAX];           // root of subtree
double w[MAX][MAX];        // weight


void opttree()
{
    int i,j,l,r1;
    double t;
    for (i=1;i<=n+1;i++){
        e[i][i-1]=0;
        w[i][i-1]=0;
    }
    for (l=1;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
            j=i+l-1;
            e[i][j]=INFINITY;
            w[i][j]=w[i][j-1]+p[j];

            for(r1=i;r1<=j;r1++){
                t=e[i][r1-1]+e[r1+1][j]+w[i][j];
                if(t<e[i][j]){
                    e[i][j]=t;
                    r[i][j]=r1;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n){
        for(int i = 1; i <= n; ++i){
            key[i] = i-1;
            cin >> p[i];
        }
        opttree();
        cout <<fixed<<setprecision(6)<< e[1][n]/w[1][n] << '\n';
    }

    return 0;
}
