#include <iostream>
#include <vector>
#include<map>
using namespace std;

//optimised solution of container with most water/max water

int maxArea(vector<int>& height) {
	
	int start = 0;
	int len = height.size();
	int end = len-1;
	int maximumArea = LONG_MIN;
	while(start<end)
	{
		
		maximumArea = max(maximumArea,min(height[start],height[end]) * (end-start));
		
		if(height[start]>height[end])
		{
			end--;
		}
		else{
			start++;
			
		}
	}        
    
    return maximumArea;  
    
}

int main()
{
	vector<int> v={1,8,6,2,5,4,8,3,7};
	cout<<maxArea(v)<<endl;
	
	
	
}
