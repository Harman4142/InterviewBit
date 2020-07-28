/*
Given two arrays A & B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5
Example:
N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)
*/

typedef  pair<int,pair<int,int>> ppi;
vector<int> Solution::solve(vector<int> &A, vector<int> &B) 
{
    vector<int> res;
    int n=A.size();
    if(n==0)
        return res;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    priority_queue<ppi> pq;
    set<pair<int,int>>S;
    pq.push(make_pair( A[n-1]+B[n-1] , make_pair(n-1,n-1)));
    S.insert(make_pair(n-1,n-1));
    
    for(int i=0;i<n;i++)
    {
        ppi top= pq.top();
        res.push_back(top.first);
        
        pq.pop();
        
        int c1 = top.second.first;
        int c2 = top.second.second;
        
        if( c2>0 && c1>=0 && S.find(make_pair(c1,c2-1)) == S.end())
        {
            pq.push(make_pair( A[c1]+B[c2-1] , make_pair(c1,c2-1)));
            S.insert(make_pair(c1,c2-1));
        }
        
        if(c1>0 && c2>=0 && S.find(make_pair(c1-1,c2)) == S.end())
        {
            pq.push(make_pair( A[c1-1]+B[c2] , make_pair(c1-1,c2)));
            S.insert(make_pair(c1-1,c2));
        }
    }
    return res;  
}
