
// 797. All Paths From Source to Target

// maintain the path vector while doing dfs => push back while visiting and pop back while going back
// insert a copy of current path into solution when a leaf is hit


class Solution {
    
void findPath(int currNode, int dest, vector<int> &visited, vector<int> &currPath, vector<vector<int>> &paths,vector<vector<int>>& graph){
    if(visited[currNode])return;
    visited[currNode]=1;
    currPath.push_back(currNode);
    
    if(currNode == dest){
        paths.push_back(currPath);
    }
    else{
        for(auto i:graph[currNode]){
            if(!visited[i]){
                findPath(i,dest,visited,currPath,paths,graph);
            }
        }
    }
    
    currPath.pop_back();
    visited[currNode]=0;
}
    
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int> > paths;
        vector<int> currPath;
        
        int n=graph.size();
        vector<int> visited(n);
        
        findPath(0,n-1,visited,currPath, paths,graph);
        return paths;
    }
};
