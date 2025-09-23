/**
 * Problema B - Maratona de 2012
 * Título: Tobogan de Bolinhas
 * Categoria: Matemática
 * Solução em C++
 * Problema 1223 do URI
*/

#include <algorithm>
#include <stdio.h>
#include <vector>
#include <math.h>
#define INF 1e4

using namespace std;

class Reta
{
private:
    double a, b;
    int _x, _y;
public:
    Reta(double a, double b, int x, int y) : a(a), b(b), _x(x), _y(y) {};
    double distToPoint(int,int,bool);
};

double Reta::distToPoint(int xp, int yp, bool dir)
{
    double x = ((xp) +(a*yp) -(a*b))/(double)((a*a) +1);
    double y = ((a*x) +b);

    if ((dir && (x > _x)) || (!dir && (x < _x)))
    {
        x = _x;
        y = _y;
    }

    return sqrt((((x -xp)*(x -xp)) + ((y -yp)*(y -yp))));
}

void solve(int n)
{
    vector<pair<int,int>> pontos;
    vector<Reta> segs;

    bool direita = false;
    int l,h,yi,xf,yf,i;
    double ans = INF;
    double a,b,d;

    scanf("%i %i", &l, &h);

    for (i = 0; i < n; i++)
    {
        scanf("%i %i %i", &yi, &xf, &yf);

        if (direita)
        {
            a = (yi -yf)/(double)(l -xf);
            b = (yi -(a*l));
        }
        else
        {
            a = ((yf -yi)/(double)xf);
            b = yi;
        }

        segs.push_back( Reta(a, b, xf, yf) );
        pontos.push_back( {xf, yf} );
        direita = !direita;
    }

    direita = false;

    for (i = 0; i < (n -1); i++)
    {
        d = segs[i+1].distToPoint(pontos[i].first, pontos[i].second, direita);

        if (direita)
            ans = min(ans, min((double)(pontos[i].first), d));
        else
            ans = min(ans, min((double)(l -pontos[i].first), d));

        direita = !direita;
    }

    if (direita)
        ans = min(ans, (double)(pontos[i].first));
    else
        ans = min(ans, (double)(l -pontos[i].first));

    printf("%.2f\n", ans);
}

int main()
{
    int n;

    while (scanf("%i", &n) != EOF)
        solve(n);
    
    return 0;
}
