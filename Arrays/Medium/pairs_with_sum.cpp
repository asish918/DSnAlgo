#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
	int arr1[] = {1, 2, 4, 5, 7};
	int arr2[] = {5, 6, 3, 4, 8};

	int X = 9;
	int n = sizeof(arr1) / sizeof(int);
	int m = sizeof(arr2) / sizeof(int);

	vector<pair<int, int>> ans;

	// Noob Approach O(n*n)
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr1[i] + arr2[j] == X)
			{
				ans.push_back(make_pair(arr1[i], arr2[j]));
			}
		}
	}

	// Pro Approach O(n)
	unordered_map<int, int> ans_map;
	for(int i = 0; i<n; i++){
		if(ans_map.find(X - arr1[i]) != ans_map.end()) {
			ans.push_back(make_pair(i, ans_map[i]));
		}
		ans_map[arr1[i]] = i;
	}

	for (auto it : ans)
		cout << it.first << " " << it.second << endl;
	return 0;
}
