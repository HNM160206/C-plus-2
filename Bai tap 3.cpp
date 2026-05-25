#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void printArray(const vector<int>& a, string msg)
{
    cout << left << setw(35) << msg;

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
        swap(a[i], a[largest]);

        printArray(a,
            "Sau khi doi " + to_string(a[largest]) +
            " va " + to_string(a[i]) + ":");

        heapify(a, n, largest);
    }
}

void heapSort(vector<int>& a)
{
    int n = a.size();

    cout << "===== QUA TRINH VUN DONG =====" << endl;

    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);

        printArray(a,
            "Trang thai sau heapify i=" + to_string(i) + ":");
    }

    cout << endl;
    cout << "===== QUA TRINH SAP XEP =====" << endl;

    // Heap sort
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]);

        printArray(a,
            "Doi max xuong cuoi:");

        heapify(a, i, 0);

        printArray(a,
            "Sau khi vun lai heap:");

        cout << endl;
    }
}

int main()
{
    vector<int> a = {4, 10, 3, 5, 1};

    printArray(a, "Mang ban dau:");
    cout << endl;

    heapSort(a);

    printArray(a, "Mang sau cung:");

    return 0;
}
