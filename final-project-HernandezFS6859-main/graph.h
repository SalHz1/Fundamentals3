//
// Created by Sal H on 5/9/23.
//

#ifndef FINAL_GRAPH_H
#define FINAL_GRAPH_H
#include <vector>
#include "data.h"
#include "iostream"
//For BreadthFirst
#include <queue>
using std::cout;
using std::endl;
using std::string;
using std::queue;
using std::vector;


class Graph
{
public:
//Constructors
    Graph();
    ~Graph();

    // Add vertex/edge
    bool addVertex(int); //vertex id
    bool addEdge(int,int); // from vertex id- to vertex id
    // Remove vertex/edge
    bool removeVertex(int); // id of vertex to remove
    bool removeEdge(int,int); // from this vertex to that vertex

    //Counts
    int getVertexCount();
    int getEdgeCount();

    //DisplayVertex Edges
    void displayVertexEdges(int); //Display vertex edges of this id
    void displayGraph();
    bool isEmpty();
    //Clear graph
    void clearGraph();
    bool containsVertex(int);
    void depthFirstTraversal(int, std::vector<bool> &visitedVertices);
    //start - visited QUEUE
    void breadthFirstTraversal(int,std::vector<bool> &visitedVertices);
    //Helper function
    void vectorDefaultFalseHelper(vector<bool>&);

private:
    std::vector<Vertex> ListOfVertices; // Adj list
    bool containsEdgeBetweenVertices(int,int);
    // Note(Important) - you need ID and the VECTOR list the vertex comes with
    Vertex& getVertex(int);
    int vertexCount;
    // Running count of ALL edges in graph
    int totalEdgeCount;
};


#endif //FINAL_GRAPH_H