#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int ans = 0;

    for(int i = 2 ; (i*(i+1))/2 <= n ; ++i)
    {
        if((n-(i*(i+1))/2)%i==0)
            ans++;
    }
    cout<<ans;
}

