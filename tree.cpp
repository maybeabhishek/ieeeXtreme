// C++ Implementation of above approach 
#include <bits/stdc++.h> 
using namespace std; 


vector<pair<long, pair<int, int> > > edges; 
long long adjMat[10][10];

void insertAdj(long long n, int a, int b){
    adjMat[a-1][b-1]=n;
    adjMat[b-1][a-1]=n;
}

void AddEdge(int a, int b, long w) 
{ 
	edges.push_back({ w, { a, b } });
    insertAdj(w,a,b);
} 

void MakeTree(int a, int b, long c) 
{ 
	AddEdge(a, b, c);

} 

void prin(){
    for(int i=0; i<5;i++){
        for(int j=0; j<5; j++){
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }
}

long long summ(int n){
    long long sum = 0;
    int j=0;
    for(auto i: adjMat){
        cout<< distance(i, max_element(i, i+j))<<endl;
        sum+=*max_element(i, i+j)*j;

        j++;
    }
    return sum;
}


// Driver code 
int main() 
{ 
    int a,b;
    long c;
	MakeTree(1,2,4); 
    MakeTree(1,3,3); 
    MakeTree(2,4,2); 
    MakeTree(2,5,1); 
    // prin();
    cout<<summ(3);
} 
