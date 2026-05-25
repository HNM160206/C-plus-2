#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void printArray(const vector<int>& a)
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

    cout << "\nHeapify nut i = " << i << endl;

    if (left < n)
        cout << "Con trai  a[" << left << "] = "
             << a[left] << endl;

    if (right < n)
        cout << "Con phai  a[" << right << "] = "
             << a[right] << endl;

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

        cout << "Trang thai hien tai:\n";
        printArray(a);

        heapify(a, n, largest);
    }
    else
    {
        cout << "Khong can doi\n";

        cout << "Trang thai hien tai:\n";
        printArray(a);
    }
}

void heapSort(vector<int>& a)
{
    int n = a.size();

    cout << "\n========================\n";
    cout << "      VUN DONG\n";
    cout << "========================\n";

    // Build Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        cout << "\n--- Heapify tai i = "
             << i
             << " ---\n";

        heapify(a, n, i);

        cout << "Sau heapify i = "
             << i
             << ":\n";

        printArray(a);
    }

    cout << "\n========================\n";
    cout << "      SAP XEP\n";
    cout << "========================\n";

    // Heap Sort
    for (int i = n - 1; i > 0; i--)
    {
        cout << "\nDua max "
             << a[0]
             << " xuong cuoi\n";

        swap(a[0], a[i]);

        cout << "Sau khi doi:\n";
        printArray(a);

        cout << "\nVun lai heap:\n";

        heapify(a, i, 0);

        cout << "Mang sau khi vun lai:\n";
        printArray(a);
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

    cout << "\n========================\n";
    cout << "Mang sau khi sap xep:\n";
    printArray(a);

    return 0;
}
