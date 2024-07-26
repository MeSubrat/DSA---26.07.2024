#include<bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> &arr)
{
    vector<int> nge(arr.size());
    stack<int> st;

    for(int i=arr.size()-1;i>=0;i--)
    {
        while(!st.empty() && st.top()<=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            nge[i]=-1;
        }
        else{
            nge[i]=st.top();
        }
        st.push(arr[i]);
    }
    return nge;
}

vector<int> NGEIdx(vector<int> arr)
{
    vector<int> nge(arr.size());
    stack<int> st;

    for(int i=arr.size()-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]<=arr[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            nge[i]=arr.size();
        }
        else{
            nge[i]=st.top();
        }
        st.push(i);
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
    vector<int> arr={6,0,8,1,3};
    vector<int> ans=NGEIdx(arr);
    print(ans);
}