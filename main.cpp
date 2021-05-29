#include <bits/stdc++.h>

using namespace std;
int NumOfVar;
struct point {
    string name, kind;
    int n;
    vector<int> cord;
};
vector<int> info;

vector<vector<point>> Shapes;
vector<point> Output;
string OutputName;

void Fuzz();

void DeFuzz();

void Enference();

bool PointInShape(point p, int x); // return true incase of Intersection
long double Intersect(point p, int x); // get the intersection between shape(line) and point then return y
long double Centroid(vector<point> v);


int main() {
    cin >> NumOfVar;
    Shapes.resize(NumOfVar);
    for (int i = 0; i < NumOfVar; ++i) {
        string VarName;
        int VarNum;
        cin >> VarName >> VarNum;
        info.push_back(VarNum);
        int SetNum;
        cin >> SetNum;
        for (int j = 0; j < SetNum; ++j) {
            point p;
            cin >> p.name >> p.kind;
            if (p.kind == "triangle")
                p.n = 3;
            else p.n = 4;
            for (int k = 0; k < p.n; ++k) {
                int x;
                cin >> x;
                p.cord.push_back(x);
            }
            Shapes[i].push_back(p);
        }
    }
    cin >> OutputName;
    int n;
    cin >> n;
    for (int j = 0; j < n; ++j) {
        point p;
        cin >> p.name >> p.kind;
        if (p.kind == "triangle")
            p.n = 3;
        else p.n = 4;
        for (int k = 0; k < p.n; ++k) {
            int x;
            cin >> x;
            p.cord.push_back(x);
        }
        Output.push_back(p);
    }
// inference to do ...
}
