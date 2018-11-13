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
class Trie {
public:
	
	struct Node{
		bool isWord;
		Node *child[26];
		Node():isWord(false){
			for(int i = 0; i < 26; i++) {
				child[i] = NULL;
			}
		}
	};
	
	Node *head;
	
	/** Initialize your data structure here. */
	Trie() {
		head = new Node();
	}
	
	/** Inserts a word into the trie. */
	void insert(string word) {
		Node *curr = head;
		for(int i = 0; i < word.size(); i++){
			int id = word[i] - 'a';
			if(curr->child[id] == NULL){
				curr->child[id] = new Node();
			}
			curr = curr->child[id];
		}
		curr->isWord = true;
	}
	
	/** Returns if the word is in the trie. */
	bool search(string word) {
		Node *curr = head;
		for(int i = 0; i < word.size(); i++){
			int id = word[i] - 'a';
			if(curr->child[id] == NULL) return false;
			curr = curr->child[id];
		}
		return curr->isWord;
	}
	
	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Node *curr = head;
		for(int i = 0; i < prefix.size(); i++){
			int id = prefix[i] - 'a';
			if(curr->child[id] == NULL) return false;
			curr = curr->child[id];
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}
	
