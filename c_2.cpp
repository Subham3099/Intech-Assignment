#include <bits/stdc++.h>
using namespace std;

double fn(double x)
{
    return x*x;
}

int main()
{
    int x1,x2;
    cin>>x1>>x2;
    
    double step = 0.1;
    
    vector<double> rightmax;
    
    for(double i = x2 ; i >= x1 ; i-=step)
    {
        if(i==x2)
        {
            rightmax.push_back(fn(i));
        }
        else
        {
            rightmax.push_back(max(rightmax.back(),fn(i)));
        }
    }
    
    reverse(rightmax.begin(),rightmax.end());
    
    double leftmax = 0.0;
    
    double ans = 0.0;
    
    int j = 0;
    for(double i = x1 ; i <= x2 ; i+=step)
    {
        double tmp = fn(i);
        ans += max(0.0,min(leftmax,rightmax[j++])-tmp);
        leftmax = max(leftmax,tmp);
    }
    cout<<ans*step;
}

