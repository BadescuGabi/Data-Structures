//
// Created by Gabi on 26.04.2020.
//

#ifndef UNTITLED2_DIRECTEDGRAPH_H
#define UNTITLED2_DIRECTEDGRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <deque>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;

class directedGraph {
    vector<pair<int, list<int>>> A;
    int max;
public:
    directedGraph() {
        cout << "valoarea maxima a nodului introdus in graf este: ";
        cin >> max;
        A.resize(max + 1);
        for (int i = 1; i <= max; i++)
            A[i].first = 0;
    }

    void addNode(int b) {
        A[b].first = b;
    }

    void addEdge(int a, int b) {
        A[a].second.push_back(b);
    }

    int hasEdge(int a, int b) {
        for (auto it = A[a].second.begin(); it != A[a].second.end(); ++it)
            if (*it == b)
                return 1;
        return 0;
    }

    void BFS(int start) {
        static deque<int> coada(1, start);
        static vector<int> vizitate;
        vizitate.push_back(start);
        if (!coada.empty()) {
            if (count(vizitate.begin(), vizitate.end(), start) <= 1)
                cout << start << " ";
            for (auto it = A[start].second.begin(); it != A[start].second.end(); ++it) {
                if (count(vizitate.begin(), vizitate.end(), *it) == 0)
                    coada.push_back(*it);
            }
            coada.pop_front();
            auto it2 = coada.begin();
            BFS(*it2);
        }
    }

    void DFS(int start) {

        static deque<int> coada(1, start);
        static vector<int> vizitate;
        vizitate.push_back(start);
        if (count(vizitate.begin(), vizitate.end(), start) <= 1)
            cout << start << " ";
        for (auto it = A[start].second.begin(); it != A[start].second.end(); ++it) {
            if (count(vizitate.begin(), vizitate.end(), *it) == 0) {
                coada.push_back(*it);
                DFS(*it);
            } else if (!coada.empty()) {
                coada.pop_back();
            }
        }
    }

    int twoCycles() {
         int nr_cicluri = 0;
        for(int i=1;i<max;i++)
            for(auto it = A[i].second.begin(); it != A[i].second.end(); ++it)
                if(hasEdge(*it,A[i].first)==1)
                    nr_cicluri++;
                nr_cicluri/=2;
        return nr_cicluri;
    }
};


#endif //UNTITLED2_DIRECTEDGRAPH_H
