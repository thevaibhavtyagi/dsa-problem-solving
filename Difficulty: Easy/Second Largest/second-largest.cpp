class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        
        int max = arr[0];
        int s_max = -1;
        
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > max) {
                max = arr[i];
            }
        }
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > s_max && arr[i] != max) {
                s_max = arr[i];
            }
        }
        
        if(s_max == max) {
            return -1;
        } else {
            return s_max;
        }
        
    }
};