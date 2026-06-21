#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int n = 11;

string city[n] = {
    "Ha Noi",
    "Hai Duong",
    "Phu Ly",
    "Hoa Binh",
    "Son Tay",
    "Thai Nguyen",
    "Bac Ninh",
    "Hung Yen",
    "Hai Phong",
    "Bac Giang",
    "Uong Bi"
};

vector<int> adj[n];

void addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void shortestPath(int start, int finish)
{
    bool visited[n] = {false};
    int parent[n];

    for(int i = 0; i < n; i++)
        parent[i] = -1;

    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int v : adj[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if(!visited[finish])
    {
        cout << "Khong co duong di!";
        return;
    }

    vector<int> path;

    for(int v = finish; v != -1; v = parent[v])
        path.push_back(v);

    cout << "\nDuong di ngan nhat:\n";

    for(int i = path.size()-1; i >= 0; i--)
    {
        cout << city[path[i]];
        if(i) cout << " -> ";
    }

    cout << "\nSo canh: " << path.size()-1;
}

int main()
{
    addEdge(0,1);
    addEdge(0,2);
    addEdge(0,3);
    addEdge(0,4);
    addEdge(0,5);
    addEdge(0,6);

    addEdge(1,7);
    addEdge(1,8);

    addEdge(2,7);

    addEdge(6,9);
    addEdge(6,10);

    addEdge(9,10);
    addEdge(8,10);

    cout << "Danh sach tinh:\n";
    for(int i = 0; i < n; i++)
        cout << i << ". " << city[i] << endl;

    int start, finish;

    cout << "\nNhap tinh bat dau: ";
    cin >> start;

    cout << "Nhap tinh dich: ";
    cin >> finish;

    shortestPath(start, finish);

    return 0;
}