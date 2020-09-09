#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

/*
字符串转数字
1、获取字符串中的第一个数字
2、连续'+'与'-'后不是数字则返回
*/
/*
			' '		+/-		number		other
start		start	signed	in_number	start
signed		end		signed	in_number	end
in_number	end		end		in_number	end
end			end		end		in_number	end
*/

class Automaton {
	string state = "start";
	unordered_map<string, vector<string>> table = {
		{"start",{"start","signed","in_number","start"}},
		{"signed",{"end","signed","in_number","end"}},
		{"in_number",{"end","end","in_number","end"}},
		{"end",{"end","end","end","end"}}
	};

	int get_col(char c) {
		if (isspace(c)) return 0;
		if (c == '+' || c == '-') return 1;
		if (isdigit(c)) return 2;
		return 3;
	}
public:
	int sign = 1;
	long long ans = 0;

	void get(char c) {
		state = table[state][get_col(c)];
		if (state == "in_number") {
			ans = ans * 10 + c - '0';
			ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
		}
		else if (state == "signed") {
			sign = c == '+' ? 1 : -1;
		}
	}
};

int main()
{
	string str;
	cin >> str;

	Automaton s;
	for (char c : str) {
		s.get(c);
	}
	cout << s.ans*s.sign << endl;

	system("pause");
	return 0;
}