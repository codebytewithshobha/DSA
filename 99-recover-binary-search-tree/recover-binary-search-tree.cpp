class Solution {
public:
    void recoverTree(TreeNode* root) {

        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        TreeNode *prev = nullptr;

        TreeNode *cur = root;

        while(cur) {

            if(cur->left == nullptr) {

                // Visit current node
                if(prev && prev->val > cur->val) {

                    if(first == nullptr)
                        first = prev;

                    second = cur;
                }

                prev = cur;
                cur = cur->right;
            }

            else {

                // Find inorder predecessor
                TreeNode* pred = cur->left;

                while(pred->right && pred->right != cur)
                    pred = pred->right;


                // Create thread
                if(pred->right == nullptr) {

                    pred->right = cur;
                    cur = cur->left;
                }

                // Remove thread
                else {

                    pred->right = nullptr;


                    // Visit current node
                    if(prev && prev->val > cur->val) {

                        if(first == nullptr)
                            first = prev;

                        second = cur;
                    }

                    prev = cur;
                    cur = cur->right;
                }
            }
        }


        // Swap the two wrong nodes
        if(first && second)
            swap(first->val, second->val);
    }
};