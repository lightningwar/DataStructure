#include <iostream>
#include <algorithm>
using namespace std;

int partition (int arr[], int low, int high) {
    int pivot = low + rand() % (high - low);  // 随机选取枢轴
    int temp = arr[pivot];
    swap (arr[low], arr[pivot]);  // 交换枢轴与low的位置
    while (low < high) {
        while (low < high && arr[high] >= temp)  --high;
        arr[low] = arr[high];
        while (low < high && arr[low] <= temp)  ++low;
        arr[high] = arr[low];
    }
    arr[low] = temp;
    return low;
}

void QuickSort (int arr[], int low, int high) {
    if (low < high) {
        int pivot_pos = partition(arr, low, high);
        quickSort (arr, low, pivot_pos - 1);
        quickSort (arr, pivot_pos + 1, high);
    }
}

int main() {
    int arr[] = {9,8,3,1,2,5,6,4,7,10,-10,-2,-8,8,11};
    int num = sizeof(arr) / sizeof(arr[0]);
    quickSort (arr, 0, num - 1);
    for (int i = 0; i < num; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}
