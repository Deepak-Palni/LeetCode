/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>
char** maxNumOfSubstrings(char* s, int* returnSize) {
    int n = strlen(s);
    int first[26], last[26];
    for (int i = 0; i < 26; i++) {
        first[i] = n;
        last[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        if (first[c] == n)
            first[c] = i;
        last[c] = i;
    }
    int left[26], right[26];
    int count = 0;
    for (int c = 0; c < 26; c++) {
        if (last[c] == -1)
            continue;
        int l = first[c];
        int r = last[c];
        int valid = 1;
        for (int i = l; i <= r; i++) {
            int x = s[i] - 'a';
            if (first[x] < l) {
                valid = 0;
                break;
            }
            if (last[x] > r)
                r = last[x];
        }
        if (valid) {
            left[count] = l;
            right[count] = r;
            count++;
        }
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (right[i] > right[j]) {
                int temp = right[i];
                right[i] = right[j];
                right[j] = temp;
                temp = left[i];
                left[i] = left[j];
                left[j] = temp;
            }
        }
    }
    char** ans = (char**)malloc(26 * sizeof(char*));
    *returnSize = 0;
    int prevEnd = -1;
    for (int i = 0; i < count; i++) {
        if (left[i] > prevEnd) {
            int len = right[i] - left[i] + 1;
            ans[*returnSize] = (char*)malloc((len + 1) * sizeof(char));
            strncpy(ans[*returnSize], s + left[i], len);
            ans[*returnSize][len] = '\0';
            (*returnSize)++;
            prevEnd = right[i];
        }
    }
    return ans;
}