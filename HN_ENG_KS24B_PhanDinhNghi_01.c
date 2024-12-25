#include<stdio.h>
#include <stdlib.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}
int secondSmallest(int arr[], int n) {
    int smallest = arr[0], secondSmallest = arr[1];
    if (smallest > secondSmallest) {
        int temp = smallest;
        smallest = secondSmallest;
        secondSmallest = temp;
    }
    for (int i = 2; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }
    return secondSmallest;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int removeDuplicates(int arr[], int *n) {
    int index = 0;
    for (int i = 0; i < *n; i++) {
        int j;
        for (j = 0; j < index; j++) {
            if (arr[i] == arr[j]) break;
        }
        if (j == index) {
            arr[index++] = arr[i];
        }
    }
    *n = index;
    return 0;
}
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return 1;
        if (arr[mid] < target) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}
void reverseArray(int arr[], int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d ", i, arr[i]);
    }
    printf("\n");
}

int main() {
    int n, choice, element, position;
    int arr[100];

    while (1) {
        printf("\n===============Menu===============\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong cac so nguyen to trong mang\n");
        printf("4. Tim gia tri nho thu hai trong mang\n");
        printf("5. Them mot phan tu vao vi tri ngau nhien\n");
        printf("6. Xoa phan tu tai mot vi tri\n");
        printf("7. Sap xep mang theo thu tu giam dan\n");
        printf("8. Tim kiem phan tu trong mang (Binary Search)\n");
        printf("9. Xoa toan bo phan tu trung lap trong mang\n");
        printf("10. Dao nguoc thu tu cac phan tu trong mang\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap gia tri cho arr[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3:
                {
                    int primeCount = 0;
                    for (int i = 0; i < n; i++) {
                        if (isPrime(arr[i])) {
                            primeCount++;
                        }
                    }
                    printf("So luong cac so nguyen to trong mang: %d\n", primeCount);
                }
                break;
            case 4:
                printf("Gia tri nho thu hai trong mang: %d\n", secondSmallest(arr, n));
                break;
            case 5:
                printf("Nhap phan tu can them: ");
                scanf("%d", &element);
                printf("Nhap vi tri can them (0-%d): ", n);
                scanf("%d", &position);
                if (position < 0 || position > n) {
                    printf("Vi tri khong hop le.\n");
                    break;
                }
                for (int i = n; i > position; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[position] = element;
                n++;
                break;
            case 6:
                printf("Nhap vi tri muon xoa (0-%d): ", n - 1);
                scanf("%d", &position);
                if (position < 0 || position >= n) {
                    printf("Vi tri khong hop le.\n");
                    break;
                }
                for (int i = position; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                n--;
                break;
            case 7:
                insertionSort(arr, n);
                printf("Mang sau khi sap xep giam dan: ");
                displayArray(arr, n);
                break;
            case 8:
                printf("Nhap phan tu can tim: ");
                scanf("%d", &element);
                if (binarySearch(arr, n, element)) {
                    printf("Phan tu %d co ton tai trong mang.\n", element);
                } else {
                    printf("Phan tu %d khong ton tai trong mang.\n", element);
                }
                break;
            case 9:
                removeDuplicates(arr, &n);
                printf("Mang sau khi xoa phan tu trung lap: ");
                displayArray(arr, n);
                break;
            case 10:
                reverseArray(arr, n);
                printf("Mang sau khi dao nguoc: ");
                displayArray(arr, n);
                break;
            case 0:
                exit(0);

            default:
                printf("Lua chon khong hop le.\n");
        }
    }
    return 0;
}

    
       