#include <bits/stdc++.h>
#define int long long
#define float double
#define vi vector<int>
#define vf vector<float>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define rep(i,a,b) for(int i = a;i<=b;i++)
#define rrep(i,a,b) for(int i = a;i>=b;i--)
#define jaldi ios_base::sync_with_stdio(false);
#define kar cin.tie(NULL);
#define bhai cout.tie(NULL);
#define no "NO"
#define yes "YES"
#define all(_) _.begin(),_.end()
using namespace std;

template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
     for (auto &it : v)
          cin >> it;
     return istream;
}

template <typename Te>
ostream &operator<<(ostream &ostream, vector<Te> &v)
{
     for (auto it : v)
     {
          cout << it << " ";
     }
     cout << endl;
     return ostream;
}
bool comp(pair<int,int> a,pair<int,int> b){
     return a.second < b.second;
}
void solution(){
     int n;cin>>n;
     vector<pair<int,int>> ar;
     rep(i,1,n){
          pair<int,int> _;
          int a,b;
          cin>>a>>b;
          _={a,b};
          ar.push_back(_);
     }

     sort(all(ar),comp);
     int cnt = 1;
     pair<int,int> t = {ar[0].first , ar[0].second};
     vector<pair<int,int>> ans;
     ans.push_back(t);
     int j = 0;
     rep(i,1,n-1){
          if(ar[j].second <= ar[i].first){
               t = {ar[i].first,ar[i].second};
               ans.push_back(t);
               cnt++;
               j = i;
          }
     }

     cout<<cnt<<endl;
     for(auto it: ans) cout<<it.first<<" "<<it.second<<endl;
}
signed main()
{
     jaldi kar bhai
     int t;
     cin >> t;

     while (t--)
     {

          solution();
     }
}
