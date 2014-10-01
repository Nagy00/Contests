#include <bits/stdc++.h>

using namespace std;

// Casos de prueba
int c;
// Mapa de las especiea
map<string,double>trees;

int main()
{
    while(cin>>c){
        string l; getline(cin,l);
        for(int t = 0; t < c; ++t){
            double pob = 0;
            // Lee las especies del caso de prueba
            while(getline(cin,l)){
                // Termina con linea vacia
                if(l == "")break;
                // Cuenta la especie
                pob++;
                // Si no esta en el mapa lo agrega
                if(!trees.count(l))
                    trees[l]=0;
                // Anade +1 a la cuenta de la especie
                trees[l]++;
            }
            // Recorremos el mapa
            for(map<string,double>::iterator it = trees.begin(); it != trees.end();++it){
                // Imprimimos la especia
                cout<<it->first<<" ";
                // Imprimimos el % con respecto a la poblacion
                cout<<fixed<<setprecision(4)<<(it->second/pob*100)<<"\n";
            }
            trees.clear();
        }
    }
    return 0;
}
