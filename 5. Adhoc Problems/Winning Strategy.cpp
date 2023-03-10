//code
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const char nl = '\n';
#define trav(a, x) for (auto &a : (x))

int main() 
{
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
      cin>>v[i];
    }
    int i = 0, cnt = 0;
    int *umap = new int[n + 1]{0};
      
    while(i < n - 1) {
      if(i < n - 1 && v[i] > v[i + 1] && umap[v[i]] < 2 && umap[v[i + 1]] < 2) {        
    	  umap[v[i]]++;                               
    	  umap[v[i + 1]]++; 
        cnt++;
        swap(v[i], v[i + 1]);
      } 
      if(i < n - 2 && v[i] > v[i + 2] && umap[v[i]] < 2 && umap[v[i + 2]] < 2) {   
        umap[v[i + 2]]++; 
        cnt++;
        swap(v[i], v[i + 2]);
      }
      i++;
    }
    
    delete[] umap;
      
    for(int i = 0; i < n - 1; i++) {
      if(v[i + 1] != v[i] + 1) {
        cout<<"NO"<<endl;
        break;
      }
      if(i == n - 2) cout<<"YES"<<endl<<cnt<<endl;
    }
  }  	
    
  return 0;
}
