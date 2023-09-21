//
// Created by Sal H on 5/8/23.
//

#ifndef FINAL_DATA_H
#define FINAL_DATA_H

#include <string>
using std::string;

struct Data
{
    // id of the vertex
    int id;
    // Each Vertex contains a vector(List) of all the edges
    std::vector<int> edges;
};

struct Vertex
{
    Data data;
};

#endif