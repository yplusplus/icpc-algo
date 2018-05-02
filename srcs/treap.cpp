struct TreapNode {
    TreapNode() : left_(NULL), right_(NULL) {}
    TreapNode(int key) : key_(key), size_(1), left_(NULL), right_(NULL) {}

    int key_, size_;
    TreapNode *left_, *right_;

    inline int size() const { return size_; }
    inline int lsize() const { return left_ ? left_->size_ : 0; }
    inline int rsize() const { return right_ ? right_->size_ : 0; }

    TreapNode *push_down() {
        // other push_down operations
        return this;
    }
    TreapNode *push_up() {
        size_ = 1 + lsize() + rsize();
        // other push_up operations
        return this;
    }
};

void split(TreapNode *root, int k, TreapNode *&p, TreapNode *&q) {
    root->push_down();
    if (k == 0) { p = NULL, q = root; return; }
    if (root->size() == k) { p = root, q = NULL; return; }
    if (root->lsize() >= k) {
        q = root;
        split(q->left_, k, p, q->left_);
        q->push_up();
    } else {
        p = root;
        k -= root->lsize() + 1;
        split(p->right_, k, p->right_, q);
        p->push_up();
    }
}

TreapNode *merge(TreapNode *p, TreapNode *q) {
    if (!p || !q) return p ? p : q;
    bool less = rand() % (p->size() + q->size()) < p->size();
    if (less) {
        p->push_down();
        p->right_ = merge(p->right_, q);
        return p->push_up();
    }

    q->push_down();
    q->left_ = merge(p, q->left_);
    return q->push_up();
}

// insert = split + merge + merge
// delete = split + split + merge