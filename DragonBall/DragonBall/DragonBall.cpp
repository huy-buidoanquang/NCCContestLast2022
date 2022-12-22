#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;
int k, q, u, v, balls_of_node;
int ballnumber_of_node[MAX],
size_of_node[MAX],
cnt[MAX],
big[MAX],
p[MAX],
col[MAX],
st[MAX],
ft[MAX],
ver[MAX];
vector <int> ways[MAX];
int result[MAX];

void input() {
	/*cin >> k >> q;
	for (int i = 1; i <= k; i++)
		cin >> ballnumber_of_node[i];
	for (int i = 1; i < k; i++) {
		cin >> u >> v;
		ways[u].push_back(v);
		ways[v].push_back(u);
	}*/
	k = 7;
	q = 2;
	//
	ballnumber_of_node[1] = 1;
	ballnumber_of_node[2] = 2;
	ballnumber_of_node[3] = 2;
	ballnumber_of_node[4] = 1;
	ballnumber_of_node[5] = 1;
	ballnumber_of_node[6] = 2;
	ballnumber_of_node[7] = 1;
	//
	ways[1].push_back(2);
	ways[2].push_back(1);
	ways[2].push_back(3);
	ways[3].push_back(2);
	ways[2].push_back(4);
	ways[4].push_back(2);
	ways[1].push_back(5);
	ways[5].push_back(1);
	ways[5].push_back(6);
	ways[6].push_back(5);
	ways[4].push_back(7);
	ways[7].push_back(4);
}

// calculate the size of subtree of every node
// calculate only one dimension from u to v
void calculateSize(int u) {
	size_of_node[u] = 1;
	for (int &v : ways[u])
		if (v != p[u]) {
			p[v] = u;
			calculateSize(v);
			size_of_node[u] += size_of_node[v]; // add size of child to its parent node
		}
}

void add(int u, int p, int val) {
	if (cnt[ballnumber_of_node[u]] == 1 && val == -1) balls_of_node--;
	if (cnt[ballnumber_of_node[u]] == 0 && val == 1) balls_of_node++;
	cnt[ballnumber_of_node[u]] += val;
	for (int v : ways[u])
		if (v != p && v != big[u])
			add(v, u, val);
}

//void dfs(int u, int p, bool keep) {
//    big[u] = -1;
//    for (auto v : ways[u])
//        if (v != p && (big[u] == -1 || size_of_node[v] > size_of_node[big[u]]))
//            big[u] = v;
//    for (auto v : ways[u])
//        if (v != p && v != big[u])
//            dfs(v, u, 0);
//    if (big[u] != -1)
//        dfs(big[u], u, 1);
//    //else
//    //    ways[u] = vector<int>();
//    ways[u].push_back(u);
//    //cnta[col[u]]++;
//    cnt[ballnumber_of_node[u]]++;
//    for (auto v : ways[u])
//        if (v != p && v != big[u])
//            for (auto x : ways[u]) {
//                cnt[ballnumber_of_node[v]]++;
//                ways[u].push_back(x);
//                if (cnt[ballnumber_of_node[u]] == 0) balls_of_node++;
//            }
//    res[u] = (balls_of_node == q);
//    big[u] = 0;
//    if (!keep)
//        for (auto v : ways[u]) {
//            cnt[ballnumber_of_node[v]]--;
//            if (cnt[ballnumber_of_node[u]] == 1) balls_of_node--;
//        }
//}

//void dfs(int v, int p, bool keep) {
//    int mx = -1, bigChild = -1;
//    for (auto u : ways[v])
//        if (u != p && size_of_node[u] > mx)
//            mx = size_of_node[u], bigChild = u;
//    for (auto u : ways[v])
//        if (u != p && u != bigChild)
//            dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
//    if (bigChild != -1)
//        dfs(bigChild, v, 1);  // bigChild marked as big and not cleared from cnt
//    for (auto u : ways[v])
//        if (u != p && u != bigChild)
//            for (int p = st[u]; p < ft[u]; p++)
//                cnt[col[ver[p]]]++;
//    cnt[col[v]]++;
//    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
//    if (keep == 0)
//        for (int p = st[v]; p < ft[v]; p++)
//            cnt[col[ver[p]]]--;
//}

void dfs(int u, int p, bool keep) {
	big[u] = -1;
	for (int v : ways[u])
		if ((v != p) && (big[u] == -1 || size_of_node[v] > size_of_node[big[u]]))
			big[u] = v;
	for (int v : ways[u])
		if (v != p && v != big[u])
			dfs(v, u, 0);
	if (big[u] != -1)
		dfs(big[u], u, 1);
	add(u, p, 1);
	result[u] = (balls_of_node == q) ? 1 : 0;
	big[u] = 0;
	if (!keep)
		add(u, p, -1);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	input();
	calculateSize(1);
	dfs(1, 0, 1);
	for (int i = 1; i <= k; i++)
		cout << result[i];
	/*for (int i = 1; i <= k; i++)
		cout << (cnt[i] == q ? 1 : 0);*/
	return 0;
}