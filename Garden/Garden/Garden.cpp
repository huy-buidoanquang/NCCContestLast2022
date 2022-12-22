#include <iostream>

using namespace std;

const int N = 300;
const long long lmax = 3000;

int n, m;
int a[N][N];
long long col[N];
long long row[2][N];

void input() {
	/*cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];*/
	m = n = 3;
	a[0][0] = -5; a[0][1] = -9; a[0][2] = 9;
	a[1][0] = -8; a[1][1] = -6; a[1][2] = 7;
	a[2][0] = -10; a[2][1] = 7; a[2][2] = 5;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	long long res = -lmax;
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < n; k++) {
			col[k] = 0;
			row[0][k] = row[0][k - 1] + a[i][k];
		}
		for (int j = i + 1; j < m; j++) {
			for (int k = 0; k < n; k++)
				row[1][k] = row[1][k - 1] + a[j][k];

			long long best = lmax;
			for (int k = 0; k < n; k++) {
				res = max(res, col[k] + row[0][k] + row[1][k] - best);
				best = min(best, row[0][k - 1] + row[1][k - 1] - col[k]);
			}

			for (int k = 0; k < n; k++)
				col[k] = col[k] + a[j][k];
		}
	}

	cout << res;
	return 0;
}