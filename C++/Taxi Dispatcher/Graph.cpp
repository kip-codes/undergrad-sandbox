#include "Graph.h"
#include <queue>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

CGraphNode::CGraphNode(void)
{
}

CGraphNode::~CGraphNode(void)
{
}

CGraph::CGraph(void)
{
}

CGraph::~CGraph(void)
{
}

CGraph::CGraph(int initSize)
{
  m_size = initSize;
  m_nodeVect.resize(m_size);
  
  m_adjList = new list<EDGE>;
  
}

void CGraph::AddEdge(int start, int end, int weight)
{
//  CGraphNode* nodeOb = new CGraphNode;
//  nodeOb->m_dist = weight;
//  nodeOb->m_known = false;
//  nodeOb->m_path = start; //assuming m_path represents parent vertex
//  nodeOb->m_label = end;
//  
//  m_nodeVect.push_back(*nodeOb);
  
  EDGE* edgeOb = new EDGE();
  edgeOb->startVert = start;
  edgeOb->endVert = end;
  edgeOb->weight = weight;
  
  m_adjList->push_back(*edgeOb);
  
}

bool CGraph::GetEdgeLength(int start, int end, int length)
{
  for(list<EDGE>::iterator it = m_adjList->begin(); it != m_adjList->end(); it++){
    if (it->startVert == start && it->endVert == end){
      if (it->weight == length)
        return true;
      else
        return false;
    }//if
    
  }//
  
  return false;
}

int CGraph::CalcShortestPath(int start, int end)
{
  int m_id;
  
  //First thing we initialize the known set
  //vector<CGraphNode>::iterator nd_it;
  for(int i = 0; i < m_nodeVect.size(); i++){
    
    m_nodeVect[i].m_known = false;
    m_nodeVect[i].m_dist = INFINITY;
    m_nodeVect[i].m_path = NOT_A_VERTEX;
  }
  
  if(start >= 0 && start < m_nodeVect.size())
    m_nodeVect[start].m_dist = 0 ; // THE ORIGIN source itself
  //count++;
  
  //queue<int> tempQueue;
  for(int ii=0; ii<m_size; ii++){
    m_id = SmallestUnknownVertex(); //m_id =? start
    m_nodeVect[m_id].m_known = true; //the starting origin OR next one to analyze
    
    if(end < m_nodeVect.size() && m_nodeVect[end].m_known)
      return (int)m_nodeVect[end].m_dist;
    //count++;
    
    //out.push_back(m_id);

    for(list<EDGE>::iterator it = m_adjList->begin(); it != m_adjList->end(); it++)
    {
      
      /* Success case */


      if (m_id == it->startVert){
        if(m_nodeVect[it->endVert].m_dist > m_nodeVect[m_id].m_dist+it->weight){
          m_nodeVect[it->endVert].m_dist = m_nodeVect[m_id].m_dist + it->weight;
          m_nodeVect[it->endVert].m_path = m_id;
          //nodeList.push_back(it->endVert);
        }//if
      }//
    }//for itr it
  }//for ii
  
  /* Reverse traversal of nodes from destination to origin,
     comparing the smallest m_dist and enqueueing the value of that node
   */
  
  return (int)m_nodeVect[end].m_dist;
}

int CGraph::GetEdge(int start, int end)
{
  for(list<EDGE>::iterator ait = m_adjList->begin(); ait != m_adjList->end(); ait++)
  {
    if(start == ait->startVert && end == ait->endVert)
      return ait->weight;
  }
  
//FIXME
  cout << "Problem finding edge in CGraph::GetEdge(). Returning -1." << endl;
  return -1;
}// GetEdge()

void CGraph::Dijkstras(int startVert)
{
  //Dijkstras are in CalcShortestPath()
}

int CGraph::SmallestUnknownVertex()
{
  long minval = INFINITY;
  int minindex = -1;
  for(int i=0; i < m_size; i++){
    if(m_nodeVect[i].m_known == false && m_nodeVect[i].m_dist < minval)
    {
      minval = m_nodeVect[i].m_dist;
      minindex = i;
    }
    if (minval == 0)
      return minindex;
  }
  return minindex;
}


int CGraph::GetSize()
{
  return m_size;
}// GetSize()

