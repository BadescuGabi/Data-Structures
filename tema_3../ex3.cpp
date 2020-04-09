#include <iostream>

using namespace std;

struct arbore {
    int info;
    arbore *stang, *drept;
} *radacina;

void insert(int x) {
    int ok = 1;
    arbore *new_arbore = new arbore;
    new_arbore->info = x;
    new_arbore->stang = NULL;
    new_arbore->drept = NULL;
    if (radacina == NULL) {
        radacina = new_arbore;
    } else {
        arbore *cur = radacina;
        while (ok) {
            if (cur->info > new_arbore->info) {
                if (cur->stang != NULL) {
                    cur = cur->stang;
                } else {
                    cur->stang = new_arbore;
                    ok = 0;
                }
            } else {
                if (cur->drept != NULL) {
                    cur = cur->drept;
                } else {
                    cur->drept = new_arbore;
                    ok = 0;
                }
            }
        }
    }
}

void SRD(arbore *radacina,int &k1,int &k2) {
    if (radacina != NULL and radacina->info>=k1+1) {
        SRD(radacina->stang,k1,k2);
        if(radacina->info>k1 and radacina->info<k2)
        cout << radacina->info;
        SRD(radacina->drept,k1,k2);
    }
    else if(radacina!=NULL and radacina->info<=k1){
        SRD(radacina->drept,k1,k2);
    }
}


int main() {
    int ok = 1;
    int k1,k2;
    insert(6);
    insert(4);
    insert(9);
    insert(2);
    insert(1);
    insert(5);
    insert(3);
    insert(7);
    insert(8);
    cin>>k1;
    cin>>k2;
    SRD(radacina,k1,k2);

}
