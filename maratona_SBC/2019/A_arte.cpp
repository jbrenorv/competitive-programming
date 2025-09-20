/**
 * Problema A - Maratona de 2019
 * Título: Arte Valiosa
 * Categoria: Matemática, Geometria
 * Solução em C++
 * Problema 2962 do URI
*/

#include <iostream>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;
typedef long long i64;

// estrutura p/ os segmentos
struct seg
{
    int esq = 0, dir = 0;
    int cma = 0, bxo = 0;

    void clear()
    {
        esq = dir = cma = bxo = 0;
    }
};

// estrutura p/ os circulos
struct circulo
{
    int x, y, r;
    bool v = false;
};

vector<circulo> circulos;
vector<circulo> cir;
vector<seg> segs;

seg solve(vector<circulo>::iterator it, seg atual)
{    
    for (; it != circulos.end(); it++)
    {
        // ver se ainda nao faz parte de um segmento
        if (!(it->v))
        {
            // intera pelos circulos que fazem parte do segmento atual
            // e ver se *it compartilha area com algum deles
            for (circulo b : cir)
            {
                // ver se *it e b possuem area em comum
                i64 d = ((it->x - b.x)*(it->x - b.x) + (it->y - b.y)*(it->y - b.y));
                i64 r = ((it->r + b.r)*(it->r + b.r));
                
                if (d <= r)
                {
                    // se sim atualiza o seg atual
                    atual.cma = max(atual.cma, (it->y + it->r));
                    atual.bxo = min(atual.bxo, (it->y - it->r));
                    atual.esq = min(atual.esq, (it->x - it->r));
                    atual.dir = max(atual.dir, (it->x + it->r));

                    it->v = true;
                    cir.push_back(*it);
                    break;
                }
            }
        }
    }

    return atual;
}

// encontra todos os segmentos e coloca em * segs *
void make_segs(int k)
{
    seg atual;
    vector<circulo>::iterator it;

    // intera por todos os circulos
    for (int i = 0; i < k; i++)
    {
        it = circulos.begin()+i;
    
        // se esse circulo *it nao faz parte de um segmento ainda:
        if (!(it->v))
        {
            // cria um segmento iniciando com ele
            it->v = true;
            cir.push_back(*it);

            // o segmento atual tem as dimencoes de *it 
            // pois apenas ele esta inicialmente neste segmento
            atual.cma = (it->y + it->r);
            atual.bxo = (it->y - it->r);
            atual.esq = (it->x - it->r);
            atual.dir = (it->x + it->r);

            atual = solve(it, solve(it, atual));

            segs.push_back(atual);
            atual.clear();
            cir.clear();
        }
    }
}

bool is_possible(int m, int n)
{
    for (seg a : segs)
    {
        if ((a.esq <= 0 && a.dir >= m) || (a.bxo <= 0 && a.cma >= n) || 
            (a.dir >= m && a.cma >= n) || (a.bxo <= 0 && a.esq <= 0))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int m,n,k;
    int x,y,r;
    circulo a;

    cin >> m >> n >> k;
    
    for (int i = 0; i < k; i++)
    {
        cin >> a.x >> a.y >> a.r;
        circulos.push_back(a);
    }
    
    make_segs(k);

    if (is_possible(m, n))
        cout << "S" << endl;
    else
        cout << "N" << endl;

    return 0;
}
