/**
 * Problema D - Maratona de 2017
 * Título: Despojados
 * Categoria: Matemática, Teoria dos números
 * Solução em C++
 * Problema 2661 do URI
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
typedef long long int lli;

vector<lli> fatores;

lli isPrimo(lli n)
{
    for(lli d = 2; d*d < n+1; d++)
        if( n%d == 0 )
            return d;

    return 0;
}

void fatora(lli n)
{
    if(n < fatores.back())
        return;

    lli p = isPrimo(n);

    if(p == 0 && n > fatores.back())
        fatores.push_back(n);
    else if(p)
    {
        fatora(p);
        fatora(n/p);
    }
}

int main()
{
    lli n, ans, aux;
    cin >> n;

    fatores.push_back(1);
    fatora(n);
    aux = fatores.size()-1;
    ans = aux < 2 ? 0 : (pow(2, aux))-aux-1;

    cout << ans << endl;
    return 0;
}
