#include <iostream>
#include <vector>
using namespace std;

int partition(int *arr, int low, int high)
{
  //  int rand_piv = random_pivot(low, high);
  //  swap(arr[rand_piv], arr[high]);
    int pivot = high;
    int index = low;
    for (int i = low; i < high; i++)
        if (arr[i] < arr[pivot])
        {
            swap(arr[i], arr[index]);
            index++;
        }
    
    swap(arr[index],arr[pivot]);

    return index;
}

void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quicksort(arr, 0, n - 1);
    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}