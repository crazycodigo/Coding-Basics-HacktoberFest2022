class Solution
{
public:
	int minMoves(vector<int> &nums)
	{

		int mi = *min_element(nums.begin(), nums.end());
		int ans = 0;
		for (auto i : nums)
		{
			ans += (i - mi);
		}
		return ans;
	}
};