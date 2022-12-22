#include <iostream>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

map<long, long> map1, map2;
long num, total = 0;
long unsigned int n, i;
vector<long> v;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    /*while (v.size() < n && (cin >> num)) {
        v.push_back(num);
    }*/
    for (long i : v) {
        map1[i]++;
        if (map1[i] == 2)
        {
            total += 1;
        }
        else if (map1[i] > 2)
        {
            total += map1[i] - 1;
        }
    }
    for (long i : v) {
        cout << total - map1[i] + 1 << endl;
    }
}
//#include <numeric>
//#include <iostream>
//#include <map>
//#include <string>
//#include <utility>
//
//using namespace std;
//
//long total = 0;
//int n, i;
//
//int main()
//{
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	/*cin >> n;
//	long arr[5], map1[5] = { 0 };
//	for (i = 0; i < n; i++)
//		cin >> arr[i];
//	for (i = 0; i < n; i++) {
//		map1[arr[i]]++;
//	}
//
//	for (i = 0; i < n; i++) {
//		total += map1[i] * (map1[i] - 1) / 2;
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		map1[arr[i]] = total - map1[arr[i]] + 1;
//		cout << map1[arr[i]];
//	}
//	cout << output;*/
//
//	cin >> n;
//	int arr[n], map[n];
//	for (int i = 1; i <= n; i++) {
//		cin >> arr[i];
//		map[arr[i]]++;
//	}
//	for (int i = 1; i <= n; i++)
//		total += map[i] * (map[i] - 1) / 2;
//	for (int i = 1; i <= n; i++)
//		cout << total - (map[arr[i]] - 1) << endl;
//}