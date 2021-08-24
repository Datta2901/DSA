# AVLTrees

* This also type of binary search but it is height balanced Binary 
* Balance factor is height(left) - height(right)
* if Balance factor is 0,-1,1 then it is said to be AVL tree(balanced)
* else it is imbalance.
* we will make imbalance trees to balance trees by making rotations

## Types of rotations

* LL rotation;
* LR Rotation(Double Rotation)
* RR Rotation
* RL Rotation(Double Rotation)
  
Due to insertion of some node the tree may become imbalance .At what place the node is 
inserted we have to do that rotation.


If height is given then 
max number of nodes possible in avl tree is $$ 2^{n + 1} - 1 $$

If nodes are given then 
min height  possible in avl tree is $$ log_2(n + 1) $$
maximum height in avl tree is $$ 1.44 * log_2(n + 2) $$
