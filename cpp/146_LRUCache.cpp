#include <iostream>
#include <unordered_map>
using namespace std;


struct LinkNode {
	int key;
	int value;
	LinkNode* prev;
	LinkNode* next;
	LinkNode(): key(0), value(0), prev(nullptr), next(nullptr){}
	LinkNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr){}
};

class LRUCache {
private:
	LinkNode *head;
	LinkNode *tail;
	unordered_map<int, LinkNode*> cache;
	int size;
	int capacity;

public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
    	head = new LinkNode();
    	tail = new LinkNode();
    	head->next = tail;
    	tail->prev = head;
    }
    
    int get(int key)
    {// 把每次get（用过的）放到最前面
    	if (!cache.count(key))
    	{
    		return -1;
    	}

    	LinkNode *node = cache[key];
    	moveToHead(node);
    	return node->value;
    }
    
    // 每次插入到最前面，如果满了就把最后一个删除，因为用到过的都往前面放了，所以后面的就是没用过的
    void put(int key, int value) 
    {
    	if (!cache.count(key))
    	{
    		LinkNode* node = new LinkNode(key, value);
    		addToHead(node);
    		cache[key] = node;
    		++size;
    		if (size > capacity)
    		{
    			LinkNode* rmNode = removeTail();
    			cache.erase(rmNode->key);
    			--size;
    		}
    	}
    	else
    	{
    		LinkNode* node = cache[key];
    		node->value = value;
    		moveToHead(node);
    	}
    }

    void removeNode(LinkNode* node)
    {
    	node->prev->next = node->next;
    	node->next->prev = node->prev;
    }

    void addToHead(LinkNode* node)
    {
    	node->prev = head;
    	node->next = head->next;
    	head->next->prev = node;
    	head->next = node;
    }

    void moveToHead(LinkNode* node)
    {
    	removeNode(node);
    	addToHead(node);
    }

    LinkNode* removeTail()
    {
    	LinkNode *node = tail->prev;
    	removeNode(node);
    	return node;
    }

};


int main()
{
	LRUCache cache = LRUCache( 2 /* 缓存容量 */ );

	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;       // 返回  1
	cache.put(3, 3);    // 该操作会使得密钥 2 作废
	cout << cache.get(2) << endl;;       // 返回 -1 (未找到)
	cache.put(4, 4);    // 该操作会使得密钥 1 作废
	cout << cache.get(1) << endl;       // 返回 -1 (未找到)
	cout << cache.get(3) << endl;       // 返回  3
	cout << cache.get(4) << endl;       // 返回  4
	return 0;
}