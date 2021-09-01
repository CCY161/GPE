#include <iostream>
#include <vector>

#define MAX_M ( 21 )

using namespace std;

int main ()
{
	int n, m;
	vector< vector<int> > table (MAX_M);

	while (cin >> n >> m)
	{
		if ( table[m].size() == 0 )
		{
			const int total = 3 * (1 << ( m-1 ));

			for ( int i = 0; i < total; i++ )
			{
				if ( i <= 2 )
				{
					table[m].push_back(1);
				}
				else
				{
					int ans = table[m].back() + table[m][table[m].size() - 2];

					table[m].push_back( ans & ( ( 1 << m ) -1 ) );
				}
			}

		}
		cout << table[m][n % (3 * (1 << (m-1)))] << '\n';
	}

	return 0;
}
