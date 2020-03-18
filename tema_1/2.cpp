#include <iostream>
using namespace std;

struct coada {
    int info;
    coada* prev, * next;
}*prim, * ultim;

void Push_right(int x) {
    coada* new_coada = new coada;
    new_coada->info = x;
    new_coada->next = NULL;
    new_coada->prev = ultim;
    if(ultim != NULL)
        ultim->next = new_coada;
    ultim = new_coada;
    if (prim == NULL)
        prim = new_coada;
}
void Push_left(int x) {
    coada* new_coada = new coada;
    new_coada->info = x;
    new_coada->next = prim;
    new_coada->prev = NULL;
    if(prim != NULL)

        prim->prev = new_coada;
    prim = new_coada;
    if (ultim == NULL)
        ultim = new_coada;
}
int Pop_Right() {
    int x = -1;
    coada* p;
    p = ultim;
    if (ultim != NULL) {
        ultim = ultim->prev;
        if(ultim != NULL)
            ultim->next = NULL;
        x = p->info;
        delete p;
    }
    return x;
}
int Pop_Left() {
    int x = -1;
    coada* q;
    q = prim;
    if (prim != NULL) {
        prim = prim->next;
        if(prim != NULL)
            prim->prev = NULL;
        x = q->info;
        delete q;
    }
    return x;
}
void afisare(){
    coada *z=prim;
    while(z!=NULL)
    {
        cout<<z->info<<" ";
        z=z->next;
    }
}
int main()
{
    Push_left(1);
    Push_right(2);
    Push_left(4);
    Push_right(3);
    cout << Pop_Right();
    cout << " ";
    cout << Pop_Left();
    Push_right(5);
    cout << " ";
    cout << Pop_Left();
    cout<<endl;
    cout<<"Numerele ramase in coada sunt: ";
    afisare();
    return 0;
}
//problema 2 sd
