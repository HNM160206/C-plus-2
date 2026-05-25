#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void printArray(const vector<string>& a, string msg)
{
    cout << left << setw(30) << msg;

    for (string x : a)
        cout << x << " ";

    cout << endl;
}

void heapify(vector<string>& a, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // So sánh từ điển
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

void heapSort(vector<string>& a)
{
    int n = a.size();

    cout << "===== VUN DONG =====" << endl;

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
    vector<string> a =
    {
        "32", "51", "27", "83", "96",
        "11", "45", "75", "66"
    };

    printArray(a, "Mang ban dau:");

    cout << endl;

    heapSort(a);

    cout << endl;

    printArray(a, "Mang sau cung:");

    return 0;
}
