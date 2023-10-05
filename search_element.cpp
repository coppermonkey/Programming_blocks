#include <bits/stdc++.h>

using namespace std;

/*
 * This create a new vector list and prints out the value on the stdout console
 */
void create_list(int rangestart, int rangeend, vector<int> &sym_vectors)
{
	sym_vectors.reserve(rangeend-rangestart);
	for(int i=0; i<rangeend-rangestart; i++) {
		sym_vectors[i] = rangestart+i;
		cout<<i<<" "<<sym_vectors[i];
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
	vector<int> sym_vectors;
	create_list(6,10, sym_vectors);

	for(vector<int>::iterator it = sym_vectors.begin(); it!= sym_vectors.end(); it++)
		cout<<*it<<endl;

	cout << is_present(-1, Alist);
}
