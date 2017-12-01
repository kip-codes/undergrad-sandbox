//#pragma once

#ifndef TAXI_H
#define TAXI_H

#include <list>
#include <iostream>
#include <string>

using namespace std;

class CGraph;

class CTaxi
{
public:
	CTaxi(void);
	~CTaxi(void);

	//access functions
	void SetLocation(int v);
	int GetLocation();
	bool IsAvailable();
	void SetAvailable(bool b);

    void SetPickup(int d);
    int GetPickup();
  
	void SetDropoff(int d);
    int GetDropoff();
  
    void SetDistLeft(int distance);
    int GetFirstRoute();
  
	//causes the taxi to calculate (and store) its route
	void SetRoute(CGraph * graph, int dest);
    void GetRoute(CGraph * graph, int dest);
    void PrintRoute();

	//update the position of the taxi
	void MoveTimeStep(int dt, CGraph * graph, int taxiIndex);
  
    string taxiNames[5] = {"RED","BLUE","GREEN","YELLOW","PINK"};


private:
	//current location
	int m_location;

	//true if the taxi does not have a passenger
	bool m_bAvailable;

	//must save this to calculate the route from the pickup to the drop off
    int m_pickup;
    int m_dropoff;

	//route to take to destination
	list <int> m_route;
	int m_distLeftOnEdge;

};

#endif
