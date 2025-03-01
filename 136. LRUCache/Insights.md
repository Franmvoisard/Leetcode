# **Understanding the LRUCache Implementation**

## **Introduction**

The `LRUCache` class implements a **Least Recently Used (LRU) cache** using a **doubly linked list** and an **unordered\_map**. This ensures **O(1) complexity** for both `get` and `put` operations.

## **Node Structure**

The `Node` struct represents individual elements in the cache.

```cpp
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) { }
};
```

Each node contains:

- `key` and `value` to store cache data.
- `prev` and `next` pointers for **bidirectional traversal**.

## **Class Members**

```cpp
private:
    int capacity;
    Node* head; // Sentinel node for the most recently used node
    Node* tail; // Sentinel node for the least recently used node
    unordered_map<int, Node*> map;
```

### **Sentinel Nodes (****`head`**** and ****`tail`****)**

- `head` and `tail` are dummy nodes that simplify insertion and deletion.
- `head->next` always points to the **most recently used node**.
- `tail->prev` always points to the **least recently used node**.

## **Helper Functions**

### **Moving a Node to the Head**

```cpp
void moveNodeToHead(Node* node){
    if(node == head->next) return;
    disconnectNode(node);
    connectNodeToHead(node);
}
```

- If the node is already the most recently used, do nothing.
- Otherwise, **remove** it from its position and **move it to the head**.

### **Connecting a Node to the Head**

```cpp
void connectNodeToHead(Node* node){
    node->next = head->next;
    node->prev = head;
    node->next->prev = node;
    node->prev->next = node;
}
```

- Inserts the node **immediately after ****`head`**, making it the most recently used.

### **Disconnecting a Node**

```cpp
void disconnectNode(Node* node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
}
```

- Removes the node from the **doubly linked list**.

### **Deleting the Least Recently Used (LRU) Node**

```cpp
void deleteTail(){
    Node* nodeInTail = tail->prev;
    disconnectNode(nodeInTail);
    map.erase(nodeInTail->key);
    delete nodeInTail;
}
```

- Identifies `tail->prev` (the **least recently used** node), removes it, and deletes it.

## **Constructor & Destructor**

```cpp
LRUCache(int capacity) : capacity(capacity) {
    head = new Node(0,0);
    tail = new Node(0,0);
    head->next = tail;
    tail->prev = head;
}
```

- Initializes the **cache capacity**.
- Creates **sentinel nodes** `head` and `tail`.

```cpp
~LRUCache(){
    Node* current = head;
    while(current){
        Node* next = current->next;
        delete current;
        current = next;
    }
}
```

- Properly deallocates all nodes to prevent memory leaks.

## **Cache Operations**

### **Get Operation**

```cpp
int get(int key) {
    auto iterator = map.find(key);
    if(iterator == map.end()) return -1;
    Node* node = iterator->second;
    moveNodeToHead(node);
    return node->value;
}
```

- If `key` is **not found**, return `-1`.
- If found, **move the node to the head** (most recently used).

### **Put Operation**

```cpp
void put(int key, int value) {
    auto iterator = map.find(key);
    if(iterator != map.end()){
        Node* node = iterator->second;
        node->value = value;
        moveNodeToHead(node);
    }
    else {
        Node* newNode = new Node(key, value);
        if(map.size() < capacity) {
            connectNodeToHead(newNode);
            map[key] = newNode;
        }
        else {
            deleteTail();
            connectNodeToHead(newNode);
            map[key] = newNode;
        }
    }
}
```

- If the key **already exists**, update its value and move it to the head.
- If the key **does not exist**:
  - If there's space, insert it at the head.
  - If the cache is full, **evict the least recently used (LRU) node**, then insert the new node.

## **Conclusion**

This implementation of `LRUCache` efficiently maintains **O(1) time complexity** for `get` and `put` using:

- **Sentinel nodes (****`head`****, ****`tail`****)** to simplify list operations.
- **A hash map (****`unordered_map`****)** for fast lookups.
- **A doubly linked list** for efficient node removal and insertion.
