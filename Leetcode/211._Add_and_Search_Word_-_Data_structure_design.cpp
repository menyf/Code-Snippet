#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <iosfwd>
#include <deque>
#include <algorithm>
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class NestedInteger {
  public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
//// Answers below
typedef long long ll;
class WordDictionary {
public:

	struct Node{
		bool isWord;
		Node *child[26];
		Node():isWord(false){
			for(int i = 0; i < 26; i++) child[i] = NULL;
		}
		
	};

	Node *root;

	/** Initialize your data structure here. */
	WordDictionary() {
		root = new Node();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		Node *curr = root;
		for(int i = 0; i < word.size(); i++){
			int id = word[i] - 'a';
			if(curr->child[id] == NULL) 
				curr->child[id] = new Node();
			curr = curr->child[id];
		}
		curr->isWord = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return search_helper(word, 0, root);
	}

	bool search_helper(string &word, int pos, Node *curr){
		if(pos == word.size()) return curr->isWord;
		if (word[pos] == '.') {
			for(auto ptr : curr->child) {
				if(ptr && search_helper(word, pos + 1, ptr))
					return true;
			}
			return false;
		}
		else {
			Node *ptr = curr->child[word[pos] - 'a'];
			return ptr && search_helper(word, pos + 1, ptr);
		}
			
	}

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}
	
