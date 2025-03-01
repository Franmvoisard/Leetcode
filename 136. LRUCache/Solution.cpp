
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value) : key(key), value(value), next(nullptr), prev(nullptr) { }
};

class LRUCache {
    private:
        int capacity;
        Node* head; //Sentinel
        Node* tail; //Sentinel
        unordered_map<int, Node*> map;

        void moveNodeToHead(Node* node){
            if(node == head->next) return;

            disconnectNode(node);
            connectNodeToHead(node);
        }

        void connectNodeToHead(Node* node){
            node->next = head->next;
            node->prev = head;
            node->next->prev = node;
            node->prev->next = node;
        }

        void disconnectNode(Node* node) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }

        void deleteTail(){
            Node* nodeInTail = tail->prev;
            disconnectNode(nodeInTail);
            map.erase(nodeInTail->key);
            delete nodeInTail;
        }

    public:
        LRUCache(int capacity) : capacity(capacity) {
            head = new Node(0,0);
            tail = new Node(0,0);
            head->next = tail;
            tail->prev = head;
        }

        ~LRUCache(){
            Node* current = head;
            while(current){
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        
        int get(int key) {
            auto iterator = map.find(key);

            if(iterator == map.end()) return -1;
            Node* node = iterator->second;
            moveNodeToHead(node);
            return node->value;
        }
        
        void put(int key, int value) {
            auto iterator = map.find(key);

            if(iterator != map.end()){ //Key was found
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
                else { //Not found and there is not capacity
                    deleteTail();
                    connectNodeToHead(newNode);
                    map[key] = newNode;
                }
            }
    }
};
