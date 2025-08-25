class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& edge) {
        vector<int>ans;
        vector<vector<int>>graph(v);
        vector<int>indegree(v,0);
        for(int i=0;i<edge.size();i++){
            int a = edge[i][0]; 
            int b = edge[i][1]; //b-->a
            graph[b].push_back(a);
            indegree[a]++;
        }
        queue<int>q;
        for(int i=0;i<v;i++){
            if(indegree[i]==0)q.push(i); //vertices with 0 indeg
        }
        while(q.size()){
            int curr=q.front();
            ans.push_back(curr);
            q.pop();
            for(auto neighbor:graph[curr]){ //unvisited== uninstalled yet
                indegree[neighbor]--;
                if(indegree[neighbor]==0)q.push(neighbor);
            }
        }
        if(ans.size()==v)return ans;
        else return {};
    }
};