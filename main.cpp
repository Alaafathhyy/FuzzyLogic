#include <bits/stdc++.h>
#include "DeFuzz.cpp"
#include "point.cpp"
#include "Fuzz.cpp"
#include "Rules.cpp"
#include "output.cpp"

using namespace std;
int NumOfVar, outputN;
vector<point> Output;
vector<pair<string, long double>> inferOutput;
map<string, long double> result;
string Outputname;

void BuildInput() {
    cin >> NumOfVar;
    for (int i = 0; i < NumOfVar; ++i) {
        string VarName;
        long double VarNum;
        cin >> VarName >> VarNum;
        int SetNum;
        cin >> SetNum;
        for (int j = 0; j < SetNum; ++j) {
            point p;
            cin >> p.name >> p.kind;
            if (p.kind == "triangle")
                p.n = 3;
            else p.n = 4;
            for (int k = 0; k < p.n; ++k) {
                long double x;
                cin >> x;
                p.cord.push_back(x);
            }

            Fuzz::membership(VarNum, p);
        }
    }

}

void BuildOutput() {

    cin >> Outputname;

    cin >> outputN;
    for (int i = 0; i < outputN; ++i) {
        point p;
        cin >> p.name >> p.kind;
        if (p.kind == "triangle")
            p.n = 3;
        else p.n = 4;
        for (int k = 0; k < p.n; ++k) {
            long double x;
            cin >> x;
            p.cord.push_back(x);
        }
        Output.push_back(p);

    }
}

void BuildRules() {
    int NumOfRules;
    cin >> NumOfRules;
    for (int i = 0; i < NumOfRules; i++) {
        output a;
        string line;
        int n;
        cin >> n;
        getline(cin, line);
        istringstream iss(line);
        vector<string> test1;
        for (string s; iss >> s;) {
            if (s == "=" || s == "then")
                continue;
            test1.push_back(s);
            if (s == "AND")
                test1.emplace_back("0");
            if (s == "OR")
                test1.emplace_back("1");
        }
        a.NumOfSides = n;
        a.words.resize(NumOfRules);
        for (int k = 0, h = 0; k < test1.size() && h < test1.size() / 2; k += 2, h++) {
            a.words[h].first = test1[k];
            a.words[h].second = test1[k + 1];
        }
        Rules::modify(a);
    }
}

int main() {
    freopen("input", "rt", stdin);
    freopen("output", "wt", stdout);

    BuildInput();

    BuildOutput();

    BuildRules();

    cout << "MemberSets for all variables" << endl;
    for (auto &i:result)
        cout << i.first << " " << i.second << endl;
    cout << endl;

    cout << "The final output from the Rules" << endl;
    for (auto &i:inferOutput)
        cout << i.first << " " << i.second << endl;
    cout << endl;

    DeFuzz deFuzz; //init all centeriod points for all the output shapes

    cout << "Centriod point for all the shapes of output" << endl;
    for (auto &i:deFuzz.centroidMap)
        cout << i.first << " " << i.second << endl;
    cout << endl;

    cout << Outputname << " = " << deFuzz.CalcOuptput();

}
