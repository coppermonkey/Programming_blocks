#include <bits/stdc++.h>

using namespace std;

void create_list(int rangestart, int rangeend, vector<int> &Alist)
{
	Alist.reserve(rangeend-rangestart);
	for(int i=0; i<rangeend-rangestart; i++) {
		Alist[i] = rangestart+i;
		cout<<i<<" "<<Alist[i];
	}
}

void is_present (int key, vector<int> &Alist)
{
	for (int i=0; i<Alist.size(); i++) {
		if (Alist.at(i) == key)
			return 1;
	}
	return 0;
}

int main()
{
	vector<int> Alist;
	create_list(5,9, Alist);

	for(vector<int>::iterator it = Alist.begin(); it!= Alist.end(); it++)
		cout<<*it<<endl;

	cout << is_present(-1, Alist);
}
