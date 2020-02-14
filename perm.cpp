#include <iostream>
#include <vector> 
#include<algorithm>
using namespace std;


void insertElement(vector<int> &v, int n){
    for(int i=0; i<v.size();i++){
        if(n<v[i]){
            v.insert(v.begin()+i,n);
            return;
        }
    }
    v.push_back(n);
}


int main() {
    int n, m;
    int temp;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> s(m);
    for(int i=0; i<n;i++){
        cin >>temp;
        v[i]=temp;
    }
    for(int i=0; i<m;i++){
        cin>>temp;
        s[i]=temp;
    }
    sort(s.begin(), s.end());
    
    for(int i=0;i<m;i++){
        insertElement(v,s[i]);
    }
    
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;
}