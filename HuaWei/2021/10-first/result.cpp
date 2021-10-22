#include <iostream>
#include <string>
using namespace std;

string getString(string s1)
{
	string res = "";
	int n = s1.length();
	if (s1.find_first_of('#') == string::npos)
		return s1;
	else
	{
		int pos = s1.find_first_of('#');
		if ((pos == 0 && n < 2) || (pos == 1 && n < 3))
			return res;
		else if ((pos == 1 && n > 2) || (pos == 0 && n > 1))
			res = s1.substr(pos + 1);
		else if (pos > 1 && pos + 1 >= n)
			res = s1.substr(0, pos - 1);
		else
			res = s1.substr(0, pos - 1) + s1.substr(pos + 1);
		return getString(res);
	}
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		string ss1 = getString(s1);
		string ss2 = getString(s2);
		cout << ss1 << endl;
		cout << ss2 << endl;
		cout << boolalpha << (ss1 == ss2) << endl;
	}
	system("pause");
	return 0;
}