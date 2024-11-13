#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

#define ii	pair<int, int>

set<string>	ans;
string		str;
set<int>	pos;
stack<int>	stk;
vector<ii>	parens;

void	dfs(vector<ii>::iterator idx)
{
	for (auto it = idx; it != parens.end(); ++it)
	{
		auto [_open, _close] = *it;
		str[_open] = 'a';
		str[_close] = 'a';
		dfs(++it);
		string tmp_str = str;
		while (tmp_str.find('a') != string::npos)
			tmp_str.erase(tmp_str.find('a'), 1);
		ans.insert(tmp_str);
		str[_open] = '(';
		str[_close] = ')';
		--it;
	}
}

int	main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
			stk.push(i);
		else if (str[i] == ')')
		{
			parens.push_back({stk.top(), i});
			stk.pop();
		}
	}
	dfs(parens.begin());
	for (auto str : ans)
		cout << str << '\n';
	return (0);
}