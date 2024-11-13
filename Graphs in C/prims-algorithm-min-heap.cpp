// PRIM'S ALGORITHM FOR MST - function

class solution
{
    public:
    
    int spanningTree(int V, vector<vector<int>>adj[])
    {
        // priority queue for pair<int, pair<int, int>>
        // for weight, node, parent
        priority_queue<int, vector<int>, greater<int>>pq; // replace int by pair<int, pair<int, pair<int,int>>
        
        vector<bool>IsMST(V,0);
        vector<int>parent(V);
        
        int cost = 0;
        pq.push({0, {0,-1}}); // intitial weight, intitial node, initial node ka parent
        
        while(!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int par = pq.top().second.second;
            pq.pop();
            
            if (!IsMST[node]) // if node not part of MST
            {
                IsMST[node] = 1;
                cost += wt;
                parent[node] = par;
                
                // node ke agal bagal aur edges kaha kaha jaa rahi hain
                
                for (int j = 0; j < adj[node].size(); j++)
                {
                    if (!IsMST[adj[node][j][0]])
                    {
                        pq.push({adj[node][j][1], {adj[node][j][0], node}});
                    }
                }
            }
        }
        
        return cost;
    }
}