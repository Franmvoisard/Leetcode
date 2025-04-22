class RandomizedSet {
    unordered_map<int,int> map;
    vector<int> array;
public:
    RandomizedSet() { }
    
    bool insert(int val) {
        if(map.contains(val)) return false;
        else {
            array.emplace_back(val);
            map.emplace(val, array.size() - 1);
            return true;
        }
    }
    
    bool remove(int val) {
        if(!map.contains(val)) return false;
        else {
            int indexToRemove = map[val];
            int& lastElement = array.back();

            map[lastElement] = indexToRemove;
            array[indexToRemove] = lastElement;

            array.pop_back();
            map.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        return array[rand() % array.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
