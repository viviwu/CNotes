//
// Created by Administrator on 2021/6/8.
//

#ifndef CNOTES_MULTIWAY_TREE_H
#define CNOTES_MULTIWAY_TREE_H
#include <iostream>
#include <memory>
#include <vector>
#include "geometry.h"

#define PRINT(var) std::cout << var << std::endl;

namespace tree{
    namespace multiway_tree {

        class MWNode {
        public:
            int id;
            char *name;

            MWNode(char *name = "");
            ~MWNode();

            XPoint origin();
            XPoint start();
            XSize size();

            int LinkSubNode(MWNode &node);
            int SubNodesCount();

            std::weak_ptr<MWNode> parent;

        private:
            std::vector<MWNode> subNodes_;
            XPoint origin_;
            XSize size_;
        };
    }
}

#define INSET_W 50
#define INSET_H 15
#define CELL_W 100
#define CELL_H 30


#endif //CNOTES_MULTIWAY_TREE_H
