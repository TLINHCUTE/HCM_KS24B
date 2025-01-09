#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;
    int choice, element, pos, x;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong cac so nguyen to trong mang\n");
        printf("4. Tim gia tri nho thu hai trong mang\n");
        printf("5. Them mot phan tu vao vi tri ngau nhien\n");
        printf("6. Xoa phan tu tai vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan (Insertion Sort)\n");
        printf("8. Tim kiem phan tu trong mang (Binary Search)\n");
        printf("9. Xoa toan bo phan tu trung lap trong mang\n");
        printf("10. Dao nguoc thu tu cua cac phan tu trong mang\n");
        printf("11. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap so phan tu cua mang: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap gia tri cho arr[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d, ", i, arr[i]);
                }
                printf("\n");
                break;
            case 3:
                {
                    int count = 0;
                    for (int i = 0; i < n; i++) {
                        if (isPrime(arr[i])) {
                            count++;
                        }
                    }
                    printf("So luong so nguyen to trong mang: %d\n", count);
                }
                break;
            case 4:
                {
                    if (n < 2) {
                        printf("Mang phai co it nhat 2 phan tu.\n");
                        break;
                    }
                    int smallest = arr[0], second = arr[1];
                    if (smallest > second) {
                        int temp = smallest;
                        smallest = second;
                        second = temp;
                    }
                    for (int i = 2; i < n; i++) {
                        if (arr[i] < smallest) {
                            second = smallest;
                            smallest = arr[i];
                        } else if (arr[i] < second && arr[i] != smallest) {
                            second = arr[i];
                        }
                    }
                    printf("Gia tri nho thu hai trong mang: %d\n", second);
                }
                break;
            case 5:
                printf("Nhap phan tu can them: ");
                scanf("%d", &element);
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                if (pos < 0 || pos > n) {
                    printf("Vi tri khong hop le.\n");
                } else {
                    for (int i = n; i > pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = element;
                    n++;
                }
                break;
            case 6:
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Vi tri khong hop le.\n");
                } else {
                    for (int i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                }
                break;
            case 7:
                for (int i = 1; i < n; i++) {
                    int key = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] < key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang sau khi sap xep giam dan: ");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d, ", i, arr[i]);
                }
                printf("\n");
                break;
            case 8:
                printf("Nhap phan tu can tim: ");
                scanf("%d", &x);
                int left = 0, right = n - 1, found = -1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (arr[mid] == x) {
                        found = mid;
                        break;
                    } else if (arr[mid] < x) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (found != -1) {
                    printf("Phan tu %d duoc tim thay tai vi tri %d.\n", x, found);
                } else {
                    printf("Phan tu %d khong ton tai trong mang.\n", x);
                }
                break;
            case 9:
                if (n == 0) break;
                int new_n = 1;
                for (int i = 1; i < n; i++) {
                    bool duplicate = false;
                    for (int j = 0; j < new_n; j++) {
                        if (arr[i] == arr[j]) {
                            duplicate = true;
                            break;
                        }
                    }
                    if (!duplicate) {
                        arr[new_n++] = arr[i];
                    }
                }
                n = new_n;
                printf("Mang sau khi xoa phan tu trung lap: ");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d, ", i, arr[i]);
                }
                printf("\n");
                break;
            case 10:
                int start = 0, end = n - 1;
                while (start < end) {
                    int temp = arr[start];
                    arr[start] = arr[end];
                    arr[end] = temp;
                    start++;
                    end--;
                }
                printf("Mang sau khi dao nguoc: ");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d, ", i, arr[i]);
                }
                printf("\n");
                break;
            case 11:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 11);

    return 0;
}
