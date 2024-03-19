#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    cin>>s;
    
    int n = s.length();
    
    if(n==0)
    {
        cout<<"";
        return 0;
    }
    int num = 0;
    
    vector<pair<string,int>> pv;
    
    string tmp_str = "";
    
    for(int i = 0 ; i < n ; ++i)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            if(num!=0)
            {
                pv.push_back({tmp_str,num});
                num = 0;
                tmp_str = "";
            }
            tmp_str += s[i];
        }
        else
        {
            num = num*10 + (s[i]-'0');
        }
    }
    
    if(num!=0)
    {
        pv.push_back({tmp_str,num});
    }
    
    string ans = "";
    
    for(auto&[a,b]:pv)
    {
        while(b--)
            ans += a;
    }
    
    cout<<ans;
    return 0;
}
