#include<bits/stdc++.h>
using namespace std;

vector<int> NSE(vector<int> &arr)
{
    int n=arr.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        nse[i]=st.empty()?n:st.top();

        st.push(i);
    }
    return nse;
}

void print(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int> arr={1,4,6,7,3,7,8,1};
    vector<int> ans=NSE(arr);
    print(ans);
}