
// 986. Interval List Intersections

// Given two lists of intervals, return a list of their intersections

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0;
        int j = 0;
        int size1 = firstList.size();
        int size2 = secondList.size();
        vector< vector<int> > intersections;
        while(i < size1 and j < size2){
            
            int L = max(firstList[i][0], secondList[j][0]);
            int R = min(firstList[i][1], secondList[j][1]);
            
            // if [L,R] is valid, it is the intersection of current intervals
            // and then we can add it to the solution
            
            if(L <= R){
                intersections.push_back({L, R});
            }
            
            // greedy choice: increment the one who ends earlier
            // because, the other may still contribute to the solution
            
            if(firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
            
        }
        
        return intersections;
        
    }
};
