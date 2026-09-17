int minSumOfLengths(int* arr, int arrSize, int target) {
    int INF = 1000000000;
    int best[arrSize];
    for (int i = 0; i < arrSize; i++)
        best[i] = INF;

    int left = 0;
    int sum = 0;
    int ans = INF;
    int minLen = INF;

    for (int right = 0; right < arrSize; right++) {
        sum += arr[right];

        while (sum > target) {
            sum -= arr[left];
            left++;
        }

        if (sum == target) {
            int len = right - left + 1;

            if (left > 0 && best[left - 1] != INF) {
                int total = len + best[left - 1];
                if (total < ans)
                    ans = total;
            }

            if (len < minLen)
                minLen = len;
        }

        best[right] = minLen;
    }
    return ans == INF ? -1 : ans;
}