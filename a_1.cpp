#include <bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    cin>>s;
    
    if(s.size()==0)
    {
        cout<<"";
        return 0;
    }
    
    
    char ch = s[0];
    int  consecutive = 0;
    
    string ans = "";
    
    for(auto&a : s)
    {
        if(a == ch)
        {
            consecutive++;
        }
        else
        {
            if(consecutive>0)
            {
                ans += ch;
                ans += to_string(consecutive);
            }
            
            ch = a;
            consecutive = 1;
        }
    }
    
    if(consecutive>0)
    {
        ans += ch;
        ans += to_string(consecutive);
    }

    cout<<"Input : "<<s<<endl;
    cout<<"Output: "<<ans;
    return 0;
}
