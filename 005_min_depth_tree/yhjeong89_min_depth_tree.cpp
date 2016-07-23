#include <iostream>
#include <queue>

using namespace std;

{
	int val;

class Solution
{
public:
	/**
	* BFS를 이용한 풀이. 최소 깊이를 구하는 문제이기 때문에 DFS 보단 BFS를 사용하는 것이 효율적이다.
	* 최초로 두 자식이 없는 노드의 깊이를 리턴한다.
	*/
	int minDepth(TreeNode* root)
	{
		// Step 0. corner case.
		if (root == NULL) return 0;

		queue<TreeNode*> q;

		// Step 1. 루트 노트를 큐에 삽입. val에 깊이값을 저장하는 방식을 사용한다.
		q.push(root);
		root->val = 1;

		// Step 2. 모든 노드들에 대해 순회. 아래의 while 문에서 반드시 어떠한 값을 리턴한다.
		while (q.empty() == false)
		{
			TreeNode* r = q.front(); q.pop();

			// Step 3. min depth를 가지는 노드 확인. 결과 리턴.
			if (r->left == NULL && r->right == NULL) return r->val;

			// Step 4. 자식 노드를 가질 경우 큐에 삽입.
			if (r->left != NULL)
			{
				r->left->val = r->val + 1;
				q.push(r->left);
			}

			if (r->right != NULL)
			{
				r->right->val = r->val + 1;
				q.push(r->right);
			}
		}

		// 이 값으로 리턴이 되는 일은 없다.
		return 0;
	}
};
