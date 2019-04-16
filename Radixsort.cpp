#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

int FindMaxNum(vector<int> arr)111
{
	int max = 0;
	int count = arr.size();
	for (int i = 0; i < count; i++)
	{
		if (arr[i] >= max)
		{
			max = arr[i];
		}
	}

	return max;
}

int FindLoopTimes(int max)
{
	int time = 1;
	int temp = max / 10;
	while (temp != 0)
	{
		time++;
		temp = temp / 10;
	}
	return time;
}

void rs(vector<int> arr)
{
	int temp;
	int flag = 1;
	vector<int> bucket[10];
	int max = FindMaxNum(arr);
	int time = FindLoopTimes(max);
	for (int i = 0; i < time; i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			temp = arr[j]/flag % 10;
			bucket[temp].push_back(arr[j]);
		}
		arr.clear();
		
		for (int m = 0; m < 10; m++)
		{
			for (int n = 0; n < bucket[m].size(); n++)
			{
				arr.push_back(bucket[m][n]);
			}
			if (bucket[m].size() != 0)
			{
				bucket[m].clear();
			}
		}
		flag = flag * 10;

	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] <<endl;
	}
	
}



int main()
{
	//int array[] = { 1,33,653,326,768,234,111 };
	vector<int> array;
	int n;
	cout << "Enter how many numbers for radix sort:";
	cin >> n ;
	srand((int)time(NULL));
	for (int i = 0; i < n; i++)
	{
		array.push_back(rand());
	}
	
	int max = FindMaxNum(array);
	int time = FindLoopTimes(max);
	rs(array);
	
	cin.get();
	cin.get();

}
