/**
 * @param {number[]} nums
 * @return {number[][]}
 */
function permute(nums) {
    
    // 요소가 한 개 이하면 그대로
    if (nums.length <= 1) {
        return [nums]
    }
    
    return nums.map((head, i) => {
        // i번째 요소(head)를 제외한 나머지 요소들로 구성된 배열
        const tail = [...nums.slice(0, i), ...nums.slice(i + 1)]
        
        // tail로 다시 순열을 구한 뒤, head를 다시 각 요소의 맨 앞에 붙임
        return permute(tail).map(p => [head, ...p])
    }).reduce((a, b) => [...a, ...b])
}
