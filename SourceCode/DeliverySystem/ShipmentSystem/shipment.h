#pragma once
#ifndef SHIPMENT_H
#define SHIPMENT_H

#include "mapping.h"
#include "truck.h"

struct Shipment {
	double weight;               // This would be used to hold the weight of the shipment
	double volume;               // This would be used to hold the volume size of the shipment
	struct Point destination;    // This would be used to hold the destination of the shipment
};

/**
* Adding shipment into system, it calls functions to check the available trucks, find the best route of the trucks, and then assign a truck for delivery and update truck's usage
* @param arr - the array of all the trucks for shipment delivery
* @param m - the map of the city
* @param s - the shipment for delivery
* @returns - 1 if successful assigned a truck for shipment or -1 if all truck are not available or -2 if cannot assign truck for delivery or -3 if data incorrect
*/
int addDelivery(struct Truck* arr, const struct Map* m, const struct Shipment* s);

/**
* User input Validation for checking the shipment information
* @param row - the updated row of the destination in the map if the shipment information is valid
* @param col - the updated column of the destination in the map if the shipment information is valid
* @param weight - the weight of the shipment
* @param volume - the volume size of the shipment
* @param location - the destination in the map
* @param m - the map of the city
* @returns - 1 if shipment information is valid or 0 if user entered "0 0 x" for exit the program or -1 if weight is not valid or -2 if volume is not valid or -3 if destination is not valid
*/
int checkInput(int* row, int* col, const double weight, const double volume, const char* location, const struct Map* m);

/**
* Assign a truck for delivery and update the truck usage information
* @param arr - the array of all the trucks for shipment delivery
* @param r - the best routes of all the trucks
* @param s - the shipment for delivery
* @returns - 10 if assigned to Blue Truck or 11 if assigned to Green Truck or 12 if assigned to Yellow Truck or -1 if destination cannot be reached and not eligible point to divert from the route
*/
int assignTruck(struct Truck* arr, const struct Route* r, const struct Shipment* s);

/**
* Check the shipment volume size if it matches the correct sizes: 0.5, 1, 5
* @param volume - the volume size of the shipment
* @returns - 1 if matched the correct size or 0 if not matched the correct size
*/
int checkShipmentVolume(double volume);

/**
* Check the shipment weight if it is 1-1200 (kg)
* @param weight - the weight of the shipment
* @returns - 1 if matched the correct shipment weigth or 0 if not matched the correct shipment weight
*/
int checkShipmentWeight(double weight);


#endif