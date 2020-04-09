#include <iostream>
#include<string.h>

using namespace std;

struct arbore {
     char info;
    arbore *stang, *drept;
} *radacina;

void insert(char x) {
    int ok = 1;
    arbore *new_arbore = new arbore;
    new_arbore->info = x;
    new_arbore->stang = NULL;
    new_arbore->drept = NULL;
    if (radacina == NULL) {
        radacina = new_arbore;
    } else {

        arbore *cur = radacina;
        while (ok ) {
            if ((cur->info> new_arbore->info)) {
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

void SRD(arbore *radacina) {
    if (radacina != NULL) {
        SRD(radacina->stang);
        cout << radacina->info;
        SRD(radacina->drept);
    }
}

void RSD(arbore *radacina) {
    if (radacina != NULL) {
        cout << radacina->info;
        RSD(radacina->stang);
        RSD(radacina->drept);
    }
}

int main() {
int n;
cin>>n;
char a[30]="";
for(int i=1;i<=n;++i){
    cin>>a[i];
    insert(a[i]);
}
SRD(radacina);
}
