
// 732. My Calendar III

// Idea is very standard, to increment at the starting point and to decrement at ending point
// only change is, as numbers are large, we have to use a map
// And as we need to answer queries, prefix sum needs to be calculated at each query

// For each query, the maximum prefix sum will be the solution

// We could do this because c++ map allows traversal on keys in sorted order

class MyCalendarThree {
    
  map<int, int> data;
  
public:
  
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        data[start]++;
        data[end]--;
        int ans=1;
        int sum=0;
        for(auto it:data){
            sum+=it.second;
            ans=max(ans, sum);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
