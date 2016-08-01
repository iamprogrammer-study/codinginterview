class Solution
{
public:
	// 추가 저장 공간을 사용하지 않고 SWAP.
	void swap(int &a, int &b)
	{
		if (a != b)
		{
			a ^= b;
			b ^= a;
			a ^= b;
		}
	}

	// 다음 개념을 이용해서 문제를 해결했습니다.
	// slen : 문자열의 길이.
	// 길이가 3이상인 수열은 다음둘 중 하나의 조건을 만족한다.
	// 1. 가장 마지막 두 숫자를 서로 바꾸면 next permutation 성립 (ex. 1134 -> 1143)
	// 		이는 nums[slen - 2] < nums[slen - 1]일 경우에 SWAP을 수행하면 된다.
	// 2. 그 외의 경우는 아래의 과정을 거친다.
	// 2-1. 가장 먼저 [slen - 2 ~ 1]의 범위에서 nums[i-1] < nums[i]를 만족하는 i를 찾는다. 
	//             *
	//		(ex. 411756 에서는 최초로 nums[2] < nums[3]에서 조건 만족. i = 3)
	// 2-1-1. 만일 위를 만족하는 i가 없는 경우는 7654321과 같이 순서가 완벽하게 뒤집어진 경우. 
	//			nums를 오름차순으로 정렬하고 함수 수행을 마친다.
	// 2-2. i부터 slen - 1까지의 숫자들을 탐색한다. 탐색 시 nums[i - 1]보다 크면되 탐색 범위 내에서는 가장 작은 숫자를 찾는다.
	//             * *
	//      (ex. 411756)
	// 2-3. nums[i - 1]과 위에서 찾은 숫자를 서로 SWAP한다.
	//             * *
	//      (ex. 415716)
	// 2-4 i부터 slen - 1까지의 숫자들을 오름 차순으로 정렬한다.
	//      (ex. 415167)
	void nextPermutation(vector<int>& nums)
	{
		int slen = nums.size();

		if (slen == 0 || slen == 1) return;
		if (slen == 2)
		{
			swap(nums[0], nums[1]);
			return;
		}

		if (nums[slen - 2] < nums[slen - 1])
		{
			swap(nums[slen - 2], nums[slen - 1]);
		}
		else
		{
			int i; bool found = false;
			for (i = slen - 2; i >= 1; i--)
			{
				if (nums[i - 1] < nums[i])
				{
					found = true;
					break;
				}
			}

			if (!found)
			{
				sort(nums.begin(), nums.end());
				return;
			}

			int changedIdx = i - 1;
			int subIdxStart = i;
			int subIdxEnd = slen - 1;

			int min = ~(1 << 31);
			int minIdx;
			for (int j = subIdxStart; j <= subIdxEnd; j++)
			{
				if (nums[j] < min)
				{
					min = nums[j];
					minIdx = j;
				}
			}
			swap(nums[changedIdx], nums[minIdx]);

			sort(nums.begin() + subIdxStart, nums.end());
		}

	}
};