/*
 * This program uses flood fill algorithm to reach every space on 2D matrix
 */
#include<bits/stdc++.h>

#define fori(i,n) for(int i=0;i<n;i++)
#define fors(i,init,n,step) for(int i=init;i<n;i+=step)

using namespace std;

typedef int nd;

#ifndef floodfill_rec_func
#define floodfill_rec_func \
	if(i>=0 && i<n && j>=0 && j<n && g[i][j]!=border && g[i][j]!=fv)floodfill(g,i,j,fv,border,xoffset,yoffset,alldirection);
#endif
#ifndef fori
#define fori(i,n) for(int i=0;i<n;i++)
#endif
template <typename t>
void floodfill(vector<vector<t> >&g, int ix, int starty, t fv, t border, int xoffset, int yoffset, bool alldirection=false){
	int n = g.size();
	g[ix][starty]=fv;
	fori(l,2){
		fori(k,2){
			int i=ix+pow(-1,l)*xoffset, j=starty+ pow(-1,k)*yoffset;
	if(ix==3 && starty==2)cout<<i<<":"<<j<<endl;
			floodfill_rec_func
			if(xoffset!=yoffset){
				int i=ix+pow(-1,l)*yoffset, j=starty+ pow(-1,k)*xoffset;
	if(ix==3 && starty==2)cout<<i<<":"<<j<<endl;
				floodfill_rec_func
			}
			if(alldirection==true){
				i=ix+pow(-1,k)*xoffset;j=starty;
	if(ix==3 && starty==2)cout<<i<<"::"<<j<<endl;
				floodfill_rec_func
				if(xoffset!=yoffset){
					j=starty+pow(-1,k)*xoffset;i=ix;
	if(ix==3 && starty==2)cout<<i<<"::"<<j<<endl;
					floodfill_rec_func
				}
			}
		}
	}
return;
}
#undef floodfill_rec_func

int main(){
	nd n;
	cin>>n;
	vector<vector<int> >g(n,vector<int>(n,-1));
	fori(i,n)fori(j,n)cin>>g[i][j];
	floodfill(g,0,0,2,-1,1,1,true);
	fori(i,n){
		fori(j,n)cout<<g[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
