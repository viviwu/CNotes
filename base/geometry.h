//
// Created by Administrator on 2021/6/8.
//

#ifndef CNOTES_GEOMETRY_H
#define CNOTES_GEOMETRY_H

struct XPoint{
    int x;
    int y;
};
typedef struct XPoint CGPoint;

struct XSize{
    int width;
    int height;
};
typedef struct XSize CGSize;

struct XRect{
    XPoint origin;
    XSize size;
};
typedef struct XRect CGRect;

#endif //CNOTES_GEOMETRY_H
