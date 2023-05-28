#include <bits/stdc++.h> 
using namespace std;
#define int long long

int find_ans(vector<int> &v){
    int ans=0;
    for(int i=1;i<v.size();i++)     ans+=max(0,v[i]-v[i-1]);
    return ans;
}

int32_t main()
{
    #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
    #endif
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)        cin>>v[i];
    cout<<find_ans(v);
    return 0;
}