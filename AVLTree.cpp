/*
 * AVLTree.cpp
 *
 *  Created on: Jul 17, 2010
 *      Author: lakkhana
 */

#include "AVLTree.h"

AVLTree::AVLTree() {

	root = NULL;
}

int AVLTree::getHeight(TreeNode* node) {

	if(node==NULL)
		return 0;

	int left,right;
	left = getHeight(node->leftChild);
	right = getHeight(node->rightChild);

	return (left<right) ? right+1 : left+1;

}

void AVLTree::search(int num) {

	tmp = root;
	prv = NULL;

	while(tmp!=NULL) {

		if(tmp->letter==num)
			return;

		else if(tmp->letter<num) {

			prv = tmp;
			tmp = tmp->rightChild;
			child = 'r';
		}


		else {

			prv = tmp;
			tmp = tmp->leftChild;
			child = 'l';
		}

	}



}
TreeNode* AVLTree::sch(int num) {

	tmp = root;
	prv = NULL;

	while(tmp!=NULL) {

		if(tmp->letter==num)
			return tmp;

		else if(tmp->letter<num) {

			prv = tmp;
			tmp = tmp->rightChild;
			child = 'r';
		}


		else {

			prv = tmp;
			tmp = tmp->leftChild;
			child = 'l';
		}

	}
	return tmp;


}

void AVLTree::insert(int let) {

	search(let);
	if(tmp==NULL) {

		tmp = new TreeNode();
		tmp->tree = NULL;
		tmp->height = 1;
		tmp->position = -1;
		tmp->leftChild = NULL;
		tmp->rightChild = NULL;
		tmp->parent = prv;
		tmp->letter = let;

		if(prv==NULL)
			root = tmp;

		else {

			if(child=='l')
				prv->leftChild = tmp;

			else
				prv->rightChild = tmp;


			while(prv!=NULL) {
				int rHeight = getHeight(prv->rightChild);
				int lHeight = getHeight(prv->leftChild);

				int max = (rHeight>lHeight) ? rHeight+1 : lHeight+1;
				if(prv->height==max)
					break;

				else {

					prv->height=max;
					prv = prv->parent;
				}
			}
		}


		prv = tmp->parent;
		balance(prv);

	}
}

void AVLTree::balance(TreeNode* point) {


	TreeNode* n1;

	while(point!=NULL) {

		int rHeight = getHeight(point->rightChild);
		int lHeight = getHeight(point->leftChild);
		cout<<"point : "<<(char)point->letter<<endl;
		if(rHeight-lHeight>1) {
			n1 = point->rightChild;
			rHeight = getHeight(n1->rightChild);
			lHeight = getHeight(n1->leftChild);
			cout<<"n1 rr: "<<(char)n1->letter<<endl;
			if(rHeight<lHeight)
				rR(n1->leftChild,n1);
			n1 = point->rightChild;
			lR(n1,point);
			cout<<"pp: "<<(char)point->parent->letter<<endl;
			cout<<"p: "<<(char)point->letter<<endl;
			cout<<"ps: "<<(char)point->parent->rightChild->letter<<endl;
			break;
		}

		else if(rHeight-lHeight<-1) {

			n1 = point->leftChild;
			rHeight = getHeight(n1->rightChild);
			lHeight = getHeight(n1->leftChild);
			cout<<"n1 ll: "<<(char)n1->letter<<endl;
			if(lHeight<rHeight)
				lR(n1->rightChild,n1);
			n1 = point->leftChild;
			rR(n1,point);
			break;
		}

		else
			point = point->parent;
	}
}

void AVLTree::rR(TreeNode* node,TreeNode* par) {

	if(par==root)
		root = node;
	node->parent = par->parent;
	par->leftChild = node->rightChild;
	node->rightChild = par;
	par->parent = node;
	cout<<"node rr: "<<(char)node->letter<<endl;

}

void AVLTree::lR(TreeNode* node,TreeNode* par) {

	if(par==root)
		root = node;
	node->parent = par->parent;
	par->rightChild = node->leftChild;
	node->leftChild = par;
	par->parent = node;
	cout<<"node ll: "<<(char)node->letter<<endl;
}


