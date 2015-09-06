/**
Follow up for ¡±Remove Duplicates¡±: What if duplicates are allowed at most twice?
For example, Given sorted array A = [1,1,1,2,2,3],
Your function should return length = 5, and A is now [1,1,2,2,3]
*/
#include <iostream>
using namespace std;

int Solution(int A[], int n)
{
	// print original array elements
	for(int i=0; i<n; ++i)
	{
		std::cout << A[i] << " ";	
	}
	std::cout << std::endl;

	if(n <= 2) return 2;

	int length = 2;
	for(int j=2; j<n; ++j)
	{
		if(A[length-2] != A[j])
		{
			A[length++] = A[j];
		}		
	}
	
	// print the handled array
	std::cout << "After Handled" << std::endl;
	for(int j=0; j<length; ++j)
	{
		std::cout << A[j] << " ";
	}
	
	return length;	
}

int main()
{
	int A[10] = {1,2,2,2,2,4,4,4,7,8};
	
	int length = Solution(A, 10);
	
	std::cout << std::endl << "The length is " << length << std::endl;
	
	return 0;
}
