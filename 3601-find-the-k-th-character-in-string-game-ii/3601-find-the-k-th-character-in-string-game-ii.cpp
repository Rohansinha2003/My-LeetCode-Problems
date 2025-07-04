 class Solution {
public:
  char kthCharacter(long long k, vector<int>& ops) {
    int n = ceil(log2(k));
    int inc = 0;
    for(int i = n - 1; i >= 0; --i) {
      long half = 1LL << i;
      if (k > half) {
        k -= half;
        inc += ops[i];
      }
    }
    return 'a' + (inc % 26);
  }
};
