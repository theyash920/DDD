int kthElement(int *a, int n, int *b, int m, int k) {
    if (n > m) return kthElement(b, m, a, n, k);

    int low = (k - m > 0) ? (k - m) : 0;      // replaces max(k-m, 0)
    int high = (k < n) ? k : n;                // replaces min(k, n)
    int left = k;

    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (mid1 < n) r1 = a[mid1];
        if (mid2 < m) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            return (l1 > l2) ? l1 : l2;        // replaces max(l1, l2)
        }
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }

    return 0;
}