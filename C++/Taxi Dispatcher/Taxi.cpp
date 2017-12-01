#include "Taxi.h"
#include "Graph.h"
#include <vector>

#include <iostream>
using namespace std;

CTaxi::CTaxi(void)
{

}

CTaxi::~CTaxi(void)
{
}

//access functions

void CTaxi:: SetLocation(int v)
{
    m_location = v;

}

int CTaxi::GetLocation()
{
    return m_location;

}

bool CTaxi::IsAvailable()
{
    return m_bAvailable;
}

void CTaxi::SetAvailable(bool b)
{
    m_bAvailable = b;
}

void CTaxi::SetDropoff(int d)
{
    m_dropoff = d;
}

int CTaxi::GetDropoff()
{
  return m_dropoff;
}// GetDropoff()

void CTaxi::SetRoute(CGraph* graph, int dest)
{
  int start;
  //Get current location
  start = GetLocation();
  
  graph->CalcShortestPath(start, dest);
  
  //Assumption: m_path to destination has been populated.
  GetRoute(graph, dest); //populate m_route
  
}// SetRoute()


// Populate m_route == everything up to (and including) destination, without origin.
void CTaxi::GetRoute(CGraph* graph, int dest)
{
  int k = dest;
  //cout << "k = " << k << endl;
  m_route.push_back(k);
  
  for (int i = 0; i < graph->GetSize(); i++){
    
    /* BASE CONDITION */
    if (graph->m_nodeVect[k].m_path == GetLocation()) //k is origin
      return;
    
    int mr = graph->m_nodeVect[k].m_path;
    //cout << "mr for Node " << i << " is " << mr << endl;
    m_route.push_front(mr);
    k = mr;
    
  }//for i
  
}// GetRoute()

void CTaxi::MoveTimeStep(int dt, CGraph *graph, int taxiIndex)
{
  //Assumption: m_distLeftOnEdge is populated by ProcessCall.
  m_distLeftOnEdge -= dt;
  //cout << "taxiIndex " << taxiIndex << " " << m_distLeftOnEdge << endl;
  
  //assuming that we're at proper taxi
  if(m_distLeftOnEdge == 0) //implies we've reached node on edge
  {
    list<int>::iterator it = m_route.begin();
    m_location = *it;
    m_route.pop_front();//makes m_location the endVert
    
    if(!m_route.empty())
    {
      list<int>::iterator it = m_route.begin();
      
      //finds value that ends up being our endVert
      
      m_distLeftOnEdge = graph->GetEdge(m_location, *it); //returns weight of next edge.
      //cout << m_distLeftOnEdge << endl;
    } // if empty
  }// if m_distleftonedge
  
  
  //Condition 1: Picking up a passenger:
  if(IsAvailable() && GetLocation() == m_pickup){
    cout << "Taxi " << taxiNames[taxiIndex] << " picking up passenger at "
      << m_pickup << "." << endl;
    SetAvailable(false);
    /* FX CALL */
    SetRoute(graph, GetDropoff());
    SetDistLeft(graph->GetEdge(GetLocation(), GetFirstRoute()));
    PrintRoute();
    return;
  }
  
  //Condition 2:Dropping off a passenger:
  if(!IsAvailable() && GetLocation() == m_dropoff){
    cout << "Taxi " << taxiNames[taxiIndex] << " dropping off passenger at "
      << m_dropoff << "." << endl;
    SetAvailable(true);
    SetDropoff(-1); // job completed
    return;
  }
  
}// MoveTimeStep()

void CTaxi::PrintRoute()
{
  //Print route to client
  cout << "Planned route: " << GetLocation();
  for (list<int>::iterator it = m_route.begin(); it != m_route.end(); it++){
    cout << " " << *it;
  }// for iterator
  
  cout << endl;
}// PrintRoute()

void CTaxi::SetDistLeft(int distance)
{
  m_distLeftOnEdge = distance;
}// SetDistLeft()

int CTaxi::GetFirstRoute()
{
  list<int>::iterator it = m_route.begin();
  return *it;
}// GetFirstRoute()

void CTaxi::SetPickup(int d)
{
  m_pickup = d;
}// SetPickup()


int CTaxi::GetPickup()
{
  return m_pickup;
}

