#include<iostream>
#include <cmath>
using namespace std;

int mediana_2_vectori (int a[],int b[],int size){
    if(size==0){
        return 0;
    }
    if(size==1){
        return min(a[0],b[0]);
    }
    if(size==2){
        return max(a[size/2-1],b[size/2-1]);
    }
    else{
        int med_a=a[size/2];
        int med_b=b[size/2];
        if(med_a<med_b){
            if(size%2==0){//ia a2a jumatate a primului vector si prima a celui de al 2 lea iar la al 2 lea if invers
                return mediana_2_vectori(a+size/2-1,b,size-size/2+1);
            }
            return mediana_2_vectori(a+size/2,b,size-size/2);
        }
        if(med_a>med_b){
            if(size%2==0){
            return mediana_2_vectori(b+size/2-1,a,size-size/2+1);
        }
        return mediana_2_vectori(b+size/2,a,size-size/2);
    }
        if(med_a==med_b)
            return med_a;
        }}

int main (){
   int n;
   cin>>n;
   int a[n+1],b[n+1],med_a,med_b;
   cout<<endl<<"vectorul a:";
   for(int i=0;i<n;++i)
        cin>>a[i];

   cout<<endl<<"vectorul b:";
    for(int i=0;i<n;++i)
        cin>>b[i];
    cout<<mediana_2_vectori(a,b,n);
}
