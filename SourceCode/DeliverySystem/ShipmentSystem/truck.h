#pragma once
#ifndef TRUCK_H
#define TRUCK_H

#define MAX_WEIGHT 1200 
#define MAX_VOLUME 50
#define NUM_TRUCK 3

#include "mapping.h"

struct Truck {
	char id;					// This would be used to hold the truck ID (B = Blue Line, Y= Yellow Line, G = Green Line)
	struct Route truckRoute;	// This would be used to hold the route of truck
	double currentWeight;		// This would be used to hold the current weight of the truck
	double currentVolume;		// This would be used to hold the current volume of the truck
};


/**
* Display and find out the percentage of current usage of the truck
* @param t - the truck for usage calculation
* @returns - the value of the percentage of usage of the truck or -1 if truck's information is invalid
*/
double displayPercentageUsage(struct Truck* t);

/**
* Find out the best route of the truck based on the map and destination
* @param r - the route of the truck
* @param dest - the destination for shipment delivery
* @param m - the map of the city
* @returns - The route of shortest distance from the start location of the route to the destination or empty route if destination cannot reached
*/
struct Route findBestRoute(const struct Route* r, const struct Point* dest, const struct Map* m);

/**
* Check and calculate the current available spaces of the truck
* @param t - the truck for finding the available space
* @param s - the shipment for delivery
* @returns - 1 if the truck has available spaces for the shipment or 0 if no available spaces of the truck for the shipment
*/
int checkAvailableSpaces(struct Truck* t, const struct Shipment* s);




#endif