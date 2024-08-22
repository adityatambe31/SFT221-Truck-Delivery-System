#include <stdio.h>
#include "truck.h"
#include "shipment.h"
#include "mapping.h"


double displayPercentageUsage(struct Truck* t)
{
    if (t == NULL) {
        return -1;
    }

    double result;
    if (t->currentWeight < 0 || t->currentWeight > MAX_WEIGHT || t->currentVolume < 0 || t->currentVolume > MAX_VOLUME) {
        result = -1;
    }
    else {
        result = ((t->currentWeight / MAX_WEIGHT) + (t->currentVolume / MAX_VOLUME)) / 2 * 100;
    }
    return result;
}

struct Route findBestRoute(const struct Route* r, const struct Point* dest, const struct Map* m)
{
    struct Route temp = { {0,0}, 0, 0 };
    struct Route result = { {0,0}, 0, 0 };
    if (dest == NULL || r == NULL) {
        return result;
    }
    int row = (int)dest->row;
    int col = (int)dest->col;
    if (m->numRows <= MAP_ROWS && m->numCols <= MAP_COLS && dest->row < m->numRows && dest->col < m->numCols && r->numPoints > 0
        && dest->row >= 0 && dest->row <= MAP_ROWS && dest->col >= 0 && dest->col <= MAP_COLS && m->squares[row][col] == 1) {
        int best = 100;
        double min_distance = 99999;
        int min_index = 99;
        double current = 0;
        for (int i = 0; i < r->numPoints; i++) {
            current = distance(&r->points[i], dest);
            if (current < min_distance) {
                min_distance = current;
                min_index = i;
            }
        }
        result = shortestPath(m, r->points[min_index], *dest);
    }
    return result;
}

int checkAvailableSpaces(struct Truck* t, const struct Shipment* s)
{
    double availableWeight = 0;
    double availableVolume = 0;
    if (t == NULL || s == NULL) {
        return -1;
    }

    int result = 0;
    if (t->currentWeight < 0 || t->currentWeight > MAX_WEIGHT || t->currentVolume < 0 || t->currentVolume > MAX_VOLUME ||
        checkShipmentWeight(s->weight) == 0 || checkShipmentVolume(s->volume) == 0) {
        result = -1;
    }
    else {
        availableWeight = MAX_WEIGHT - t->currentWeight;
        availableVolume = MAX_VOLUME - t->currentVolume;

        if (s->weight <= availableWeight && s->volume <= availableVolume) {
            result = 1;
        }
    }
    
    return result;
}