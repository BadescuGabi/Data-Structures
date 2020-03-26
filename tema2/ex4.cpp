#include <iostream>

using namespace std;


void count_sort(int a[], int &n,int &x) {
    int frecv[10]={0} ,c[100]={0};
    for (int i = 1; i <= n; ++i) {
        frecv[(a[i]/x)%10]++;
    }
    for (int i = 1; i <= 10; ++i) {
        frecv[i]+=frecv[i-1];
    }
    for (int i = n; i >= 1; --i) {
        c[frecv[a[i]/x%10]] = a[i];
        frecv[a[i]/x%10]--;
    }
    for(int i=1;i<=n;++i){
        a[i]=c[i];
    }
}

void RadixSort(int n, int a[]){
    int x=1;
    int nr_maxim=0;
    for(int i=1;i<=n;i++){
        if (a[i] > nr_maxim)
            nr_maxim=a[i];}
        for(int x=1;nr_maxim/x>0;x*=10){
            count_sort(a,n,x);
            cout<<endl;
            for(int j=1;j<=n;j++,cout<<endl)
                cout<<a[j];
        }
    }

int main() {
    int a[100] = {0}, n;
    cin >> n;
    for (int j = 1; j <= n; ++j)
        cin >> a[j];
   RadixSort(n,a);
    for (int i = 1; i <= n; ++i) {
        cout << a[i]<<" ";
    }
}

//problema 4 sd
