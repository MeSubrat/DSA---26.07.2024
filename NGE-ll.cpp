#include<bits/stdc++.h>
using namespace std;

vector<int> NGEBetter(vector<int> &arr)
{
    vector<int> nge(arr.size());
    stack<int> st;
    int n=arr.size();
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && st.top()<=arr[i%n])
        {
            st.pop();
        }
        if(i<n)
        {
            nge[i]=st.empty()?-1:st.top();
        }
        st.push(arr[i%n]);
    }
    return nge;
}

void print(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    vector<int> arr={2,10,12,1,11};
    vector<int> ans=NGEBetter(arr);
    print(ans);
}