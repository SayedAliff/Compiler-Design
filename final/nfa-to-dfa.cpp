#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 9;
vector<int> nfa[N][2];
vector<int> eps[N];

set<int> epsilon_closure(const set<int>& states) {
    set<int> result = states;
    queue<int> q;
    for (int s : states) q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : eps[u]) {
            if (!result.count(v)) {
                result.insert(v);
                q.push(v);
            }
        }
    }
    return result;
}

set<int> move(const set<int>& current_states, int symbol) {
    set<int> next;
    for (int u : current_states) {
        for (int v : nfa[u][symbol]) {
            next.insert(v);
        }
    }
    return next;
}

int main() {
    eps[0] = {1, 3, 7};
    nfa[1][0] = {2};
    nfa[3][0] = {4};
    nfa[7][0] = {7};
    nfa[4][1] = {5};
    nfa[5][1] = {6};
    nfa[7][1] = {8};
    nfa[8][1] = {8};

    set<int> nfa_final = {2, 6, 8};

    map<set<int>, size_t> dfa_state_id;
    vector<set<int>> dfa_states;
    vector<vector<int>> dfa_transitions;
    vector<bool> dfa_final_state;

    set<int> start = epsilon_closure({0});
    dfa_state_id[start] = 0;
    dfa_states.push_back(start);
    dfa_transitions.push_back(vector<int>(2, -1));
    dfa_final_state.push_back(any_of(start.begin(), start.end(), [&](int x){return nfa_final.count(x);}));

    queue<size_t> q;
    q.push(0);

    while (!q.empty()) {
        size_t u = q.front(); q.pop();
        for (int symbol = 0; symbol < 2; symbol++) {
            set<int> next = epsilon_closure(move(dfa_states[u], symbol));
            if (next.empty()) continue;
            if (!dfa_state_id.count(next)) {
                size_t id = dfa_states.size();
                dfa_state_id[next] = id;
                dfa_states.push_back(next);
                dfa_transitions.push_back(vector<int>(2, -1));
                dfa_final_state.push_back(any_of(next.begin(), next.end(), [&](int x){return nfa_final.count(x);}));
                q.push(id);
            }
            dfa_transitions[u][symbol] = dfa_state_id[next];
        }
    }

    cout << "DFA states and their corresponding NFA subsets:\n";
    for (size_t i = 0; i < dfa_states.size(); ++i) {
        cout << "DFA State " << i << " = {";
        for (auto it = dfa_states[i].begin(); it != dfa_states[i].end(); ++it) {
            if (it != dfa_states[i].begin()) cout << ",";
            cout << *it;
        }
        cout << "}";
        if (dfa_final_state[i]) cout << " (final)";
        cout << "\n";
    }

    cout << "\nDFA transitions:\n";
    for (size_t i = 0; i < dfa_states.size(); ++i) {
        for (int symbol = 0; symbol < 2; ++symbol) {
            if (dfa_transitions[i][symbol] != -1) {
                cout << "From " << i << " on '" << (symbol == 0 ? 'a' : 'b') << "' -> " << dfa_transitions[i][symbol] << "\n";
            }
        }
    }
    return 0;
}