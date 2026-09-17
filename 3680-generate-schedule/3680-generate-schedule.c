/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced,
 * assume caller calls free().
 */

int** generateSchedule(int n, int* returnSize, int** returnColumnSizes) {

    if (n < 5) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int total = n * (n - 1);

    int** ans = (int**)malloc(total * sizeof(int*));
    *returnColumnSizes = (int*)malloc(total * sizeof(int));

    int idx = 0;

    for (int d = 2; d <= n - 2; d++) {

        for (int i = 0; i < n; i++) {

            ans[idx] = (int*)malloc(2 * sizeof(int));

            ans[idx][0] = i;
            ans[idx][1] = (i + d) % n;

            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }

    for (int i = 0; i < n; i++) {

        ans[idx] = (int*)malloc(2 * sizeof(int));
        ans[idx][0] = i;
        ans[idx][1] = (i + 1) % n;
        (*returnColumnSizes)[idx] = 2;
        idx++;
        ans[idx] = (int*)malloc(2 * sizeof(int));

        ans[idx][0] = (i + n - 1) % n;
        ans[idx][1] = (i + n - 2) % n;

        (*returnColumnSizes)[idx] = 2;
        idx++;
    }
    *returnSize = idx;
    return ans;
}