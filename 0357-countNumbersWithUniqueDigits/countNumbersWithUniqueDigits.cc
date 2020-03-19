class Solution {
  public:
    auto countNumbersWithUniqueDigits(int n) -> int {
        if (n == 0) {
            return 1;
        }
        int arr[10];
        arr[0] = 10;
        arr[1] = 91;
        for (int i = 2; i < 10 && i < n; i++) {
            arr[i] = (10 - i) * (arr[i - 1] - arr[i - 2]) + arr[i - 1];
        }
        if (n <= 10) {
            return arr[n - 1];
        }
        return arr[9];
    }
};