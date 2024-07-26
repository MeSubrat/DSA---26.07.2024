#include<bits/stdc++.h>
using namespace std;

vector<int> PGE(vector<int> &arr)
{
    int n=arr.size();
    vector<int> pge(n);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]<=arr[i])
        {
            st.pop();
        }
        pge[i]=st.empty()?-1:st.top();

        st.push(i);
    }
    return pge;
}

void print(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int> arr={4,1,2,3,5};
    vector<int> ans=PGE(arr);
    print(ans);
}