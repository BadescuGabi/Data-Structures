#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    cout<<"citeste vectorul: ";
    int a[n+2],sum=0;
    for(int i=0;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    cout<<"elementul care apare de 2 ori este: ";
    cout<<sum-(n*(n+1))/2;

}
