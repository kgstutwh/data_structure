#include<iostream>
using namespace std;
#include<vector>

int maxSubSum4(const vector<int> &vec);
int main()
{
	int a[8]={4,-3,5,-2,-1,2,6,-2};
	vector<int> vec(a,a+8);
	cout << maxSubSum4(vec) << endl;
	return 0;
}
int maxSubSum4(const vector<int> &vec)
{
	int maxSum=0;
	int thisSum=0;
	for(int i=0;i<vec.size();i++)
	{
		thisSum+=vec[i];
		if(maxSum<thisSum)
			maxSum=thisSum;
		else if(thisSum<0)
			thisSum=0;
	}
	return maxSum;
}