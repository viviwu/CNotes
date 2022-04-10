//
// Created by Administrator on 2021/6/8.
//

#include "multiway_tree.h"


namespace tree{
    namespace multiway_tree {
        MWNode::MWNode(char *str):
                id(0)
                ,name("")
                ,origin_({0, 0})
                ,size_({CELL_W, CELL_H})
//            ,subNodes_(std::vector<MWNode>(0))
        {
            name = str;
            std::cout << this << " structure: "<< name << std::endl;
        }

        MWNode::~MWNode()
        {
            std::cout << this << " release: " << name << std::endl;
        }

        XPoint MWNode::origin(){
            int x=0;
            int y=0;
            return origin_;
        }

        XPoint MWNode::start()
        {
            return origin_;
        }

        XSize MWNode::size()
        {
            int width = size_.width + INSET_W;
            int height = size_.height + INSET_H;
            int snc = SubNodesCount();
            if (snc > 0)
            {
                int max_width = 0;
                int total_height = 0;
                for (auto node : this->subNodes_)
                {
                    XSize size = node.size();
                    max_width = (max_width > size.width ? max_width : size.width);
                    total_height += size.height;
                }
                width += max_width;
                height = height>total_height ? height : total_height;
            }
            return {width, height};
        }

        int MWNode::LinkSubNode(MWNode &node)
        {
            int ret = 0;
//            std::shared_ptr<MWNode> p(this);
//            node.parent = p;
            subNodes_.push_back(node);
            return ret;
        }

        int MWNode::SubNodesCount(){
            return subNodes_.size();
        }

    }
}