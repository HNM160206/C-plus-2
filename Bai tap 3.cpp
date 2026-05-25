#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void printArray(vector<int> a)
{
    for (int x : a)
        cout << setw(4) << x;

    cout << endl;
}

void heapify(vector<int>& a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(a[i], a[largest]);

        // In trạng thái sau mỗi lần đổi khi vun đống
        printArray(a);

        heapify(a, n, largest);
    }
}

void heapSort(vector<int>& a)
{
    int n = a.size();

    cout << "\n===== CAC BUOC VUN DONG =====\n";

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);

        // Trạng thái sau mỗi bước heapify
        printArray(a);
    }

    cout << "\n===== CAC BUOC SAP XEP =====\n";

    // Heap Sort
    for (int i = n - 1; i > 0; i--)
    {
        // Đưa max xuống cuối
        swap(a[0], a[i]);

        // In trạng thái sau khi đổi
        printArray(a);

        // Vun lại heap
        heapify(a, i, 0);

        // In trạng thái sau khi vun lại
        printArray(a);

        cout << endl;
    }
}

int main()
{
    int n;

    cout << "Nhap so phan tu: ";
    cin >> n;

    vector<int> a(n);

    cout << "Nhap day so:\n";

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nMang ban dau:\n";
    printArray(a);

    heapSort(a);

    cout << "\nMang sau khi sap xep:\n";
    printArray(a);

    return 0;
}
