class Solution {
public:

void dfs(int u,vector<vector<int>> &graph,vector<bool>&sus){
    sus[u]=true;
    for(int v:graph[u]){
        if(!sus[v]){
            dfs(v,graph,sus);
        }
    }
}

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>graph(n);
        for(auto &e:invocations)
        graph[e[0]].push_back(e[1]);
        vector<bool>sus(n,false);
        dfs(k,graph,sus);
        for(auto &e:invocations){
            int a=e[0];
            int b=e[1];
            if(!sus[a]&&sus[b]){
                vector<int>all;
                for(int i=0;i<n;i++){
                    all.push_back(i);
                }
                return all;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(!sus[i])
            ans.push_back(i);
        }
        return ans;
    }
};