#include <bits/stdc++.h>

using namespace std;

int c;
map<string,double>trees;


int main()
{
    while(cin>>c){
        string l;getline(cin,l);
        for(int t = 0; t < c; ++t){
            double pob = 0;
            while(getline(cin,l)){
                if(l == "")break;
                pob++;
                if(!trees.count(l))
                    trees[l]=0;
                trees[l]++;
            }
            for(map<string,double>::iterator it = trees.begin(); it != trees.end();++it){
                cout<<it->first<<" ";
                cout<<fixed<<setprecision(4)<<(it->second/pob*100)<<"\n";
            }
            trees.clear();
        }
    }
    return 0;
}
