#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL N, T;
char D;

LL move(LL p)
{
    if(D == 'R')
        p = (p+T%N);
    else
        p = N-(abs(p-T)%N);

    return p*2;
}


int main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(NULL); cout.tie(NULL);

    while(cin >> N >> T >> D){
        string m, text;
        getline(cin, m);
        getline(cin, m);
        getline(cin, text);
        getline(cin, m);
        string t = "", t2 = "";
        LL p = 1;
        assert(text[0] == '|');
        for(LL i = 1; i < text.size(); i += 2){
            t += text[i];
            text[i] = ' ';
        }
        /*for(int i = 1; i < text.size(); i += 2){
            char c = text[i];
            if(c != '|' and c != ' '){
                t += c;
                text[i] = ' ';
                p = p == -1 ? i : p;
            }
            else if(t != "")
                break;
        }
        if(text.size() > t.size() and text[text.size()-2] != ' '){
            for(int i = text.size() - 2; i >= 0; i-=2 ){
                if(text[i] == ' '){
                    p = i+2;
                    break;
                }
                t2 = text[i] + t2;
                text[i] = ' ';
            }
        }
        t = t2 + t;*/

        p = move((p+1)/2)-1;
        assert(p < text.size()); assert(p >= 0);
        for(LL i = 0; i < t.size(); p += 2, ++i){
            if(p >=text.size())
                p = 1;
            text[p] = t[i];
        }
        cout << m<< '\n' << text << '\n' << m << '\n';
    }

    return 0;
}

