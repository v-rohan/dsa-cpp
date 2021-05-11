#include <iostream>
using namespace std;

pair<int, int> func(int *arr, int m, int n, int target)
{
    int i = 0;
    int j = n - 1;
    while(true)
        {
            if (i >= m || j < 0)
                break;
            if (*((arr + i * n) + j) == target)
                return make_pair(i, j);
            else if (*((arr + i * n) + j) < target)
                i++;
            else if (*((arr + i * n) + j) > target)
                j--;
        }
    return make_pair(-1, -1);
}

int main()
{
    int rows = 3, cols = 3;
    int arr[rows][cols] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int target = 2;
    pair<int, int> a = func((int *)arr, rows, cols, target); //function call
    cout << "Found "<<target<<" at ("<<a.first<<", "<<a.second<<")\n";
    return 0;
}