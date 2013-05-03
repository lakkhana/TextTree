/*
 * TextTree.cpp
 *
 *  Created on: Jul 17, 2010
 *      Author: lakkhana
 */
#include <iostream>
#include <string>
#include <fstream>
#include "AVLTree.h"


void insert(string,int,AVLTree*);
int searchWord(string,AVLTree*);

int main() {

	ifstream text,qry;
	text.open("corpus.txt",ios::in);

	int count = 0;
	AVLTree* tree = new AVLTree();
	string word;
	while(text!=NULL) {

		text>>word;
		cout << word<<endl;
		insert(word,count,tree);
		count += word.length()+1;

	}
	text.close();
	/*insert("word",75,tree);
	insert("ro",5,tree);
	insert("yd",58,tree);
	insert("wo",54,tree);
	insert("oh",25,tree);
	insert("jklword",5,tree);
	insert("wor",7,tree);
	insert("pfh",23,tree);
	insert("ghrd",59,tree);*/
	text.open("corpus.txt",ios::in);
	while(text!=NULL) {

			text>>word;
			cout << word<<endl;
			int a = searchWord(word,tree);
			cout << a << endl;
		}
	text.close();
	/*qry.open("query.txt",ios::in);
	while(qry!=NULL) {

		qry.getline(word,16);
		cout << word<<endl;

		cout << a << endl;

	}
	qry.close();*/


	return 0;
}

int searchWord(string word,AVLTree* tr) {
	AVLTree* next;
	TreeNode* nd;

	for(int i=0;i<word.length();i++) {

		nd = tr->sch(word[i]);

		if(nd==NULL)
			return -1;

		next = nd->tree;
		tr = next;

	}

	return nd->position;

}

void insert(string word,int inx,AVLTree* tr) {

	if(word.length()==0)
		return;

	tr->search(word[0]);
	AVLTree* nextT;


	if(tr->tmp==NULL){

		tr->insert(word[0]);
		if(word.length()==1)
			tr->tmp->position = inx;
	}



	if(tr->tmp->tree==NULL){
		AVLTree* curT;
		curT = tr;
		for(int i=1;i<word.length();i++) {

			nextT = new AVLTree();
			nextT->insert(word[i]);

			if(i==word.length()-1)
				nextT->tmp->position = inx;

			curT->tmp->tree = nextT;
			curT = nextT;

		}

	}

	else {

		if(word.length()==1 && tr->tmp->position==-1)
			tr->tmp->position = inx;

		nextT = tr->tmp->tree;
		string sub(word,1);
		insert(sub,inx,nextT);

	}
}
