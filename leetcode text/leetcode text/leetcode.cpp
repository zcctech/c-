#define  _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<queue>
#include<iostream>

using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> ret;
        if (root == nullptr)
        {
            return ans;
        }
        ret.push(root);
        int i = 0;
        while (!ret.empty())
        {
            int num = ret.size();
            vector<int> level;
            while (num != 0)
            {
                int j = 0;
                level.push_back((ret.front())->val);

                if (ret.front()->left != nullptr)
                    ret.push(ret.front()->left);
                if (ret.front()->right != nullptr)
                    ret.push(ret.front()->right);
                ret.pop();
                num--;
                j++;
            }
            ans.push_back(level);
        }
        return ans;
    }
};
int main()
{
	return 0;
}