#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void printArray(const vector<int>& a, string msg)
{
    cout << left << setw(30) << msg;

    for (int x : a)
        cout << x << " ";

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
        cout << "Doi "
             << a[i]
             << " va "
             << a[largest]
             << endl;

        swap(a[i], a[largest]);

        printArray(a, "Trang thai:");

        heapify(a, n, largest);
    }
}

void heapSort(vector<int>& a)
{
    int n = a.size();

    cout << "\n===== VUN DONG =====" << endl;

    // Build Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        cout << "\nHeapify i = " << i << endl;

        heapify(a, n, i);

        printArray(a, "Sau heapify:");
    }

    cout << "\n===== SAP XEP =====" << endl;

    // Heap Sort
    for (int i = n - 1; i > 0; i--)
    {
        cout << "\nDoi max "
             << a[0]
             << " voi "
             << a[i]
             << endl;

        swap(a[0], a[i]);

        printArray(a, "Sau doi:");

        heapify(a, i, 0);

        printArray(a, "Sau vun lai:");
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

    cout << endl;

    printArray(a, "Mang ban dau:");

    heapSort(a);

    cout << endl;

    printArray(a, "Mang da sap xep:");

    return 0;
}
