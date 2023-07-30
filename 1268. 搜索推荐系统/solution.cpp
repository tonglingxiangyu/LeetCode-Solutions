// 定义前缀树，child连接子树，words存储当前满足当前前缀的词
struct Trie{
    unordered_map<char, Trie*> child;
    priority_queue<string> words; // 默认最大堆
};

class Solution {
private:
// 将词添加进前缀树
    void addWord(Trie* root, const string& word){
        Trie* cur = root;
        for(const char& ch: word){
            if(!cur->child.count(ch)){
                cur->child[ch] = new Trie();
            }
            cur = cur->child[ch];
            cur->words.push(word);
            if(cur->words.size() > 3){
                cur->words.pop();
            }
        }
    }
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root = new Trie();
        for(const string& word: products){
            addWord(root, word);
        }

        vector<vector<string>> ans;
        Trie* cur = root;
        bool flag = false;
        for(const char& ch: searchWord){
            if(flag || !cur->child.count(ch)){
                ans.emplace_back(); // 添加一个空向量，用emplace_back效率更高
                flag = true; // 每次都添加一个空向量
            }
            else{
                cur = cur->child[ch];
                vector<string> selects;
                while(!cur->words.empty()){
                    selects.push_back(cur->words.top());
                    cur->words.pop();
                }
                reverse(selects.begin(), selects.end()); // 默认按最大堆弹出，逆序得到字典序从小到大
                ans.push_back(move(selects)); // 这里使用 move 而不是直接添加 selects，是因为我们不再需要 selects，所以我们可以避免复制 selects，直接将 selects 的所有权移动到 ans，这样可以提高代码的效率。
            }

        }
        return ans;
    }
};

/*
    1.push_back是最直观的方法，它将一个新元素添加到vector的末尾。这种方法需要先创建一个元素，然后将其复制或者移动到vector中。
    
    2.emplace_back也是将一个新元素添加到vector的末尾，但与push_back不同，emplace_back能够在原地构造元素，避免了不必要的复制或移动操作，因此通常更高效。
    vector<pair<int, string>> v;
    v.emplace_back(1, "one");  // 在vector末尾直接构造一个pair
    
    3.move并不是一个向量方法，而是C++标准库中的一个函数。它可以将一个对象的所有权从一个变量转移到另一个变量，而不涉及复制或析构操作。这对于重资源对象（如大型vector或其他容器）来说，可以大大提高效率。例如：
    vector<int> v1 = {1, 2, 3};
    vector<int> v2;
    v2 = std::move(v1);  // 将v1的所有权转移给v2
    在这个例子中，std::move将v1的所有元素的所有权转移给了v2，v1现在不再拥有任何元素。注意，std::move之后，原vector(v1）处于一个有效但未指定的状态，你不应该再使用它，除非你赋予它一个新的值。
    在使用push_back添加元素到向量时，可以结合使用std::move，例如：
    vector<string> v;
    string str = "Hello";
    v.push_back(std::move(str));  // 移动str到vector末尾，而不是复制
    在这个例子中，std::move将字符串str的所有权转移给了v，因此不涉及复制操作。注意，std::move之后，str处于一个有效但未指定的状态。
*/