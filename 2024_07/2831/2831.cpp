#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	map<int, int> g_mail;
	map<int, int> g_femail;
	int N, tmp;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		g_mail[tmp]++;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		g_femail[tmp]++;
	}
	int ans = 0;
	for (map<int, int>::iterator it = g_mail.begin(); it != g_mail.end(); ++it)
	{
		if (it->first > 0)
		{
			for (map<int, int>::reverse_iterator fit = g_femail.rbegin(); fit != g_femail.rend(); ++fit)
			{
				if (fit->first < 0 && abs(fit->first) > it->first)
				{
					while (fit->second > 0)
					{
						fit->second--;
						it->second--;
						ans++;
						if (it->second == 0)
							break ;
					}
					if (it->second == 0)
						break ;
				}
			}
		}
		else if (it->first < 0)
		{
			for (map<int, int>::reverse_iterator fit = g_femail.rbegin(); fit != g_femail.rend(); ++fit)
			{
				if (fit->first > 0 && abs(it->first) > fit->first)
				{
					while (fit->second > 0)
					{
						fit->second--;
						it->second--;
						ans++;
						if (it->second == 0)
							break ;
					}
					if (it->second == 0)
						break ;
				}
			}
		}
	}
	std::cout << ans << '\n';
}