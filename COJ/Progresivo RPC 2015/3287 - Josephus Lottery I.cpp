#include <bits/stdc++.h>

#define ALL(x) x.begin(), x.end()
#define MAX 10010

using namespace std;

typedef long long int LL;

const int MOD = 1000007;
const double EPS = 0.0000000001;

class nodo{
public:
    nodo* back;
    nodo* next;
    int value;

    nodo(nodo* a, nodo* b, int v) : value(v)
    {
        back = a;
        next = b;
    }
    nodo(){}
    ~nodo()
    {
        back = nullptr; next = nullptr;
    }
};

class dclist{
public:
    nodo* first;
    nodo* last;
    nodo* current;
    int size;

    dclist(int n)
    {
        size = 0;
        first = new nodo();
        first->value = n;
        first->next = first;
        first->back = first;
        last = first;
        current = first;
        size++;
    }

    void push_back(int n)
    {
        nodo* new_n = new nodo(last, first, n);
        last->next = new_n;
        first->back = new_n;
        last = new_n;
        size++;
    }

    void delete_current()
    {
        current->back->next = current->next;
        current->next->back = current->back;
        nodo* aux = current;
        current = current->next;
        delete aux;
        size--;
    }

    void operator>> (int n)
    {
        for(int i = 0; i < n; ++i){
            current = current->next;
        }
    }

    void operator<< (int n)
    {
        for(int i = 0; i < n; ++i){
            current = current->back;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    while( cin >> N >> K){
        if(N == K and K == 0)
            break;
        dclist lista(1);
        for(int i = 1; i < N; ++i)
            lista.push_back(i+1);

        bool left = false;
        while(lista.size > 1){
            if(!left)
                lista >> (K-1)%lista.size;

            else
                lista << (K-1) %lista.size;

            lista.delete_current();
            if(left)
                lista << 1;
            left = !left;
        }
        cout << lista.current->value << '\n';
    }

    return 0;
}


