/*PROBLEM: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5028

AUTHOR:  Juan Felipe Cañizares Corrales
         Systems Engineer [Professor]
         Universidad Católica de Oriente
         pipecaniza@outlook.com

LICENCE: MIT License

Copyright (C) 2016 Juan Felipe Cañizares Corrales

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:


The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.


THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.
*/

#include <bits/stdc++.h>

#define INF 1E+37
#define EPSILON 0.00001

using namespace std;

struct point{
    double x,y;
    bool operator != (point& a)
    {
        return x != a.x || y != a.y;
    }
    point(double _x, double _y) : x(_x), y(_y){}
};

double distance(const point& a, const point& b)
{
    return sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2));
}

double dot(const point& s, const point& v)
{
    return v.x * s.x + v.y * s.y;
}

inline void correct_point(point& a, point& b)
{
    a.x -= b.x;
    a.y -= b.y;
}
inline void restore_point(point& a, point& b)
{
    a.x += b.x;
    a.y += b.y;
}

point proyection(point s, point v)
{
    double value = dot(s,v)/dot(s,s);
    s.x *= value;
    s.y *= value;
    return s;
}

bool is_point_on_line(point linePointA, point linePointB, point p)
{
    if(distance(linePointA, p) + distance(p, linePointB) - distance(linePointA,linePointB) <= EPSILON)
        return true;
    return false;
}

void find_min_segment(vector<point>& polygon, point& center, double& ans)
{
    for(int i = 0; i < polygon.size(); ++i){
        point current = polygon[i];
        point next = polygon[(i+1)%polygon.size()];
        point n_center = center;
        correct_point(next, current);
        correct_point(n_center, current);
        point proy_vector = proyection(next, n_center);
        restore_point(proy_vector, current);
        restore_point(next, current);

        if(is_point_on_line(current, next, proy_vector))
            ans = min(ans, distance(proy_vector, center));
    }
}


int main()
{
    string sn;
    vector<point> polygon;
    double ans;
    while(cin >> sn){
        if(sn == "*")
            break;
        int n = atoi(sn.c_str());
        ans = INF;
        double a,b;
        cin >> a >> b;
        point center(a,b);

        for(int i = 0; i < n; ++i) {
            cin >> a >> b;
            point p(a,b);
            polygon.push_back(p);
            ans = min(distance(center,p), ans);
        }
        find_min_segment(polygon, center, ans);
        ans *= 1000;
        ans = round(ans);
        ans /= 1000;
        cout << fixed << setprecision(3) <<ans << '\n';
        polygon.clear();
    }
    return 0;
}
