/**
 * Problema I - Maratona de 2012
 * Título: Integral
 * Categoria: Matemática
 * Solução em C++
 * Problema 1230 do URI
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <stdio.h>
#include <vector>

using namespace std;
#define MAX 1000001
typedef pair<int,int> pii;

struct pto 
{
    int x, miF, maF;
};

vector<vector< pto >> segs;
vector<pii> extms;
vector<pto> seg;
vector<pii> S;

const int INF = MAX+10;
double miA, maA;

void init()
{
    vector<pii>::iterator p;
    pto atual;
    int cnt = 1;

    for (p = S.begin()+1; p != S.end(); p++)
    {
        int mi = min((p-1)->second, p->second);
        int ma = max((p-1)->second, p->second);

        // possiveis pontos entre (p-1) e p
        while (cnt < p->first)
        {
            atual.x = cnt;
            atual.miF = mi;
            atual.maF = ma;

            if (cnt == ((p-1)->first + 1))
            {
                miA += (((p-1)->second - mi)/2.0 + mi);
                maA += (p-1)->second < p->second ? ((ma - (p-1)->second)/2.0 + mi) : ma;
            }
            else
            {
                miA += mi;
                maA += ma;
            }

            seg.push_back(atual);
            cnt++;
        }

        // estou em p olho para traz
        if (p->first == (p-1)->first +1)
        {
            maA += ((ma-mi)/2.0 + mi);
            miA += ((ma-mi)/2.0 + mi);
        }
        else
        {

            if (p->second > (p-1)->second)
            {
                maA += ma;
                miA += ((ma-mi)/2.0 + mi);
            }
            else if (p->second < (p-1)->second)
            {
                maA += ((ma-mi)/2.0 + mi);
                miA += mi;
            }
            else
            {
                maA += ma;
                miA += mi;
            }
        }

        if (!(seg.empty()))
        {
            pii exts;
            exts.first = (p-1)->second;
            exts.second = p->second;
            segs.push_back(seg);
            extms.push_back(exts);
            seg.clear();
        }

        cnt++;
    }
}

void points_update(int y, int t)
{
    if (y == miA)
        return;
    
    vector<vector<pto>>::iterator it = segs.end()-1;
    vector<pii>::iterator et = extms.end()-1;
    vector<pto>::iterator se;

    // devo iterar em segs do fim para o inicil
    for (; it >= segs.begin(); it--)
    {
        int flt = (y - miA);

        // atualiza o seg apontado por it
        if (et->first >= et->second)
        {
            int cmp = (it->back().x - it->front().x +1);
            int num = (flt/cmp);
            
            if (num != 0)
            {
                int aux = min((it->front().maF - it->front().miF), num);
                
                for (se = it->begin(); se != it->end(); se++)
                {
                    se->miF += aux;
                    miA += aux;
                }
            }

            if (miA == y)
                return;

            if (it->front().miF < it->front().maF)
            {
                for (se = it->begin(); se != it->end(); se++)
                {
                    (se->miF)++;
                    miA++;
                    if (miA == y)
                        return;
                }
            }
        }
        else
        {
            int dif = (it->back().maF - it->back().miF);
            int num = (flt/dif);

            for (se = it->end()-1; se >= it->begin(); se--)
            {
                if (num != 0)
                {
                    se->miF = se->maF;
                    miA += dif;
                    num--;
                }
                else
                {
                    while (se->miF < se->maF)
                    {
                        (se->miF)++;
                        miA++;
                        if (miA == y)
                            return;
                    }
                }
            }
        }
        et--;
    }
}

int main()
{
    int n,m,y,x,f;

    while(scanf("%i %i %i", &n, &m, &y) != EOF)
    {
        for (int i = 0; i < m; i++)
        {
            scanf("%i %i", &x, &f);
            S.push_back( make_pair(x, f) );
        }

        sort(S.begin(), S.end());
        init();

        if ((y <= maA && y >= miA) && ((int)(2*y)%2 == (int)(2*miA)%2))
        {
            int t = segs.size();
            points_update(y, t);
            cout << "S";
            
            if (!(segs.empty()))
                for (vector<pto> s : segs)
                    for (pto p : s)
                        cout << " " << p.miF;

            cout << endl;
        }
        else
            cout << "N" << endl;
        
        S.clear();
        seg.clear();
        segs.clear();
        miA = maA = 0;
    }

    return 0;
}
