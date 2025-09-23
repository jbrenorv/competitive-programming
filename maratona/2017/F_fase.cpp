/**
 * Problema F - Maratona de 2017
 * Título: Fase
 * Categoria: Lógica, Iniciante
 * Solução em C++
 * Problema 2663 do URI
*/

#include <iostream>
#include <vector>

using namespace std;
 
int main()
{

    int n,k,x,i;
    vector<int> pts(1000, 0);
    cin >> n >> k;

    for(i = 0; i < n; i++)
    {
        cin >> x;
        pts[-x +1000] += 1;
    }

    x = i = 0;

    while (x < k)
        x += pts[i++];

    cout << x << endl;
    return 0;
}