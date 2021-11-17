
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ind(n);
      
      // computing indegrees of each vertex
        for(auto edge:edges){
            ind[edge[1]]++;
        }
        vector<int> sol;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                sol.push_back(i);
            }
        }
        
        return sol;
    }
};
