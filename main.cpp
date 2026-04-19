// 1-mashq
#include <bits/stdc++.h>
using namespace std;

int n=4;
set<int> col,d1,d2;

int solve(int r){
    if(r==n) return 1;
    int res=0;

    for(int c=0;c<n;c++){
        if(col.count(c)||d1.count(r+c)||d2.count(r-c)) continue;
        col.insert(c); d1.insert(r+c); d2.insert(r-c);
        res+=solve(r+1);
        col.erase(c); d1.erase(r+c); d2.erase(r-c);
    }
    return res;
}

int main(){
    cout<<solve(0);
}
// 2-mashq
#include <bits/stdc++.h>
using namespace std;

vector<int> seg(100);

void build(vector<int>&a,int i,int l,int r){
    if(l==r){ seg[i]=a[l]; return; }
    int m=(l+r)/2;
    build(a,2*i,l,m);
    build(a,2*i+1,m+1,r);
    seg[i]=seg[2*i]+seg[2*i+1];
}

int query(int i,int l,int r,int ql,int qr){
    if(qr<l||ql>r) return 0;
    if(ql<=l && r<=qr) return seg[i];
    int m=(l+r)/2;
    return query(2*i,l,m,ql,qr)+query(2*i+1,m+1,r,ql,qr);
}

int main(){
    vector<int>a={1,2,3,4};
    build(a,1,0,3);
    cout<<query(1,0,3,1,3);
}
