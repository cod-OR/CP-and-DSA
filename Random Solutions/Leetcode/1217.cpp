

// 1217. Minimum Cost to Move Chips to The Same Position

// basicaly, if we want to move a coin to position with same parity, no cost is required;
// This is as if, we have only two positions, one with odd parity, one with even;
// Now all we need to do is to move coins on one of those positions to other, obviously, we will choose the position with less number of coins
// Number of coins is same as cost of moving them all

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n=position.size();
        int cost[2]={0,0};
        for(int i=0;i<n;i++){
            cost[position[i]%2]++;
        }
        return min(cost[0], cost[1]);
    }
};

