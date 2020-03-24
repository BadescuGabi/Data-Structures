#include <queue>
#include <iostream>

using namespace std;

const int di[] = {-1, 0, 1, 0},
        dj[] = {0, 1, 0, -1};
int a[8][8], n, istart, jstart, i, j, k, ok = 0;
int mini=999;
void Fill(int istart, int jstart, int &v) {
    ok = 0;
    queue<pair<int, int>> coada;
    coada.push(make_pair(istart, jstart));
    i = coada.front().first;
    j = coada.front().second;
    for(k = 0; k<4;k++){
        int ivecin = i + di[k];
        int jvecin = j + dj[k];
        if(a[ivecin][jvecin]>mini and a[ivecin][jvecin]>1)
            mini=a[ivecin][jvecin];
    }
    for (k = 0; k < 4; k++) {
        int ivecin = i + di[k];
        int jvecin = j + dj[k];
        if(a[ivecin][jvecin]==1 && a[istart][jstart]>1){
            a[ivecin][jvecin]=a[istart][jstart];
        }
        if (a[ivecin][jvecin] > 1 and a[istart][jstart]<a[ivecin][jvecin]) {
            a[istart][jstart] = a[ivecin][jvecin];
            ok=1;
        }}
if (a[istart][jstart]!=1){
    return;
}
    if (ok == 0) {
        a[istart][jstart] = ++v;
        for (k = 0; k < 4; k++) {
            int ivecin = i + di[k];
            int jvecin = j + dj[k];
            if(mini!=999 and a[ivecin][jvecin]==1)
                a[ivecin][jvecin]=mini;
            else if (a[ivecin][jvecin] == 1 && a[istart][jstart] > 1) {
                a[ivecin][jvecin] = a[istart][jstart];
            }}}
            coada.pop();
        }

int main() {
    queue<pair<int, int>> coada;
    int v = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    cout<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] >= 1) {
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
