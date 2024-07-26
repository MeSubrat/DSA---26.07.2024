#include<bits/stdc++.h>
using namespace std;

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

vector<int> NSEIdx(vector<int> &arr)
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

int SumOfSubArrMin(vector<int>&arr)
{
    int sum=0;
    vector<int> nse=NSEIdx(arr);
    vector<int> pse=PSEIdx(arr);
    for(int i=0;i<arr.size();i++)
    {
        int left=i-pse[i];
        int right=nse[i]-i;

        sum=sum+(left*right*arr[i]);
    }
    return sum;
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
    vector<int> arr={1,4,6,7,3,7,8,1};
    int ans=SumOfSubArrMin(arr);

    cout<<ans;
    // vector<int>nse=NSEIdx(arr);
    // vector<int>pse=PSEIdx(arr);
    // print(nse);
    // cout<<"\n";
    // print(pse);

}