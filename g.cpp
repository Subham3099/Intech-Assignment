// One of my published solutions on leetcode : https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/solutions/4694632/traversing-segment-tree-c-simple-segment-tree-template-intuition
/*
Logic :

The question is about finding minimum length of subarray with sum atleast k.
As negatives are allowed in the array so the prefix-sum of the array in not monotonically increasing.
So For every index(idx) we have to find maximum index (found_index) such that  " pre[idx] - pre[found_index - 1 ] >= k "
For doing that I am using Traversal on Segment Tree for range 0 to idx-1 , I am finding maximum index whose value is less than equal to pre[idx] - k .
The Segment Tree used here is for Range Minimum.
*/
class Solution {
public:
    long long seg[4*100000] = {};
    long long base = LONG_LONG_MAX;
    void init_seg(long long x)
    {
        for(int i= 0 ; i < 4*100000 ; ++i)
            seg[i] = x;
    }
    long long fn(long long a,long long b)
    {
        return min(a,b);
    }
    void build(int l,int r,int idx,vector<long long>& v)
    {
        if(l==r)
            seg[idx] = v[l];
        else
        {
            build(l,l+(r-l)/2,2*idx+1,v);
            build(l+((r-l)/2)+1,r,2*idx+2,v);
            seg[idx] = fn(seg[2*idx+1],seg[2*idx+2]);
        }
    }

    void supdate(int l,int r,int idx,int node,int val)
    {
        if(l==r)
            seg[idx] = val;
        else
        {
            if(node>=l && node<=l+(r-l)/2)
                supdate(l,l+((r-l)/2),2*idx+1,node,val);
            else
                supdate(l+((r-l)/2)+1,r,2*idx+2,node,val);
            
            seg[idx] = fn(seg[2*idx+1],seg[2*idx+2]);
        }
    }

    long long query(int lq,int rq,int l,int r,int idx)
    {
        if(l>=lq && r<=rq)
            return seg[idx];
        else if(rq < l || lq > r)
            return base;
        else
        {
            return fn(query(lq,rq,l,l+(r-l)/2,2*idx+1),query(lq,rq,l+(r-l)/2+1,r,2*idx+2));
        }
    }
    int hs(int lq,int rq,long long x,int idx,int l,int r,int s,int e)
    {
        int m = l+(r-l)/2;
        if(l==r)
        {
            return l;
        }
        if(m+1<=rq && query(m+1,rq,s,e,0)<=x)
        {
            return hs(lq,rq,x,2*idx+2,m+1,r,s,e);
        }
        else
        {
            return hs(lq,rq,x,2*idx+1,l,m,s,e);
        }
    }
    int bs(int lq,int rq,long long x,int idx,int l,int r)
    {
        if(query(lq,rq,l,r,idx)>x)
            return -1;

        return hs(lq,rq,x,idx,l,r,l,r);
    }
    int shortestSubarray(vector<int>& nums, int k) {
        
        int ans = 1e9,n=nums.size();
        vector<long long> pre(nums.begin(),nums.end());
        for(int i = 1 ; i < n ; ++i)
            pre[i]+=pre[i-1];
        pre.insert(pre.begin(),0);
        
        init_seg(LONG_LONG_MAX);
        build(0,n,0,pre);
        for(int i = 1 ; i <= n ; ++i)
        {
            int qr = bs(0,i-1,pre[i]-1ll*k,0,0,n);
            if(qr!=-1)
            {
                ans = min(ans,i-qr);
            }
        }
        return ans==1e9?-1:ans;
    }
};

