int *stalin_sort(int *a, int n) {
    if (n == 0) return 0;
    int k = 1;
    for (int i = 1; i < n; i++)
        if (a[i] >= a[k - 1])
            a[k++] = a[i];
    return;
}

int main(){

    int arr[] = {3,4,6,19,44,1};
    stalin_sort(arr, 6);
    return 0;
}

// Hello, I am Macintosh. It sure is great to get out of that bag!-
// Access denied.