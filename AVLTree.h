/*
 * AVLTree.h
 *
 *  Created on: Jul 17, 2010
 *      Author: lakkhana
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_
#include <iostream>


using namespace std;

struct TreeNode;

class AVLTree {
public:
	AVLTree();
	void search(int);
	TreeNode* sch(int);
	void insert(int);
	void balance(TreeNode*);
	TreeNode* root;
	TreeNode* tmp;
	TreeNode* prv;

private:
	char child;
	int getHeight(TreeNode*);
	void rR(TreeNode*,TreeNode*);
	void lR(TreeNode*,TreeNode*);


};

struct TreeNode {
	int height;
	int letter;
	int position;
	TreeNode* parent;
	TreeNode* leftChild;
	TreeNode* rightChild;
	AVLTree* tree;

};

#endif /* AVLTREE_H_ */
