#include "Dispatcher.h"
#include "Graph.h"
#include "Taxi.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <queue>
#include <assert.h>

using namespace std;

//FIXME
//CGraph MainMap;
/* Redundant with m_roadmap member of CDispatcher
 */

CDispatcher::CDispatcher(void)
{
  for(int i = 0; i < NUM_TAXIS; i++){
    m_taxis[i].SetAvailable(true);
    m_taxis[i].SetDropoff(-1);
    m_taxis[i].SetPickup(-1);
  }// for i
  
}

CDispatcher::~CDispatcher(void)
{
}

void CDispatcher::UpdateTaxis(int dt)
{
  for (int i = 0; i < NUM_TAXIS; i++)
    if (m_taxis[i].GetDropoff() >= 0)
      m_taxis[i].MoveTimeStep(dt, m_roadMap, i);
}

void CDispatcher::ProcessCall(string buf)
{
  //extract input from buffer
  istringstream tBuf(buf);
  
  char command;
  int start_vert, end_vert, taxiID = 0;
  
  tBuf >> command; //Ignore the m
  
  tBuf >> start_vert >> end_vert;
  
  /* STEP 1: Determine which available taxi is closest to client */

  int minDist = INFINITY;
  
  for (int i = 0; i < NUM_TAXIS; i++)
    if (m_taxis[i].GetDropoff() < 0){
      int tdist = m_roadMap->CalcShortestPath(m_taxis[i].GetLocation(), start_vert);
      if (tdist < minDist){
        minDist = tdist;
        taxiID = i;
      }// if
    }// if the taxi is able to take on a job,
  /* END STEP 1 */
  
  /* STEP 2: Assign taxi to client */
  m_taxis[taxiID].SetPickup(start_vert);
  m_taxis[taxiID].SetDropoff(end_vert);
  
  /* STEP 3: Call CalcShortestPath() */
  m_taxis[taxiID].SetRoute(m_roadMap, start_vert);
  m_taxis[taxiID].SetDistLeft(m_roadMap->GetEdge(m_taxis[taxiID].GetLocation(), m_taxis[taxiID].GetFirstRoute()));
  
  /* STEP 4: Print out which taxi is being dispatched, the destination, and the route. */
  cout << "Dispatching taxi " << taxiNames[taxiID]
    << " to location " << start_vert
    <<  " with destination " << end_vert << endl;

  m_taxis[taxiID].PrintRoute();

}

void CDispatcher::SetMap(string buf)
{
  istringstream tBuf(buf);
  int num_verts, start_vert, end_vert, weight;

  char command;

  tBuf >> command; //Ignore the m

  tBuf >> num_verts;
  
  m_roadMap = new CGraph(num_verts);
  
  //debug
  //cout << "Number of nodes = " << num_verts;

  while(!tBuf.eof())
  {
      tBuf >> start_vert;
      tBuf >> end_vert;
      tBuf >> weight;
  //MainMap.AddEdge(start_vert, end_vert, weight);
    m_roadMap->AddEdge(start_vert, end_vert, weight);
  }
}

void CDispatcher::SetTaxiLocations(string buf)
{
    istringstream tBuf(buf);

    //dump command from buffer
    char command, taxi;
    tBuf>>command;

    int location;

    //position all the taxis
    while(!tBuf.eof())
    {
        tBuf>>taxi;
        tBuf>>location;
        int index;
        switch(taxi)
        {
            case 'R':
                index = RED;
                break;
            case 'G':
                index = GREEN;
                break;
            case 'B':
                index = BLUE;
                break;
            case 'Y':
                index = YELLOW;
                break;
            case 'P':
                index = PINK;
                break;
            default:
                assert(false);
          }
      
      //FIXME
          //m_index[index].setLocation(location);
      m_taxis[index].SetLocation(location);
    }
}



