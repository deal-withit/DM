#include<bits/stdc++.h>

using namespace std;

int min_sup_count = 2;

fstream wrt, rd;

map<vector<string>, int> ss_freq;

vector<string> split(string &x) {
    vector<string> res;
    string a;
    stringstream obj(x);
    while (obj >> a) {
        res.push_back(a);
    }
    return res;
}

map<string, vector<string>> transaction_reader(string file_name) {
    rd.open(file_name, ios::in);
    map<string, vector<string>> res;
    string s;
    while (getline(rd, s)) {
        vector<string> A = split(s);
        for (int i = 1; i < A.size(); i++) {
            res[A[0]].push_back(A[i]);
        }
    }
    return res;
}

void subset(int i, vector<string> &A, vector<string> &S, vector<vector<string>> &Ans) {
    if (i == A.size()) {
        if (!S.empty()) Ans.push_back(S);
        return;
    }
    S.push_back(A[i]);
    subset(i + 1, A, S, Ans);
    S.pop_back();
    subset(i + 1, A, S, Ans);
}

map<vector<string>, int> subset_freq(map<string, vector<string>> &data) {
    map<vector<string>, int> ss_freq;

    vector<string> S;
    vector<vector<string>> ss;
    unordered_set<string> unq;

    for (auto i : data) {
        S.clear();
        ss.clear();
        subset(0, i.second, S, ss);
        for (auto k : ss) ss_freq[k]++;
    }

    return ss_freq;

}

vector<vector<string>> F(vector<string> &A, int i, int k) {
    if (k == 0) return vector<vector<string>> {{}};
    vector<vector<string>> ans;
    for (int j = i; j < A.size(); j++) {
        vector<vector<string>> T = F(A, j + 1, k - 1);
        for (auto v : T) {
            v.push_back(A[j]);
            ans.push_back(v);
        }
    }
    return ans;
}

vector<vector<string>> k_subset(vector<string> A, int k) {
    return F(A, 0, k);
}

int main() {
    map<string, vector<string>> data = transaction_reader("input.txt");

    ss_freq = subset_freq(data);

    set<string> unq;
    int max_trans = 0;

    for (auto i : data) {
        max_trans = max(max_trans, int(i.second.size()));
        for (auto k : i.second) unq.insert(k);
    }

    vector<string> unq_items(unq.begin(), unq.end());

    int K = 1;



    vector<vector<string>> pruned, final;

    while (K <= max_trans) {

        vector<vector<string>> lk_substet = k_subset(unq_items, K);

        final = pruned;
        pruned.clear();

        for (auto i : lk_substet) {
            vector<string> temp = i; sort(temp.begin(), temp.end());
            if (ss_freq[temp] >= min_sup_count) {
                bool ok = 1;
                vector<vector<string>> res;
                vector<string> x;
                subset(0, temp, x, res);
                for (auto j : res) {
                    if (ss_freq[j] < min_sup_count) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) pruned.push_back(temp);
            }
        }

        cout << "\nC" << K << " :\n";

        if (pruned.empty()) cout << "Blank\n";
        else {
            for (auto i : pruned) {
                for (auto k : i) cout << k << ' ';
                cout << '\n';
            }
        }

        if (pruned.empty()) break;


        unq.clear();
        unq_items.clear();

        for (auto i : pruned) {
            for (auto k : i) unq.insert(k);
        }

        for (auto i : unq) unq_items.push_back(i);

        K++;
    }

    wrt.open("output.txt", ios::out);

    cout << "\n\nFinal frequent itemsets found are : \n\n";
    for (auto i : final) {
        for (auto k : i) cout << k << ' ', wrt << k << ' ';
        cout << "\n\n", wrt << "\n\n";
    }
}