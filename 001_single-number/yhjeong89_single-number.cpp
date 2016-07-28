class Solution {
public:
	/**
	* 추가 메모리 공간을 사용하지 않고 O(n)으로 푸는 방법.
	* 서로 같은 수에 대한 XOR를 수행하면 0이 된다는 특징을 이용한다.
	* ex. 10110011 ^ 10110011 = 00000000
	* 모든 수에 xor를 수행한다.
	*/
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i=0 ; i<nums.size() ; i++)
        {
            res ^= nums[i];
        }
        return res;
    }
};