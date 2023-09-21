//
// Created by Sal H on 5/8/23.
//

#include "main.h"
int main()
{
    cout << "Creating a graph...\n";
    Graph graph;
    std::vector<bool> visitedVertices(graph.getVertexCount() + 1, false);
    cout << "Graph created...\n";
    cout << "Testing isEmpty...\n";
    if(graph.isEmpty())
    {
        cout << "The graph is empty.\n";
    }
    else
    {
        cout << "The graph is not empty.\n";
    }
    cout << "calling displayGraph()\n";
    graph.displayGraph();
    cout << "Testing adding negative vertex...\n";
    int negativeNumber = -1;
    if(graph.addVertex(negativeNumber))
    {
        cout << "Success! Added: " << negativeNumber << " to the List of vertices.\n";
    }
    else
    {
        cout << "Fail! Unable to add: " << negativeNumber << endl;
    }
    int duplicateTest = 1;
    cout << "Adding 1 vertice.";
    if(graph.addVertex(duplicateTest))
    {
        cout << "Success! Added: " << duplicateTest << " to the list of vertices.\n";
    }
    else
    {
        cout << "Fail! Unable to add: " << duplicateTest << endl;

    }
    graph.displayGraph();
    cout << "Attempting to add:" << duplicateTest << endl;
    if(graph.addVertex(duplicateTest))
    {
        cout << "Success! Added: " << duplicateTest << " to the list of vertices.\n";
    }
    else
    {
        cout << "Fail! Unable to add: " << duplicateTest << endl;

    }
    graph.displayGraph();
    cout << "Testing addEdge on nonexistent vertex.\n";
    int unusedNumberforVertex = 99;
    if(graph.addEdge(duplicateTest,unusedNumberforVertex))
    {
        cout << "Success! added an edge between : " << duplicateTest << " and " << unusedNumberforVertex << endl;
    }
    else
    {
        cout << "Failed adding Edge, unable to add an edge between " << duplicateTest << " and " << unusedNumberforVertex << endl;
    }
    cout << "Testing containsVertex...\n";
    if(graph.containsVertex(duplicateTest))
    {
        cout << "The graph does contain a vertex with the id : " << duplicateTest << endl;
    }
    else
    {
        cout << "The graph does not contain a vertex with the id : " << duplicateTest << endl;

    }
    cout << "Testing; Calling clear()...\n";
    graph.clearGraph();
    graph.displayGraph();
    cout << "Building graph from Figure 20-12 of book...\n";
    cout << "See List Below for reference.\n";
    cout << "A,B,C,D,E,F,G,H,I\n";
    cout << "1,2,3,4,5,6,7,8,9\n";
    cout << "Creating vertices 1-9...\n";
    for(int x = 1; x<=9; x++)
    {
        graph.addVertex(x);
    }
    cout << "Making all the edges...\n";
    graph.addEdge(1,9);
    graph.addEdge(1,2);
    graph.addEdge(1,6);
    graph.addEdge(2,3);
    graph.addEdge(5,2);
    graph.addEdge(5,3);
    graph.addEdge(5,7);
    graph.addEdge(7,6);
    graph.addEdge(7,4);
    graph.addEdge(4,3);
    graph.addEdge(4,8);
    graph.displayGraph();
    cout << "Showing depth first traversal...\n";
    cout << "Correct output (For verification): \n1,2,3,4,7,5,6,8,9\n";
    cout << "a,b,c,d,g,e,f,h,i\n";
    graph.depthFirstTraversal(1,visitedVertices);
    cout << endl;
    cout << "Showing breadth first traversal...\n";
    cout << "Correct output (For verification): \n1,2,6,9,3,5,7,4,8\n";
    cout << "a,b,f,i,c,e,g,d,h\n";
    graph.vectorDefaultFalseHelper(visitedVertices);
    graph.breadthFirstTraversal(1,visitedVertices);
    cout << "Removing vertex 5...\n";
    graph.removeVertex(5);
    graph.displayGraph();
    cout << "Removing edge from 8 to 4...\n";
    graph.removeEdge(8,4);
    graph.displayGraph();
    cout << "Calling clear...\n";
    graph.clearGraph();
    srand(time(NULL));
    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */

    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
    }
    ids[testdatasize-2] = ids[testdatasize-3];

    cout << "Showing Test Data (" << testdatasize << " entries/Vertex Ids)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << endl;
    }
    cout << "Adding all testdata to list of vertices...\n";
    for(int addVertexLoop = 0; addVertexLoop < testdatasize; addVertexLoop++)
    {
        if( graph.addVertex(ids[addVertexLoop]) )
        {
            cout << "Success! Added :" << ids[addVertexLoop] << " to the list of vertices\n";
        }
        else
        {
            cout << "Fail! Unable to add :" << ids[addVertexLoop] << " to the list of vertices\n";
        }
    }
    graph.displayGraph();
    cout << "Adding edges randomly between...\n";

    for(int addEdges = 0; addEdges < testdatasize*TESTMULTIPLIER;addEdges++)
    {
        int randomNumber1 = rand() % TESTRANGE + (NEGATIVERANGE);
        int randomNumber2 = rand() % TESTRANGE + (NEGATIVERANGE);
        if(graph.addEdge(randomNumber1,randomNumber2) )
        {
            cout << "Added an edge between " << randomNumber1 << " and " << randomNumber2 << endl;
        }
        else
        {
            cout << "unable to add an edge between " << randomNumber1 << " and " << randomNumber2 << endl;
        }
    }
    cout << "Testing contains randomly...\n";
    for(int contains = 0; contains < testdatasize*TESTMULTIPLIER;contains++)
    {
        int randomNumber1 = rand() % TESTRANGE + (NEGATIVERANGE);
        if(graph.containsVertex(randomNumber1))
        {
            cout << "There is a vertex with the id: " << randomNumber1 << " in the graph.\n";
        }
        else
        {
            cout << "Unable to find a vertex with the id: " << randomNumber1 << " in the graph.\n";
        }
    }
    graph.displayGraph();
    cout << "Testing removeEdge randomly..." << endl;
    for(int addEdges = 0; addEdges < testdatasize*TESTMULTIPLIER;addEdges++)
    {
        int randomNumber1 = rand() % TESTRANGE + (NEGATIVERANGE);
        int randomNumber2 = rand() % TESTRANGE + (NEGATIVERANGE);
        if(graph.removeEdge(randomNumber1,randomNumber2) )
        {
            cout << "Removed an edge between " << randomNumber1 << " and " << randomNumber2 << endl;
        }
        else
        {
            cout << "No edge found between " << randomNumber1 << " and " << randomNumber2 << endl;
        }
    }
    graph.displayGraph();
    cout << "Testing removeVertex randomly...\n";
    for(int vertex = 0; vertex < testdatasize*SMALLERMULTIPLIER;vertex++)
    {
        int randomNumber1 = rand() % TESTRANGE + (NEGATIVERANGE);
        if(graph.removeVertex(randomNumber1))
        {
            cout << "Removed vertex : " << randomNumber1 << " in the graph.\n";
        }
        else
        {
            cout << "Unable to find a vertex with the id: " << randomNumber1 << " in the graph.\n";
        }
    }
    graph.displayGraph();
    cout << "Clearing graph..." << endl;


    graph.clearGraph();
    graph.displayGraph();

}
