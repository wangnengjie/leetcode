#include <string>
#include <vector>
#include <memory>

using std::string;
using std::vector;

class MapSum
{
public:
    /** Initialize your data structure here. */
    MapSum()
    {
        root = std::make_shared<Node>();
    }

    void insert(string key, int val)
    {
        auto p = root;
        for (int i = 0, index; i < key.size() - 1; i++)
        {
            index = key[i] - 'a';
            if (!p->sub[index])
                p->sub[index] = std::make_shared<Node>();
            p = p->sub[index];
        }
        int valChange = val;
        if (!p->sub[key.back() - 'a'])
        {
            p->sub[key.back() - 'a'] = std::make_shared<Node>(val, 0);
        }
        else
        {
            valChange -= p->sub[key.back() - 'a']->val;
            p->sub[key.back() - 'a']->val = val;
        }
        p = root;
        for (const auto &c : key)
        {
            p = p->sub[c - 'a'];
            p->sumVal += valChange;
        }
    }

    int sum(string prefix)
    {
        auto p = root;
        for (const auto &c : prefix)
        {
            p = p->sub[c - 'a'];
            if (!p)
                return 0;
        }
        return p->sumVal;
    }

private:
    using Node = struct Node
    {
        int val;
        int sumVal;
        std::shared_ptr<Node> sub[26]{nullptr};
        Node() : val(0), sumVal(0) {}
        Node(int _val, int _sumVal) : val(_val), sumVal(_sumVal) {}
    };
    std::shared_ptr<Node> root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */