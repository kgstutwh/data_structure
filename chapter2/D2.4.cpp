#include<iostream>
using namespace std;
#include<vector>

int maxSumRec(const vector<int> &vec,int left,int right);
int max3(int num1,int num2,int num3);
int maxSubSum3(const vector<int> &vec);

int main()
{
	int a[8]={4,-3,5,-2,-1,2,6,-2};
	vector<int> vec(a,a+8);
	int max=maxSubSum3(vec);
	cout << max << endl;
	return 0;
}

int max3(int num1,int num2,int num3)
{
	int max=num1;
	if(max<num2)
		max=num2;
	if(max<num3)
		max=num3;
	return max;
}

int maxSumRec(const vector<int> &vec,int left,int right)
{
	if(left==right)
	{
		if(vec[left]>0)
			return vec[left];
		else
			return 0;
	}
	int center=(left+right)/2;
	int maxLeftSum=maxSumRec(vec,left,center);
	int maxRightSum=maxSumRec(vec,center+1,right);
	int maxLeftBorderSum=0,leftBorderSum=0;
	for(int i=center;i>=left;i--)
	{
		leftBorderSum+=vec[i];
		if(maxLeftBorderSum<leftBorderSum)
			maxLeftBorderSum=leftBorderSum;
	}
	int maxRightBorderSum=0,rightBorderSum=0;
	for(int i=center+1;i<right;i++)
	{
		rightBorderSum+=vec[i];
		if(maxRightBorderSum<rightBorderSum)
			maxRightBorderSum=rightBorderSum;
	}
	return max3(maxLeftSum,maxRightSum,maxLeftBorderSum+maxRightBorderSum);
}
int maxSubSum3(const vector<int> &vec)
{
	return maxSumRec(vec,0,vec.size()-1);
}

