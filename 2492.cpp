class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<int>dist(n+1,INT_MAX/2);
        priority_queue<int,vector<int>,greater<int>>pq;
        pq.push(1);
        dist[1]=0;
        while(!pq.empty())
        {
            int node=pq.top();
            pq.pop();
            for(auto it:adj[node]){
                if(dist[it.first]>it.second)
                {
                    dist[it.first]=it.second;
                    pq.push(it.first);
                }
            }
        }
        int ans=INT_MAX/2;
        for(int i=2;i<=n;i++)
        {
            ans=min(ans,dist[i]);
        }
        return ans;

    }
};
