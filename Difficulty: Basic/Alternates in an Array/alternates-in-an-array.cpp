class Solution {
  public:
    vector<int> getAlternates(vector<int> &arr) {
        // code here
        vector<int> result;
        
        for(int i = 0; i < arr.size(); i += 2) {
            result.push_back(arr[i]);
        }
        
        return result;
    }
};