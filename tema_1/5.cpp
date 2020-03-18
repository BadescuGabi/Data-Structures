#include <iostream>

using namespace std;

int vector_maj(int a[],int n) {
    int numar_posibil = -1, contor = 0;
    for (int i = 0; i < n; i++) {
        if (contor == 0) {
            numar_posibil = a[i];
            contor++;
        } else if (a[i] == numar_posibil) {
            contor++;
        } else {
            contor--;
        }
    }
    int nr = 0;
    for (int i = 0; i <= n; i++) {
        if (a[i] == numar_posibil) {
            nr++;
        }
    }
    if (nr > n / 2) {
        return numar_posibil;
    } else {
        return -1;
    }
}

int main() {
    int a[100] = {}, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << vector_maj(a, n);
}
//problema 5 sd
