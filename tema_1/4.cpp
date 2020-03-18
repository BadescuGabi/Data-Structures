#include <queue>
#include <iostream>

using namespace std;

const int di[] = {-1, 0, 1, 0},
        dj[] = {0, 1, 0, -1};
int a[8][8], n, istart, jstart, i, j, k, ok = 0;

void Fill(int istart, int jstart, int &v) {
    int min = 999;
    ok = 0;
    queue<pair<int, int>> coada;
    coada.push(make_pair(istart, jstart));
    a[istart][jstart] = v;
    i = coada.front().first;
    j = coada.front().second;
    for (k = 0; k < 4; k++) {
        int ivecin = i + di[k];
        int jvecin = j + dj[k];
        if (a[ivecin][jvecin] < min && a[ivecin][jvecin] > 1) {
            min = a[ivecin][jvecin];
        }
        if (a[ivecin][jvecin] > 1) {
            a[i][j] = min;
        } else if (ivecin >= 0 && ivecin < n && jvecin >= 0 && jvecin < n && a[ivecin][jvecin] == 1) {
            a[ivecin][jvecin] = v;
            ok = 1;
        }
    }
    if (ok == 0) {
        v++;
    }
    coada.pop();
}

int main() {
    queue<pair<int, int>> coada;
    int v = 2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                Fill(i, j, v);
            }
        }
    }
    for (int i = 0; i < n; i++, cout << endl) {
        for (j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
    }
}
//problema 4 sd
