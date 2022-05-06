#include <stdio.h>
#include <vector>
#include <algorithm>
#define pp pair<double,double>

using namespace std;
vector < pp > v;

bool cmp(pp a, pp b){
	if(a.first < b.first)
		return true;
	else if(a.first == b.first)
		return (a.second < b.second);
	else
		return false;
}
double len(pp a, pp b){
	return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

double isSQ(pp a, pp b, pp c, pp d){
	/*
	사각형의 모양
	1. c d
	   a b 
	*/
	if(len(a,d) == len(b,c))
		if(len(a,b) == len(b,d) && len(a,b) == len(a,c) && len(a,b) == len(c,d))
			return len(a,b);
	else
		return 0;
}


int main()
{   //프로그램의 시작부 
	int n; scanf("%d",&n);
	double area = 0;
	while(n--){
		double x,y; scanf("%lf %lf",&x,&y);
		v.push_back({x,y});
	}
	sort(v.begin(),v.end(),cmp);
	
	for(int i = 0 ; i < v.size() - 3 ; i++)
		for(int j = i + 1 ; j < v.size() - 2 ; j++)
			for(int k = j + 1 ; k < v.size() - 1; k++)
				for(int l = k + 1 ; l < v.size() ; l++){
					double tmp = isSQ(v[i],v[j],v[k],v[l]);
					area = (tmp > area) ? tmp : area;
				}
	printf("%.2lf",area);
    return 0;
}