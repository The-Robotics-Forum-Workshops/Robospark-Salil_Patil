#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int mincost(vector<int> const &prices)
{
    priority_queue<int, vector<int>, greater<int>> priq(prices.begin(), prices.end());
    int cost = 0;
    while (priq.size() > 1)
    {
        int x = priq.top();
        priq.pop();
        int y = priq.top();
        priq.pop();
        int sum = x + y;
        priq.push(sum);
        cost += sum;
    }

    return cost;
}

int main()
{
    vector<int> prices = {2,8,5,8,12,14};
    cout << "The minimum cost for connection of ropes is: " << mincost(prices);
    return 0;
}
