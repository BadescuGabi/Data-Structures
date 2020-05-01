#include <iostream>
#include "directedGraph.h"
using namespace std;

int main(){
directedGraph C;
for(int j=1;j<=10;++j){
    C.addNode(j);
}
C.addEdge(1,10);
C.addEdge(1,5);
C.addEdge(5,9);
C.addEdge(9,4);
C.addEdge(10,7);
C.addEdge(10,8);
C.addEdge(7,3);
C.addEdge(3,8);
C.addEdge(8,2);
C.addEdge(2,6);
    //cu muchiile de mai jos practic l am fct neorientat
    C.addEdge(10,1);
    C.addEdge(5,1);
    C.addEdge(9,5);
    C.addEdge(4,9);
    C.addEdge(8,10);
    C.addEdge(7,10);
    C.addEdge(3,7);
    C.addEdge(8,3);
    C.addEdge(2,8);
    C.addEdge(6,2);
//cout<<C.hasEdge(1,2);
cout<<"Parcurgerea BFS: ";
C.BFS(1);
cout<<endl;
cout<<"Parcurgerea DFS: ";
C.DFS(1);
cout<<endl;
cout<<C.twoCycles();
}
