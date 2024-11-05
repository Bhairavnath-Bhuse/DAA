#include<bits/stdc++.h>
using namespace std;


int knapsack(int n,int w,vector<int> &values,vector<int> &weight,vector<vector<int>> &kp)
{
    if(n == 0 || w == 0) return 0;

    if(kp[n][w] != -1) return kp[n][w];

    if(weight[n-1] >w)
    {
        kp[n][w] = knapsack(n-1,w,values,weight,kp);
    }
    else{
        int includeI = values[n-1] + knapsack(n-1,w-weight[n-1],values,weight,kp);
        int excludeI = knapsack(n-1,w,values,weight,kp);

        kp[n][w] = max(includeI,excludeI);
    }

    return kp[n][w];



}


int main()
{
    int n;
    cout<<"Enter the number of values ";
    cin>>n;
    vector<int> price(n);
    vector<int> weight(n);

    cout<<"Enter the price values ";
    for(int i =0;i<n;i++)
    {
        cin>>price[i];
    }

    cout<<"Enter the weight values ";
    for(int i =0;i<n;i++)
    {
        cin>>weight[i];
    }

    int w;
    cout<<"Enter the weight limit ";
    cin>>w;
    vector<vector<int>> kp(n+1, vector<int>(w+1,-1));

    int maxProfit = knapsack(n, w, price, weight, kp);
    cout << "The maximum value that can be obtained is: " << maxProfit << endl;

}