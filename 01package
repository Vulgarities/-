#include<cstdio>
#include<iostream>
#include<fstream>
using namespace std;
int calculateSet(int n, int m)
{
	if ((m > n) || (m == 0))
	{
		return 0;
	}
	else if ((m == 1) || (n == 1) || (m == n))
	{
		return 1;
	}
	else
	{
		return (calculateSet(n - 1, m - 1) + m*calculateSet(n - 1, m));
	}
}

int main()
{
	for(double i=73;i<150;i++){
		cout<<i<<'-'<<i-16<<"-"<<(i-16)/i<<endl;
	}
}
