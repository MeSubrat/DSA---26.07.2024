#include<bits/stdc++.h>
using namespace std;

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

vector<int> PGEIdx(vector<int> &arr)
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
int sumOfSubArrMax(vector<int> &arr)
{
    vector<int> nge=NGEIdx(arr);
    vector<int> pge=PGEIdx(arr);
    int total=0;
    for(int i=0;i<arr.size();i++)
    {
        int left=i-pge[i];
        int right=nge[i]-i;

        total=total+(left*right*arr[i]);
    }
    return total;
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

int sumOfSubArrRanges(vector<int> arr)
{
    return sumOfSubArrMax(arr)-SumOfSubArrMin(arr);
}

int main()
{
    vector<int> arr={1,4,3,2};
    cout<<sumOfSubArrRanges(arr);
}