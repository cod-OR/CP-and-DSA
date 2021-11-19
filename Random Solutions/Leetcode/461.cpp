class Solution {
public:
    int hammingDistance(int x, int y) {
      
      // when the bit is different, their xor will have a 1 at that position
      // so we just need to count the set bits in the xor 
      
        return __builtin_popcount(x^y);
    }
};
