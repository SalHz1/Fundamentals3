//
// Created by Sal H on 5/9/23.
//
//Git commit test comment
#include "graph.h"
Graph::Graph()
{
    //Initialize variables to 0
    vertexCount = totalEdgeCount = 0;
}
Graph::~Graph()
{
    // Call clear when finished with object
    clearGraph();
}
bool Graph::addVertex(int id)
{
    bool addedFlag = false;
    // only positive ids , no duplicates
    if (id > 0 && !containsVertex(id))
    {
        //Create vertex assign its id to the id after validating
        Vertex vertex;
        vertex.data.id = id;
        // Adding vertex to the vector
        ListOfVertices.push_back(vertex);
        // Incrementing the count
        vertexCount++;
        //A vertex was added so set flag to true
        addedFlag = true;
    }
    // return flag result
    return addedFlag;
}
bool Graph::addEdge(int fromID, int toID) {
    bool addEdge = false;
    // Check if both vertices exist
    Vertex& fromVertex = getVertex(fromID);
    Vertex& toVertex = getVertex(toID);

    // Add condition where you can't add an edge to the same vertex
    // Example input: 5,5 should not add an edge and should not increment edgeCount
    // Segfaults addressed - positive ids only
    // Check if there is no edge between the vertices
    if (fromID > 0 && toID > 0 && fromID != toID && containsVertex(fromID) && containsVertex(toID) &&
        !containsEdgeBetweenVertices(fromID, toID))
    {
            // Add toID to the fromVertex vector in a sorted manner
            vector<int>& fromEdges = fromVertex.data.edges;
            std::vector<int>::iterator itFrom = std::lower_bound(fromEdges.begin(), fromEdges.end(), toID);
            fromEdges.insert(itFrom, toID);
            // Add fromID to the toVertex vector in a sorted manner
            vector<int>& toEdges = toVertex.data.edges;
            std::vector<int>::iterator itTo = std::lower_bound(toEdges.begin(), toEdges.end(), fromID);
            toEdges.insert(itTo, fromID);
            // Increment total edge count
            totalEdgeCount++;
            //Change flag
            addEdge = true;
    }
    return addEdge;
}
bool Graph::removeVertex(int id)
{
    bool removedVertexFlag = false;
    // Check if the vertex with the given id exists in the graph
    if (containsVertex(id))
    {
        // Find the vertex with the given id
        std::vector<Vertex>::iterator start = ListOfVertices.begin();
        while (start != ListOfVertices.end())
        {
            if (start->data.id == id)
            {
                break;
            }
            ++start;
        }

        // Remove all "from" edges from the vertex
        for (int edge : start->data.edges)
        {
            removeEdge(id, edge);
        }
        // Remove all "to" edges to the vertex
        for (Vertex& vertex : ListOfVertices)
        {
            removeEdge(vertex.data.id, id);
        }
        // Erase the vertex from the list
        ListOfVertices.erase(start);
        // Update the vertex count
        --vertexCount;
        // Decrement the totalEdgeCount by the number of edges removed
        removedVertexFlag = true;
    }
    return removedVertexFlag;
}
bool Graph::removeEdge(int fromID, int toID)
{
    bool removedFlag = false;
    if (containsVertex(fromID) && containsVertex(toID))
    {
        Vertex& fromVertex = getVertex(fromID);
        std::vector<int>& edges = fromVertex.data.edges;
        std::vector<int>::iterator vertexSearch = std::find(edges.begin(), edges.end(), toID);
        if (vertexSearch != edges.end())
        {
            edges.erase(vertexSearch);
            removedFlag = true;
            --totalEdgeCount;  // Decrement the totalEdgeCount
        }
        Vertex& toVertex = getVertex(toID);
        std::vector<int>& reverseEdges = toVertex.data.edges;
        std::vector<int>::iterator reverseSearch = std::find(reverseEdges.begin(), reverseEdges.end(), fromID);
        if (reverseSearch != reverseEdges.end())
        {
            reverseEdges.erase(reverseSearch);
            // Decrement the totalEdgeCount
        }
    }
    return removedFlag;
}
int Graph::getVertexCount()
{
    return vertexCount;
}
int Graph::getEdgeCount()
{
    return totalEdgeCount;
}
void Graph::displayVertexEdges(int id) // Displays the Edges of the VERTEX
{
    if (!containsVertex(id)) // If n/f display message
    {
        cout << "Vertex " << id << " was not found in the Graph.\n" ;
    }
    const Vertex &vertex = getVertex(id);
    cout << "Edges: ";
    if(vertex.data.edges.size() == 0)
    {
        cout << "No edges.";
    }
    for (int x = 0; x < vertex.data.edges.size(); x++)
    {

        cout <<"[" <<  vertex.data.edges[x] << "]";
        if (x < vertex.data.edges.size() - 1)
        {
            cout << ",";
        }
    }
    cout << endl;
}
void Graph::displayGraph()
{
    if (!isEmpty())
    {
        cout << endl;
        cout << "Displaying Graph...\n";
        for (Vertex vertex : ListOfVertices)
        {
            int id = vertex.data.id;
            cout << "Vertex: " << id << " ";
            displayVertexEdges(id);
        }
        cout << "Total vertices: " << getVertexCount() << endl;
        cout << "Total edge count: " << getEdgeCount() << endl;
    }
    else
    {
        cout << "No vertices, Graph is empty.\n";
    }
}
bool Graph::isEmpty()
{
    return vertexCount == 0;
}

void Graph::clearGraph()
{
    ListOfVertices.clear();
    vertexCount = 0;
    totalEdgeCount = 0;
}
void Graph::depthFirstTraversal(int beginning, std::vector<bool> &visitedVertices)
{
    //Begins with given beginning vertice, marks it as visited then displays the id.
    //CHECK IF VERTEX EXISTS FIRST OTHERWISE SEGFAULT IF GRAPH IS EMPTY
    if(containsVertex(beginning))
    {
        visitedVertices[beginning] = true;
        cout << getVertex(beginning).data.id<< " ";
        // Using recursion to traverse the graph
        for( int adjV : getVertex(beginning).data.edges )
        {
            if( !visitedVertices[adjV] ) // if the current node isn't marked as visited then traverse
            {
                cout << "-> ";
                depthFirstTraversal(adjV,visitedVertices);
            }
        }
    }
    else
    {
        cout << "A vertex with ID: " << beginning << " was not found. Depth Traversal cannot be performed.\n";
    }
}
void Graph::breadthFirstTraversal(int beginning, std::vector<bool> &visitedVertices)
{
    queue<int> line; // Create queue to store vertices
    visitedVertices[beginning] = true;
    line.push(beginning); // Push the beginning onto the queue since that will indicate what still needs to be visited
    int prevID = -1;
    while(line.empty() == false)
    {
        int current = line.front(); // Set current to the front of the line
        line.pop();
        if (prevID != -1)
        {
            cout << " -> ";
        }
        cout << getVertex(current).data.id;
        for (int adjV : getVertex(current).data.edges)
        {
            if (!visitedVertices[adjV])
            {
                visitedVertices[adjV] = true;
                line.push(adjV);
            }
        }
        prevID = current; // Update the previous vertex ID
    }
    cout << endl;
}
bool Graph::containsVertex(int id)
{
    bool containsFlag = false;
    for(Vertex searchVertex : ListOfVertices)
    {
        if(searchVertex.data.id == id)
        {
            containsFlag = true;
        }
    }
    return containsFlag;
}
bool Graph::containsEdgeBetweenVertices(int fromId, int toID)  // Checks if a vertice has edges
{
    const Vertex &vertex = getVertex(fromId);
    bool containsEdgeBetween = false;
    if(containsVertex(fromId) && containsVertex(toID))
    {

        for( int edge : vertex.data.edges )
        {
            if (edge == toID)
            {
                containsEdgeBetween = true;
            }
        }
    }
    return containsEdgeBetween;
}
Vertex& Graph::getVertex(int id)
{
    Vertex* returnedVertex = nullptr;
    for (Vertex& vertex : ListOfVertices)
    {
        if (vertex.data.id == id)
        {
            returnedVertex = &vertex;
        }
    }
    return *returnedVertex;
}
void Graph::vectorDefaultFalseHelper(vector<bool> &visitedVertices)
{
    for (int i = 0; i < getVertexCount()+1; i++)
    {
        visitedVertices[i] = false;
    }
}