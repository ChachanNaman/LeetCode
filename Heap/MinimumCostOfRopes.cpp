// MinimumCostOfRopes
// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1?page=1&category=Heap&sortBy=submissions

class Solution
{
public:
    int minCost(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        int cost = 0;
        while (pq.size() > 1)
        {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();

            int sum = a + b;
            cost = cost + sum;

            pq.push(sum);
        }
        return cost;
    }
};
