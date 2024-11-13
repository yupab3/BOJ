#include <iostream>
#include <vector>

using namespace std;

int	main()
{
	ios::sync_with_stdio(0);
	std::cin.tie(0);
	vector<int>	data;
	std::string	buf;
	cin >> buf;
	int i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == 'M')
			data.push_back(1000);
		else if (buf[i] == 'D')
			data.push_back(500);
		else if (buf[i] == 'C')
			data.push_back(100);
		else if (buf[i] == 'L')
			data.push_back(50);
		else if (buf[i] == 'X')
			data.push_back(10);
		else if (buf[i] == 'V')
			data.push_back(5);
		else if (buf[i] == 'I')
			data.push_back(1);
		i++;
	}
	data.push_back(0);
	int num1 = 0;
	i = 0;
	while (data[i])
	{
		if (data[i] >= data[i + 1])
			num1 += data[i];
		else
			num1 -= data[i];
		i++;
	}
	num1 += data[i];
	data.clear();
	cin >> buf;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == 'M')
			data.push_back(1000);
		else if (buf[i] == 'D')
			data.push_back(500);
		else if (buf[i] == 'C')
			data.push_back(100);
		else if (buf[i] == 'L')
			data.push_back(50);
		else if (buf[i] == 'X')
			data.push_back(10);
		else if (buf[i] == 'V')
			data.push_back(5);
		else if (buf[i] == 'I')
			data.push_back(1);
		i++;
	}
	data.push_back(0);
	int num2 = 0;
	i = 0;
	while (data[i])
	{
		if (data[i] >= data[i + 1])
			num2 += data[i];
		else
			num2 -= data[i];
		i++;
	}
	num2 += data[i];
	int ans = num1 + num2;
	std::cout << ans << '\n';
	buf.clear();
	while (ans > 0)
	{
		if (ans >= 1000)
		{
			buf.append("M");
			ans -= 1000;
		}
		else if (ans >= 900)
		{
			buf.append("CM");
			ans -= 900;
		}
		else if (ans >= 500)
		{
			buf.append("D");
			ans -= 500;
		}
		else if (ans >= 400)
		{
			buf.append("CD");
			ans -= 400;
		}
		else if (ans >= 100)
		{
			buf.append("C");
			ans -= 100;
		}
		else if (ans >= 90)
		{
			buf.append("XC");
			ans -= 90;
		}
		else if (ans >= 50)
		{
			buf.append("L");
			ans -= 50;
		}
		else if (ans >= 40)
		{
			buf.append("XL");
			ans -= 40;
		}
		else if (ans >= 10)
		{
			buf.append("X");
			ans -= 10;
		}
		else if (ans >= 9)
		{
			buf.append("IX");
			ans -= 9;
		}
		else if (ans >= 5)
		{
			buf.append("V");
			ans -= 5;
		}
		else if (ans >= 4)
		{
			buf.append("IV");
			ans -= 4;
		}
		else if (ans >= 1)
		{
			buf.append("I");
			ans -= 1;
		}
	}
	std::cout << buf << '\n';
}
