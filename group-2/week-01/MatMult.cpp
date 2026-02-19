#include <iostream>
#include <vector>

using namespace std;

#define MAX 25
    
long long matrix1[MAX][MAX];
long long matrix2[MAX][MAX];
long long matrix3[MAX][MAX];

int main()
{
    int n, m, k;

    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix1[i][j];
        }
    }

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            cin >> matrix2[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; j++)
        {
            for (int h = 0; h < m; ++h)
            {
                matrix3[i][j] += matrix1[i][h] * matrix2[h][j];
			}
		}
    }
    
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < k; j++)
    	{
    		cout << matrix3[i][j] << " ";
		}
		cout << endl;
	}

    return 0;
}
