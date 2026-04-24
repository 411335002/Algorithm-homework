class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        int n=costs.size();
        int mid=n/2;
        vector<int>diffList;
        int total=0;
        for(int i=0; i<n; i++)
        {
            total += costs[i][1];  //先假設每個人都去 B 城市
            int difference = costs[i][0] - costs[i][1];
            diffList.push_back(difference);
        }
        sort(diffList.begin(),diffList.end());

        for(int i=0; i<mid; i++)
        {
            total += diffList[i];
        }
        return total;
    }
};