#include <bits/stdc++.h>
using namespace std;

bool isprime(int x)
{
    for(int i = 2 ; i <= x/2 ; ++i)
        if(x%i==0)
            return false;
    return true;
}
int main()
{
    string pi = "3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067";
    //ref : https://clickcalculators.com/pi-calculator/100
    
    int n = pi.size();
    
    int i = 0 , j = 0 , ans = 0;
    
    string tmp = "";
    
    while(j<n)
    {
        tmp+=pi[j];
        
        if(j-i+1==5)
        {
            int x = stoi(tmp);
            
            if(isprime(x))
                ans = max(ans,x);
            
            tmp.erase(0,1);
            i++;
        }
        j++;
    }
    
    cout<<ans;
    
}

