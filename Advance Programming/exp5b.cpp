#include <bits/stdc++.h>
using namespace std;

#define INF 99999

void floydWarshall(vector<int> graph[], int v)
{
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (graph[i][j] > (graph[i][k] + graph[k][j]) && (graph[k][j] != INF && graph[i][k] != INF))
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    cout << "\nThe Shortest distance btw every pair of distances is : \n";

    for (int i = 0; i < v; i++)
    {
        for (int x : graph[i])
        {
            if (x == 99999)
            {
                cout << "INF ";
            }
            else
            {
                cout << x << " ";
            }
        }
        cout << endl;
    }

    cout << "\nThe transitive closure of following graph matrix is : \n";

    for (int i = 0; i < v; i++)
    {
        for (int x : graph[i])
        {
            if (x == INF)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int v;

    cout << "Enter the number of vertices : \n";
    cin >> v;

    vector<int> graph[v];

    cout << "\nEnter values in Graph : \n";

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            int temp;
            cin >> temp;

            if (temp == -1)
            {
                temp = INF;
            }
            graph[i].push_back(temp);
        }
    }

    cout << "\nEntered values in graph is as follows : \n";

    for (int i = 0; i < v; i++)
    {
        for (int x : graph[i])
        {
            if (x == 99999)
            {
                cout << "INF ";
            }
            else
            {
                cout << x << " ";
            }
        }
        cout << endl;
    }
    floydWarshall(graph, v);

    return 0;
}
