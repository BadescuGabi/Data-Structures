#include <iostream>
#include <cmath>

using namespace std;

void heap_push(int *a, int &n, int val) {
    n++;
    a[n] = val;
    int j = n;
    int i = n / 2;
    while (i >= 1) {
        int ok = 0;
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            j = i;
            i /= 2;
            ok = 1;
        }
        if (ok == 0)
            break;
    }
}

void heap_pop(int *a, int &n) {
    if (n == 1) {
        cout << "e gol";
        return;
    }
    if (n == 2) {
        cout << a[n];
        return;
    }
    a[1] = a[n];
    n--;
    int i = 1;
    int j = 2 * i;
    while (j < n) { //pusesem =
        int ok = 0;
        if (a[j] < a[j + 1]) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
                i = j;
                j *= 2;
                ok = 1;
            }
        } else if (a[j + 1] < a[j]) {
            if (a[i] > a[j + 1]) {
                swap(a[i], a[j + 1]);
                i = j + 1;
                j *= 2;
                ok = 1;
            }
        }
        if (ok == 0)
            break;
    }
}

void min_heap(int *a, int k, int n, int &check) {
    int s = 2 * k;
    if (a[s] < a[s + 1]) {

        if (a[s] < a[k]) {
            swap(a[s], a[k]);
            check = 1;
        }
    } else if (a[s] > a[s + 1]) {

        if (a[s + 1] < a[k]) {
            swap(a[s + 1], a[k]);
            check = 1;
        }
    }
}

void build_min_heap(int *a, int n, int &check) {
    int k;
    for (k = n / 2; k >= 1; k--) {
        min_heap(a, k, n, check);
    }
    if (check == 1) {
        check = 0;
        build_min_heap(a, n, check);
    }
}

int main() {
    int n;
    int check = 0;
    cin >> n;
    int a[100];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << endl;
    cout << "valoare pentru push:";
    int val;
    cin >> val;
    build_min_heap(a, n, check);
    cout << "min heap dupa push:";
    heap_push(a, n, val);
    cout << endl;
    for (int i = 1; i <= n; ++i, cout << " ")
        cout << a[i];
    heap_pop(a, n);
    cout << endl;
    cout << "min heap dupa pop";
    cout << endl;
    for (int i = 1; i <= n; ++i, cout << " ")
        cout << a[i];

}
//problema 1 sd




