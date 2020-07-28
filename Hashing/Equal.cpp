/*
Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:
1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2

Example:
Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)
*/

vector<int> Solution::equal(vector<int> &A) 
{
    vector<int> res;
    int n=A.size();
    if(n==0)
        return res;
        
    unordered_map<int,pair<int,int>> m;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            auto sum=A[i] + A[j];
            if(m.find(sum) == m.end())
                m[sum]=make_pair(i,j);  // if sum not found save it in map with indexes pair
            else
            {
                pair<int,int>p=m[sum];  //if sum found then check for conditions
                
                if(p.first<i && p.second !=i &&p.second !=j) // First conditiin stated in the question
                {
                    vector<int> tmp;
                    tmp.push_back(p.first);
                    tmp.push_back(p.second);
                    tmp.push_back(i);
                    tmp.push_back(j);
                    
                    if(res.size()==0)
                        res=tmp;
                    else
                    {
                        for(auto x=0;x<res.size();x++)
                        {
                            if(res[x] < tmp[x])
                                break; // new sol is lexio greater
                            
                            if(res[x] > tmp[x]) // new sol is lexio smalller than current sol
                            {
                                res.clear();
                                res=tmp;
                                break;
                            }
                        }
                    }

                }
            }
        }
    }
    return res;
}
