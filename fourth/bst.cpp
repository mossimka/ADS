#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

struct node {
    int key;
    node *ls = NULL;
    node *rs = NULL;
    string value = "";
    node() { key = 0; }
    node(int x) {
        key = x;
    }
    node(int x, node*l, node*r) {
        key = x;
        ls = l;
        rs = r;
    }
};

node* find(node *v, int x) {
    if (v == NULL)
        return NULL;
    cout << v->key << " ";//path
    if (v->key == x)
        return v;
    if (x < v->key)
    return find(v->rs, x);
}

// inserts new node and return it.
// (Ne) *&v means that we modify pointer
// that were passed to the function
// like we pass *root in main().ot
node* insert(node *&v, int x) {
    if (v == NULL) {
        v = new node(x);
        return v;
    }
    node *newnode;
    if (x <= v->key)
        newnode = insert(v->ls, x);
    else
        newnode = insert(v->rs, x);
    return newnode;
}


/* finds vertex by key with its parent + info about which son of parent v is */
tuple<node*, node*, int> find_with_prev(node *root, int x) {
    node *v = root;
    node *p = NULL; // parent of v
    int last_step = 0; // 0 means v is left son of p, 1 - right son
    while (v != NULL && v->key != x) {
        /* make a step to left or right */
        p = v;
        if (x < v->key)
            v = v->ls, last_step = 0;
        else
            v = v->rs, last_step = 1;
    }
    return make_tuple(v, p, last_step);
}


void del_without_comments(node *&root, int x) {
    /* if remove comments, its not that long */
    tuple<node*, node*, int> T 
        = find_with_prev(root, x);
    node* v = get<0>(T);
    node* pv = get<1>(T);
    int last_step = get<2>(T);
    // auto [v, pv, last_step] = find_with_prev(root, x);
    if (v == NULL)
        return;
    if (v->ls == NULL) {
        if (pv == NULL) { // v == root
            root = root->ls;
            delete v; // delete old root
            return;
        }
        if (last_step == 0) {
            pv->ls = v->rs;
        } else {
            pv->rs = v->rs;
        }
        delete v;
        return;
    }
    node *pu = v;
    node *u = v->ls;
    while (u->rs != NULL)
        pu = u, u = u->rs;
    v->key = u->key;
    v->value = u->value;
    pu->rs = u->ls;
    delete u;
    return;
}

/* reversed inorder, ordinary inorder: left son, me, right son */
void print_inorder(node *v, int tab = 0) {
    if (v == NULL)
        return;
    // print right son
    print_inorder(v->rs, tab+2);
    // print me
    for (int i = 0; i < tab; i++)
        cout << ".";
    cout << v->key << "\n";
    // print left son
    print_inorder(v->ls, tab+2);
}

int main () {

    /* STEP 1. Create tree */
    node *root = NULL;
    int a[12] = {10,5,3,1,4,7,6,16,15,16,12,20};
    for (int i = 0; i < 12; i++) {
        insert(root, a[i]);
        // Since there is an ampersand (&)
        // root variable will change within insert 
        // function itself on initial run
    }

    // lean your head to the left
    // to see the tree from left to right
    print_inorder(root);
    
    /* STEP 2. Find operation */
    {   
        // cout << "\n------------\n\n";
        // cout << "Search path: ";
        // node *v = find(root, 7);
        // cout << endl;
        // cout << "Just found: " << v->key << "\n";
        
        // cout << "Searching 9: ";
        // node *vv = find(root, 9);
        // if (vv == NULL)
        //     cout << "| 9 not found!\n";
        // else
        //     cout << "| Found 9!\n";

        // cout << "Find with parent method:\n";
        // // returns <vertex, parent, which_son>
        // tuple<node*, node*, int> T = find_with_prev(root, 7);
        // node* ver = get<0>(T);
        // node* par = get<1>(T);
        // int which_son = get<2>(T);
        // cout << "Found " << ver->key << ", ";
        // cout << (which_son == 0 ? "left" : "right");
        // cout << " son of a " << par->key << "\n";
    }

    /* STEP 3. Insert */
    { 
        // cout << "\n------------\n\n";
        // cout << "Insert 9\n";
        // insert(root, 9);
        // print_inorder(root);
    }
    
    /* 
        STEP 4. Delete operation, diffent tests
        test should cover all cases of the code 
    */
    {
        // cout << "\n------------\n\n";
        // insert(root, 8);
        // cout << "Extra 8 inserted, before delete of 10:\n";
        // print_inorder(root);
        
        // del(root, 10);
        // cout << "After delete of 10:\n";
        // print_inorder(root);
        // cout << "Checking Case 1.b, ";
        // cout << "After delete of 12:\n";
        // del(root, 12);
        // print_inorder(root);

        // cout << "After delete of 15:\n";
        // del(root, 15);
        // print_inorder(root);
        // cout << "===============\n";
        // for (int i = 1; i <= 8; i++) {
        //     cout << "Delete " << i << "\n";
        //     del(root, i);
        //     print_inorder(root);
        //     cout << "-----\n";
        // }

        // cout << "Checking Case 1.a by deleting 9:\n";
        // del(root, 9);
        // print_inorder(root);
        // cout << "-----\n";

    }
 
    return 0;
}




