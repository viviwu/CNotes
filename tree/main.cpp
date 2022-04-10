#include <iostream>
#include "multiway_tree.h"

using  namespace  tree::multiway_tree;

void test_multi_way_tree()
{
    MWNode root = MWNode("root");
    MWNode a0 = MWNode("a0");
    MWNode a1 = MWNode("a1");
    MWNode b0 = MWNode("b0");
    MWNode c0 = MWNode("b0");
    MWNode c1 = MWNode("c1");
    MWNode c2 = MWNode("c2");
    MWNode c3 = MWNode("c3");
    b0.LinkSubNode(c0);
    b0.LinkSubNode(c2);
    b0.LinkSubNode(c2);
    b0.LinkSubNode(c3);

    MWNode b1 = MWNode("b1");
    a1.LinkSubNode(b0);
    a1.LinkSubNode(b1);
    MWNode a2 = MWNode("a2");
    root.LinkSubNode(a0);
    root.LinkSubNode(a1);
    root.LinkSubNode(a2);

    XSize size = root.size();
    PRINT(size.width)
    PRINT(size.height)
}

int main() {

    test_multi_way_tree();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
