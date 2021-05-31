//
// Created by Alaa on ٣١/٠٥/٢٠٢١.
//

#include "Rules.h"

void Rules::calc(vector<pair<string, long double>> &update, string &oper) {
    for (int i = 0; i < update.size(); i++) {
        if (update[i].first == oper) {
            long double temp;
            if (oper == "AND") temp = min(update[i - 1].second, update[i + 1].second);
            else temp = max(update[i - 1].second, update[i + 1].second);
            update.erase(update.begin() + i - 1, update.begin() + i + 2);
            update.insert(update.begin() + i - 1, {"", temp});
        }

    }

}

void Rules::modify(output &out) {
    vector<pair<string, long double>> update(out.words.size());
    for (int i = 0; i < out.words.size(); i++) {
        update[i].first = out.words[i].first;
        if (update[i].first != "OR" && update[i].first != "AND") update[i].second = result[out.words[i].second];
    }
    Rules::calc(update, (string &) "AND");
    Rules::calc(update, (string &) "OR");
    if (update[0].second != 0.0)
        inferOutput.emplace_back(out.words.back().second, update[0].second);

}
