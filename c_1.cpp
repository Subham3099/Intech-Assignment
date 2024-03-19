#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    vector<int> arr(n);
    
    for(int i = 0 ; i < n ; ++i)
        cin>>arr[i];
    
    vector<int> rightmax = arr;
    
    for(int i = n-2 ; i >= 0 ; --i)
        rightmax[i] = max(rightmax[i+1],rightmax[i]);
    
    int leftmax = arr[0];
    
    long long ans = 0;
    
    for(int i = 1 ; i < n-1 ; ++i)
    {
        ans += max(0,min(leftmax,rightmax[i])-arr[i]);
        leftmax = max(leftmax,arr[i]);
    }
    
    cout<<ans;
    
}

