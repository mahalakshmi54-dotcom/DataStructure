#include <iostream>
using namespace std;

void merge(int a[], int left, int mid, int right) {
    int temp[100];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= right)
        temp[k++] = a[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

int main() {
    int a[] = {7, 25, 10, 45, 30, 15, 50, 20};
    int n = sizeof(a) / sizeof(a[0]);

    mergeSort(a, 0, n - 1);

    cout << "Sorted weights: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
    return 0;
}
