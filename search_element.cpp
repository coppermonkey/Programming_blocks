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
int main()
{
	vector<int> Alist;
	create_list(5,9, Alist);

	for(vector<int>::iterator it = Alist.begin(); it!= Alist.end(); it++)
		cout<<*it<<endl;
}
