#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

#define iii tuple<int, int, int>

int			first_union_in_my_life[5002];
vector<iii>	jjamtong;
vector<iii>	jjamtong2;
int			n, q;
int			jjamtong3[5002];
int			jjamtong4[5002];

int	first_finder_in_my_life(int first_union_idx_in_my_life)
{
	if (first_union_in_my_life[first_union_idx_in_my_life] == first_union_idx_in_my_life)
		return (first_union_idx_in_my_life);
	first_union_in_my_life[first_union_idx_in_my_life] = first_finder_in_my_life(first_union_in_my_life[first_union_idx_in_my_life]);
	return (first_union_in_my_life[first_union_idx_in_my_life]);
}

// 1 2 1 4 3
void	first_merger_in_my_life(int first_union_idx_in_my_life, int second_union_idx_in_my_life)
{
	first_union_idx_in_my_life = first_finder_in_my_life(first_union_idx_in_my_life);
	second_union_idx_in_my_life = first_finder_in_my_life(second_union_idx_in_my_life);
	if (first_union_idx_in_my_life == second_union_idx_in_my_life) return ;
	if (first_union_idx_in_my_life < second_union_idx_in_my_life)
	{
		first_union_in_my_life[second_union_idx_in_my_life] = first_union_idx_in_my_life;
		jjamtong4[first_union_idx_in_my_life] += jjamtong4[second_union_idx_in_my_life];
	}
	else
	{
		first_union_in_my_life[first_union_idx_in_my_life] = second_union_idx_in_my_life;
		jjamtong4[second_union_idx_in_my_life] += jjamtong4[first_union_idx_in_my_life];
	}
}

void	sol()
{
	int cnt = 0;
	for (int i = 0, j = 0; i < q; i++)
	{
		auto [cost, trgt, idx] = jjamtong2[i];
		for (; j < n; j++)
		{
			auto [r, p, q] = jjamtong[j];
			if (first_finder_in_my_life(p) == first_finder_in_my_life(q)) continue ;
			if (r < cost) break ;
			first_merger_in_my_life(p, q);
			cnt++;
			
			if (cnt == n - 1)
				break;
		}
		jjamtong3[idx] = jjamtong4[first_finder_in_my_life(trgt)] - 1;
		// cout << idx << ", " << ans << '\n';
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> n >> q;

	int tmp1, tmp2, tmp3;
	for (int i = 1; i <= n; i++)
	{
		first_union_in_my_life[i] = i;
		jjamtong4[i] = 1;
	}
	for (int i = 1; i <= n - 1; i++)
	{
		cin >> tmp1 >> tmp2 >> tmp3;
		jjamtong.push_back({tmp3, tmp1, tmp2});
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> tmp1 >> tmp2;
		jjamtong2.push_back({tmp1, tmp2, i});
	}
	sort(jjamtong.rbegin(), jjamtong.rend());
	sort(jjamtong2.rbegin(), jjamtong2.rend());
	sol();
	for (int i = 1; i <= q; i++)
	{
		cout << jjamtong3[i] << '\n';
	}
	return (0);
}

// 1 2 3 4
// 1 1 3 4
// 1 1 3 4

// 1 2 3 4
// 


// 이거 이해할 때 까지 읽고 안보고 구현하기
// #include <bits/stdc++.h>

// using namespace std;

// using edge = tuple<int, int, int>;
// using query = tuple<int, int, int>;

// class UF {
// public:
// 	UF(int N) : par(N), sz(N, 1) {
// 		for (int i = 0; i < N; ++i) {
// 			par[i] = i;
// 		}
// 	}
// 	int root(int x) {
// 		return par[x] == x ? x : (par[x] = root(par[x]));
// 	}
// 	bool same(int x, int y) {
// 		return root(x) == root(y);
// 	}
// 	bool unite(int x, int y) {
// 		x = root(x);
// 		y = root(y);
// 		if (x == y) {
// 			return false;
// 		}
// 		if (sz[x] < sz[y]) {
// 			swap(x, y);
// 		}
// 		par[y] = x;
// 		sz[x] += sz[y];
// 		return true;
// 	}
// 	int size(int x) {
// 		return sz[root(x)];
// 	}
// private:
// 	vector<int> par, sz;
// };

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(nullptr);
// 	int N{}, Q{};
// 	cin >> N >> Q;
// 	vector<edge> E(N - 1);
// 	for (auto &[w, a, b] : E) {
// 		cin >> a >> b >> w;
// 	}
// 	sort(E.rbegin(), E.rend());
// 	vector<query> A(Q);
// 	for (int i = 0; i < Q; ++i) {
// 		auto &[k, v, idx] = A[i];
// 		cin >> k >> v;
// 		idx = i;
// 	}
// 	sort(A.rbegin(), A.rend());
// 	vector<int> B(Q);
// 	UF uf(N + 1);
// 	for (int i = 0, j = 0; i < Q; ++i) {
// 		auto &[k, v, idx] = A[i];
// 		while (j < N - 1) {
// 			auto &[w, a, b] = E[j];
// 			if (k > w) {
// 				break;
// 			}
// 			uf.unite(a, b);
// 			++j;
// 		}
// 		B[idx] = uf.size(v) - 1;
// 	}
// 	for (int i = 0; i < Q; ++i) {
// 		cout << B[i] << "\n";
// 	}
// 	return 0;
// }
