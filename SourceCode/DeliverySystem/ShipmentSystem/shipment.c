

#include <stdio.h>
#include "mapping.h"
#include "shipment.h"
#include "truck.h"

int addDelivery(struct Truck* arr, const struct Map* m, const struct Shipment* s)
{
	if (arr == NULL || m == NULL || s == NULL || m->numCols > MAP_COLS || m->numRows > MAP_ROWS || m->numCols <= 1 || m->numRows <= 1) {
		return -3;
	}
	int result = 1;
	for (int i = 0; i < NUM_TRUCK; i++) {
		if (arr[i].currentWeight < 0 || arr[i].currentWeight > MAX_WEIGHT || arr[i].currentVolume < 0 || arr[i].currentVolume > MAX_VOLUME) {
			result = -3;
		}
	}
	if (m->numCols <= MAP_COLS && m->numRows <= MAP_ROWS && checkShipmentWeight(s->weight) == 1 && checkShipmentVolume(s->volume) == 1 && result == 1) {
		int allTruckIsFull = 1;
		int truckSpaceResult[NUM_TRUCK] = { 0 };
		int truckBestRouteResult[NUM_TRUCK] = { 0 };
		struct Route truckBestRoute[NUM_TRUCK] = { 0 };

		for (int i = 0; i < NUM_TRUCK; i++) {
			truckBestRoute[i] = findBestRoute(&arr[i].truckRoute, &s->destination, m);
		}

		int status = assignTruck(arr, truckBestRoute, s);
		if (status == -2) {
			result = -2;
		}
		else if (status == -1) {
			result = -1;
		}
		else {
			result = 1;
		}
	}
	else {
		result = -3;
	}
	return result;
}

int checkInput(int* row, int* col, const double weight, const double volume, const char* location, const struct Map* m) {
	int result = 1;
	if (location == NULL || m == NULL) {
		return -3;
	}

	if (m->numCols <= 1 || m->numRows <= 1 || m->numRows > MAP_ROWS || m->numCols > MAP_COLS) {
		return -3;
	}


	if (weight == 0 && volume == 0 && location[0] == 'x') {
		printf("Thanks for shipping with Seneca!\n");
		result = 0;
	}
	else if (checkShipmentWeight(weight) == 0) {
		printf("Invalid weight (must be 1-1200 Kg.)\n");
		result = -1;
	}
	else if (checkShipmentVolume(volume) == 0) {
		printf("Invalid size\n");
		result = -2;
	}
	else {
		if (strlen(location) != 2 && strlen(location) != 3 && volume == -1) {
			result = -2;
		}
		else if (strlen(location) == 2) {
			if (isdigit(location[0])) {
				if (location[1] >= 'A' && location[1] < MAP_ROWS + 'A') {
					*row = location[0] - '1' < 0 ? 0 : location[0] - '1';
					*col = location[1] - 'A';
					if (m->squares[*row][*col] != 1) {
						printf("Invalid destination\n");
						result = -3;
					}
				}
				else {
					printf("Invalid destination\n");
					result = -3;
				}
			}
			else {
				printf("Invalid destination\n");
				result = -3;
			}
		}
		else if (strlen(location) == 3) {
			if (isdigit(location[0]) && isdigit(location[1])) {
				if (location[2] >= 'A' && location[2] < MAP_COLS + 'A') {
					*row = (location[0] - '0') * 10 + location[1] - '1' < 0 ? 0 : (location[0] - '0') * 10 + location[1] - '1';
					*col = location[2] - 'A';
					if (m->squares[*row][*col] != 1) {
						printf("Invalid destination\n");
						result = -3;
					}
				}
				else {
					printf("Invalid destination\n");
					result = -3;
				}
			}
			else {
				printf("Invalid destination\n");
				result = -3;
			}
		}
		else {
			printf("Invalid destination\n");
			result = -3;
		}
	}
	return result;
}

int assignTruck(struct Truck* arr, const struct Route* r, const struct Shipment* s)
{
	if (arr == NULL || r == NULL || s == NULL) {
		return -1;
	}
	int result = -1;
	if (checkShipmentWeight(s->weight) == 1 && checkShipmentVolume(s->volume) == 1) {
		int emptyRoute = 1;
		int noSpace = 0;
		double distanceCost[NUM_TRUCK] = { 100,100,100 };
		double tempCost[NUM_TRUCK] = { 100,100,100 };
		int sortList[NUM_TRUCK] = { 0,1,2 };
		int temp;
		for (int i = 0; i < NUM_TRUCK; i++) {
			if (r[i].numPoints > 0) {
				distanceCost[i] = distance(&r[i].points[0], &s->destination);
				tempCost[i] = distanceCost[i];
				emptyRoute = 0;
			}
		}
		if (emptyRoute == 1) {
			printf("Destination cannot be reached and not eligible point to divert from the route.\n");
			return -2;
		}
		for (int i = 0; i < NUM_TRUCK - 1; i++) {
			for (int j = 0; j < NUM_TRUCK - i - 1; j++) {
				if (tempCost[j] > tempCost[j + 1]) {
					temp = sortList[j];
					double tempC = tempCost[j];
					tempCost[j] = tempCost[j + 1];
					sortList[j] = sortList[j + 1];
					tempCost[j + 1] = tempC;
					sortList[j + 1] = temp;
				}
			}
		}
		int index = 100;
		int count = 0;
		int init = 0;
		for (int i = 0; i < NUM_TRUCK - 1; i++) {
			if (distanceCost[sortList[0]] == distanceCost[sortList[i + 1]]) {
				count++;
			}
		}
		if (count == 0) {
			for (int i = 0; i < NUM_TRUCK; i++) {
				if (checkAvailableSpaces(&arr[sortList[i]], s) == 1 && r[sortList[i]].numPoints>0) {
					index = sortList[i];
					break;
				}
			}
		}

		for (int i = 0; i < count; i++) {
			int first = checkAvailableSpaces(&arr[sortList[init]], s);
			int second = checkAvailableSpaces(&arr[sortList[i + 1]], s);
			if (first == 1 && second == 1) {
					int firstUsage = displayPercentageUsage(&arr[sortList[init]]);
					int secondUsage = displayPercentageUsage(&arr[sortList[i+1]]);
					if (firstUsage < secondUsage && init == sortList[i]) {
						index = sortList[i];
						init = sortList[i];
					}
					else if (firstUsage > secondUsage) {
						index = sortList[i+1];
						init = sortList[i+1];
					}
					else if (firstUsage == secondUsage && init == sortList[i]) {
						index = sortList[i];
						init = sortList[i];
					}
			}
			else {
				if (first == 1) {
					index = sortList[i];
					init = sortList[i];
				}
				else if (second == 1) {
					index = sortList[i+1];
					init = sortList[i+1];
				}
			}
		}

		char name[20] = { 0 };
		if (index == 100) {
			printf("Ships tomorrow\n");
			result = -1;
		}
		else
		{
			arr[index].currentWeight += s->weight;
			arr[index].currentVolume += s->volume;

			switch (arr[index].id) {
			case 'B':
				strcpy(name, "BLUE LINE");
				result = 10;
				break;
			case 'G':
				strcpy(name, "GREEN LINE");
				result = 11;
				break;
			case 'Y':
				strcpy(name, "YELLOW LINE");
				result = 12;
				break;
			}
			printf("Ship on %s, ", name);

			if (r[index].numPoints == 2) {
				printf("no diversion\n");
			}
			else {
				printf("divert: ");
				for (int i = 0; i < r[index].numPoints; i++) {
					printf("%d%c", r[index].points[i].row + 1, r[index].points[i].col + 'A');
					if (i < r[index].numPoints - 1) {
						printf(", ");
					}
				}
				printf("\n");
			}
		}

	}
	return result;
}

int checkShipmentVolume(double volume)
{
	int result = 0;
	if (volume == 0.5 || volume == 1 || volume == 5) {
		result = 1;
	}
	return result;
}

int checkShipmentWeight(double weight)
{
	int result = 0;
	if (weight >= 1 && weight <= MAX_WEIGHT) {
		result = 1;
	}
	return result;
}



