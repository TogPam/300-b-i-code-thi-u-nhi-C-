#include <iostream>
#include <vector>
int binarySearch(std::vector<int> a, int target)
{
	int left = 0, right = a.size() - 1;
	int mid = 0;
	while(left <= right)
	{
		mid = (right + left) / 2;
		if(a[mid] == target)
			return mid;
		else if(target < a[mid])
			right = mid - 1;
		else left = mid + 1;
	}
	return -1;
}

int main()
{
	std::vector<int> a = {-1,0,3,5,9,12};
	std::cout<<binarySearch(a,9);
	
    return 0;
}
