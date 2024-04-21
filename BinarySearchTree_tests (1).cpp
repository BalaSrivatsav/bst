#include "BinarySearchTree.hpp"
#include "unit_test_framework.hpp"

using namespace std;

TEST(test_stub) {
    // Add your tests here
    ASSERT_TRUE(true);
}

TEST(test_multiple){
    BinarySearchTree<int>b;
    b.insert(5);
    ASSERT_FALSE(b.empty());
    ASSERT_TRUE(b.size()==1);
    ASSERT_TRUE(b.height()==1);
}

TEST(test_multiple2){
    BinarySearchTree<int>b;
    ASSERT_TRUE(b.empty());
    ASSERT_TRUE(b.size()==0);
    ASSERT_TRUE(b.height()==0);
    ASSERT_TRUE(b.find(5) == b.end());
    ASSERT_TRUE(b.check_sorting_invariant());
}

TEST(test_traverse){
    BinarySearchTree<int>b;
    ostringstream os;
    b.traverse_inorder(os);
    ASSERT_TRUE(os.str() == "");
    b.insert(5);
    b.insert(-8);
    b.insert(16);
    ASSERT_FALSE(os.str() == "-8 5 16 ");
}

TEST(test_traverse2){
    BinarySearchTree<int>b;
    ostringstream os;
    b.traverse_preorder(os);
    ASSERT_TRUE(os.str() == "");
    b.insert(5);
    b.insert(3);
    b.insert(4);
    b.insert(1);
    ASSERT_FALSE(os.str() == "5 3 1 4 ");
}

TEST(min_greater_than){
    BinarySearchTree<int>b;
    b.insert(-11);
    b.insert(999);
    b.insert(0);
    b.insert(13);
    ASSERT_TRUE(*b.min_greater_than(13) == 999);
    ASSERT_TRUE(*b.min_greater_than(0) == 13);
    ASSERT_FALSE(*b.min_greater_than(0) == -11);
}

TEST(edge){
    BinarySearchTree<double>b;
    b.insert(3.14);
    b.insert(4.00);
    b.insert(2.65);
    ASSERT_FALSE(b.find(2.65)==b.end());
    ASSERT_TRUE(b.size()==3);
    ASSERT_TRUE(b.height()==2);
}

TEST(edge2){
    BinarySearchTree<string>b;
    b.insert("Bala");
    b.insert("Srivatsav");
    b.insert("Yerramilli");
    ASSERT_TRUE(*b.max_element()=="Yerramilli");
    ASSERT_TRUE(*b.min_element()=="Bala");
}

TEST(destroy_nodes){
    ASSERT_TRUE(true);
}

TEST_MAIN()
