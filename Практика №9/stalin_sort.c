int stalin_sort(int *a, int n) {
    if (n == 0) return 0;
    int k = 1;
    for (int i = 1; i < n; i++)
        if (a[i] >= a[k - 1])
            a[k++] = a[i];
    return k;
}
