#include <unordered_map>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <list>
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

class Node_t{
public:
	int key;
	int val;
	int id;
};

bool cmp(Node_t a, Node_t b){
	return a.id < b.id;
}

class LRUCache {
private:
	int capacity;
	list<int> l; // key list
	unordered_map<int, pair<list<int>::iterator, int>>mp; // key to list iterator and value
public:
	LRUCache(int capacity): capacity(capacity){}
	
	int get(int key) {
		if (mp.find(key) == mp.end()) 
			return -1;
		
		int value = mp[key].second;
		l.erase(mp[key].first);
		l.push_back(key);
		mp[key] = {--l.end(), value};
		return value;
	}
	
	void put(int key, int value) {
		
		// no key in list and full
		if (mp.find(key) == mp.end() && l.size() == capacity) {
			mp.erase(l.front());
			l.pop_front();
		}
		
		// exist key
		if (mp.find(key) != mp.end()) {
			l.erase(mp[key].first);
		}
		
		l.push_back(key);
		mp[key] = make_pair(--l.end(), value);
		
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}
	
