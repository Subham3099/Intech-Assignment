#include <bits/stdc++.h>
using namespace std;

bool intersect(int a,int b,int x,int y)
{
    return min(b,y) - max(a,x) >=0;     //equal condition for touching 
}
int main()
{
    int a1,b1,x1,y1,a2,b2,x2,y2;
    
    cout<<"\n\n\nFirst Rectangle : \n";
    cout<<"Enter bottom left co-ordinate (x,y) : ";
    cin>>a1>>b1;
    
    cout<<"Enter top right co-ordinate (x,y) : ";
    cin>>x1>>y1;
    
    cout<<"\n\n\nSecond Rectangle : \n";
    cout<<"Enter bottom left co-ordinate (x,y) : ";
    cin>>a2>>b2;
    
    cout<<"Enter top right co-ordinate (x,y) : ";
    cin>>x2>>y2;

//if both have some intersection in their range of x - coordinates and y - coordinates then only there can be intersection in both rectangles
    if(intersect(a1,x1,a2,x2)&&intersect(b1,y1,b2,y2))
        cout<<"\nRectangles are Intersecting";
    else
        cout<<"\nRectangles are not Intersecting";
    return 0;
}

