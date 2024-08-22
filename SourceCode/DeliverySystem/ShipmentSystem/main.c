
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "truck.h"
#include "shipment.h"

int main(void)
{
	struct Map baseMap = populateMap();
	struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
	int numInput = 0;
	int result = -99;
	int row = -1;
	int col = -1;

	printf("=================\n");
	printf("Seneca College Deliveries\n");
	printf("=================\n");
	do {
		double weight = -1;
		double volume = -1;
		char location[4] = { 0 };
		printf("Enter shipment weight, box size and destination (0 0 x to stop): ");
		numInput = scanf("%lf %lf %s", &weight, &volume, &location);
		while (getchar() != '\n');
		result = checkInput(&row, &col, weight, volume, location, &baseMap);
		if (result == 0) {
			break;
		}
		else if (result == 1) {
			struct Shipment shipmentOrder = { weight, volume, { row,col } };
			addDelivery(trucks, &baseMap, &shipmentOrder);
		}
		result = -99;
	} while (1);
	return 0;
}