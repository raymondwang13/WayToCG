/**
Given a sorted array, remove the duplicates in place such that each element appear only once
and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example, Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].
*/

#include <iostream>
using namespace std;

int removeDuplicate(int A[], int length)
{
	for(int i=0; i<length; ++i)
	{
		std::cout << A[i] << " ";	
	}
	std::cout << std::endl;
	
	int index = 0;
	for(int i=1; i<length; ++i)
	{
		if(A[index] != A[i])
		{
			A[++index] = A[i];	
		}
	}
	
	std::cout << "After Remove:" << std::endl;
	for(int i=0; i<index+1; ++i)
	{
		std::cout << A[i] << " ";	
	}
	
	return (index + 1);
}

int main()
{
	int A[10] = {1,1,1,3,3,3,4,4,5,5};
	
	int length = removeDuplicate(A, 10);
	
	std::cout << std::endl << "The length is " << length << std::endl; 
		
	return 0;
}
