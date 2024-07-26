#include<bits/stdc++.h>
using namespace std;

vector<int> PSE(vector<int> &arr)
{
    int n=arr.size();
    vector<int> pse(n);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && st.top()>=arr[i])
        {
            st.pop();
        }
        pse[i]=st.empty()?-1:st.top();

        st.push(arr[i]);
    }
    return pse;
}

vector<int> PSEIdx(vector<int> &arr)
{
    int n=arr.size();
    vector<int> pse(n);
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
        {
            st.pop();
        }
        pse[i]=st.empty()?-1:st.top();

        st.push(i);
    }
    return pse;
}

void print(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int> arr={5,7,9,6,7,4,5,1,3,7};
    vector<int> ans=PSE(arr);
    print(ans);
}