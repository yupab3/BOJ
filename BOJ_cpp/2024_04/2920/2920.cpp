#include <iostream>
using namespace std;

int	main(void){
	int	tmp, N;
	bool	flag;
	string	str;

	for (int i = 1; i <= 8; i++){
		cin >> N;
		if (i == 1){
			tmp = N;
			if (N == 1)	flag = 1;
			else if (N == 8) flag = 0;
			else tmp = 0;
		}
		if (i != 1){
			if (tmp != 0){
				if ((flag == 1 && N < tmp) || (flag == 0 && N > tmp)) tmp = 0;
				else tmp = N;
			}
		}
	}
	if (tmp != 0){
		if (flag == 1) cout << "ascending";
		else cout << "descending";
	}
	else cout << "mixed";
}