#include<bits/stdc++.h>
using namespace std;

struct Item{
    int weight;
    int price;

    Item(int p,int w) : price(p),weight(w) {}
};


bool compare(Item a, Item b)
{
    double ratioA = (double)a.price/a.weight;
    double ratioB = (double)b.price/b.weight;

    return ratioA > ratioB;
}

// struct compare{
//       bool operator()(Item a, Item b)
//       {
//           double aa = (double)a.price/a.weight;
//           double bb = (double)b.price/b.weight;
          
//           return aa>bb;
//       }
// };


double knapsack(int n, int w,vector<int> price, vector<int> weight)
{
    double maxProfit = 0.0;
    vector<Item> ans;

    for(int i =0;i<n;i++)
    {
        ans.push_back({price[i],weight[i]});
    }

    sort(ans.begin(), ans.end(), compare);

    for(Item& item:ans)
    {
        if(w == 0) break;

        if(item.weight<=w)
        {
            maxProfit +=item.price;
            w -= item.weight;
        }
        else{
            maxProfit += item.price*(double(w)/item.weight);
            w =0;
        }
    }

    return maxProfit;

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
    // vector<vector<int>> kp(n+1, vector<int>(w+1,-1));

    double maxProfit = knapsack(n, w, price, weight);
    cout << "The maximum value that can be obtained is: " << maxProfit << endl;

}