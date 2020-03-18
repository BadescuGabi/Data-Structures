#include <iostream>

using namespace std;

struct stiva {
    int info;
    stiva *next;
} *vf;

void push(stiva *&vf, int x) {
    stiva *new_stiva = new stiva;
    new_stiva->info = x;
    new_stiva->next = NULL;
    new_stiva->next = vf;
    vf = new_stiva;
}

int pop() {
    int x = -1;
    stiva *q;
    q = vf;
    if (vf != NULL) {
        vf = vf->next;
    }
    x = q->info;
    delete q;
    return x;
}

int simulare_pop() {
    int x = -1;
    stiva *z;
    z = vf;
    x = z->info;
    return x;
}

bool IsEmpty() {
    if (vf == NULL) {
        return false;
    }
    return true;
}

void afisare(stiva *vf) {
    while (vf != NULL) {
        cout << vf->info << " ";
        vf = vf->next;
    }
}

int main() {
    int n;
    cout << "Numarul de tarusi este:";
    cin >> n;
    cout << endl;
    cout << "Iar vectorul de tarusi este:";
    int a[n + 1], i, ok = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (i = 0; i < n; i++) {
        ok = 0;
        if (IsEmpty() == false) {
            push(vf, a[i]);
        } else {
            if (a[i] == simulare_pop()) {
                pop();
                ok = 1;
            }
            if (ok == 0) {
                if (a[i] != simulare_pop() && a[i] >= simulare_pop()) {
                    push(vf, a[i]);
                } else {
                    cout << "Solutia nu e valida";
                    return 0;
                }
            }
        }
    }
    cout << "Solutia este valida";
    return 0;
}
//problema 3+1 sd
