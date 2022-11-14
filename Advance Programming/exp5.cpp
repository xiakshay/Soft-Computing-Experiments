#include <bits/stdc++.h>
using namespace std;

vector<int> djikstra(vector<int> gh[], int V, int src)
{

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    vector<bool> fin(V, false);

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;

        for (int i = 0; i < V; i++)
            if (!fin[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        fin[u] = true;

        for (int v = 0; v < V; v++)

            if (gh[u][v] != 0 && fin[v] == false)
                dist[v] = min(dist[v], dist[u] + gh[u][v]);
    }
    return dist;
}

int main()
{

    int v;

    cout << "Enter the number of vertices : \n";
    cin >> v;

    vector<int> gh[v];

    cout << "\nEnter values in Graph : \n";

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            int temp;
            cin >> temp;
            gh[i].push_back(temp);
        }
    }

    cout << "\nEntered values in graph is as follows : \n";

    for (int i = 0; i < v; i++)
    {
        for (int x : gh[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    cout << "\nThe shortest path from index 0 is : \n";

    int vertex = 0;

    for (int x : djikstra(gh, v, 0))
    {
        cout << vertex++ << " --> " << 0 << " == " << x << endl;
    }

    return 0;
}
