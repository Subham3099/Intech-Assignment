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
    
    vector<pair<char,int>> pv;
    
    char ch = s[0];
    
    for(int i = 0 ; i < n ; ++i)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            if(num!=0)
            {
                pv.push_back({ch,num});
                num = 0;
            }
            ch = s[i];
        }
        else
        {
            num = num*10 + (s[i]-'0');
        }
    }
    
    if(num!=0)
    {
        pv.push_back({ch,num});
    }
    
    string con_str = "";
    int    cur_no  = 0;
    
    con_str += pv[0].first;
    cur_no  = pv[0].second;
    
    string ans = "";
    
    for(int i = 1 ; i < pv.size() ; ++i)
    {
        if(cur_no == pv[i].second)
        {
            con_str += pv[i].first;
        }
        else
        {
            ans += con_str;
            ans += to_string(cur_no);
            
            con_str = "";
            
            con_str += pv[i].first;
            cur_no   = pv[i].second;
        }
    }
    
    ans += con_str;
    ans += to_string(cur_no);
    
    
    cout<<ans;
    return 0;
}
