class Solution {
  public:
    bool isPrime(int n) {
        if(n <= 1) {
            return false;
        }
        
        bool is_prime = true;
            
            for(int i = 2; i * i <= n; i++) {
                if(n % i == 0) {
                    is_prime = false;
                    break;
                }
            }
            
        return is_prime ? true : false;
        
    }
};
