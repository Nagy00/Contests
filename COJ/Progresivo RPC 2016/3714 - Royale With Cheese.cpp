#include <bits/stdc++.h>

using namespace std;

string S;
string value [28];
bool alph[28];

string tostr(int a)
{
    stringstream ss;    //bastante lento
    ss << a;
    string b;
    ss >> b;
    return b;
}

string policeChange(string n)
{
    for(int i = 0; i < n.size(); ++i){
        if(n[i] == '5')
            n[i] = '2';
        else if(n[i] == '2')
            n[i] = '5';
        else if(n[i] == '9')
            n[i] = '6';
        else if(n[i] == '6')
            n[i] = '9';
    }
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while(cin >> S){
        memset(alph, false, sizeof alph);
        int cur = 1;
        string ans = "";
        for(int i = 0; i < S.size(); ++i){
            if(alph[S[i]-'a'] == false){
                value[S[i]-'a'] = tostr(cur++);
                alph[S[i]-'a'] = true;
            }
            ans += policeChange(value[S[i]-'a']);
        }
        cout << ans << '\n';
    }

    return 0;
}

