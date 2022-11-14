#include <iostream>
using namespace std;

void leftRotation(int arr[], int n)
{
    int j, temp;
    temp = arr[0];
    for (j = 0; j < n - 1; j++)
    {
        arr[j] = arr[j + 1];
    }
    arr[j] = temp;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n = 0;
    cout << "Size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter element : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int r = 0;
    cout << "No of rotation : ";
    cin >> r;

    cout << "\nArray before rotation : ";
    printArray(arr, n);

    for (int i = 0; i < r; i++)
    {
        leftRotation(arr, n);
        cout << "\nArray after " << i + 1 << " rotation : ";
        printArray(arr, n);
    }

    cout << "\nFinal array : ";
    printArray(arr, n);
    return 0;
}

