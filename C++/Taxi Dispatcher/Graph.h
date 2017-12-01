//#pragma once

#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <iostream>
#include <vector>

using namespace std;

#define INFINITY 99999
#define NOT_A_VERTEX -1

class CGraphNode
{
public:
	CGraphNode(void);
	~CGraphNode(void);

	long m_dist;  //Assumption: distance from parent node to current node.
                  //Only valid if there are multiple nodes for the same vertex
                  // but with different parents.
	bool m_known; //Assumption: TRUE iff processed by list<edge> for shortest
                  // route calculation.
	int m_path; //Assumption: parent vertex.
    //int m_label; //Def: contains the ID for the current node.

};


typedef struct edge
{
  int startVert;
  int endVert;
  int weight;
  
  edge(): startVert(-1), endVert(-1), weight(-1) {}
  
} EDGE;

class CGraph
{
public:
	CGraph(int initSize);
    CGraph(void);
	~CGraph(void);

	//adds an edge to the graph going from start to end and having weight "weight"
	void AddEdge(int start, int end, int weight);

	//return the length of a specified edge through the parameter length. 
	//returns false if there is no such edge, otherwise true
	bool GetEdgeLength(int start, int end, int length);

	//calculates the weight of the shortest path between start and end
	int CalcShortestPath(int start, int end);
  
  int GetEdge(int start, int end);
  int GetSize();
  
  vector<CGraphNode> m_nodeVect;

private:
	//runs Dijkstra's algorithm to calculate the shortest path
	void Dijkstras(int startVert);
	//helper function for above.  Find the smallest unknown vertex
	int SmallestUnknownVertex();

  /* Changed to Dhanya_method */
  //list <CGraphNode> * m_nodeList;
  list <EDGE> * m_adjList;
	

	//number of nodes in the graph
	int m_size;

	int m_lastDijkCall;

public:
	CGraphNode * m_verts;
};

#endif
