
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include "pch.h"
#include "CppUnitTest.h"
#include "shipmentTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace ShipmentSystemTest
{

	TEST_CLASS(Integration_TestCase)
	{
	public:

		//TFI001 - Integration Test - Input Validation - Weight Integration Test (Less than MAX_WEIGHT)

		TEST_METHOD(TFI001_IntegrationTest_checkInput_checkShipmentVolume_WeightIsCorrect)
		{
			struct Map m = populateMap();
			double weight = MAX_WEIGHT - 1;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;

			int result1 = checkInput(&row, &col, weight, volume, location, &m);
			int result2 = checkShipmentWeight(weight);

			Assert::IsTrue(result1 == 1 && result2 == 1);
		}

		//TFI002 - Integration Test - Input Validation - Weight Integration Test (Larger than MAX_WEIGHT)

		TEST_METHOD(TFI002_IntegrationTest_checkInput_checkShipmentVolume_WeightIsNotCorrect)
		{
			struct Map m = populateMap();
			double weight = MAX_WEIGHT + 1;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;

			int result1 = checkInput(&row, &col, weight, volume, location, &m);
			int result2 = checkShipmentWeight(weight);

			Assert::IsTrue(result1 == -1 && result2 == 0);
		}

		//TFI003 - Integration Test - Input Validation - Volume Integration Test (Size = 0.5)

		TEST_METHOD(TFI003_IntegrationTest_checkInput_checkShipmentVolume_VolumeIsCorrectSize1)
		{
			struct Map m = populateMap();
			double weight = 500;
			double volume = 0.5;
			char location[] = "2B";
			int row = -1;
			int col = -1;

			int result1 = checkInput(&row, &col, weight, volume, location, &m);
			int result2 = checkShipmentVolume(volume);

			Assert::IsTrue(result1 == 1 && result2 == 1);
		}

		//TFI004 - Integration Test - Input Validation - Volume Integration Test (Size = 1)

		TEST_METHOD(TFI004_IntegrationTest_checkInput_checkShipmentVolume_VolumeIsCorrectSize2)
		{
			struct Map m = populateMap();
			double weight = 500;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;

			int result1 = checkInput(&row, &col, weight, volume, location, &m);
			int result2 = checkShipmentVolume(volume);

			Assert::IsTrue(result1 == 1 && result2 == 1);
		}

		//TFI005 - Integration Test - Input Validation - Volume Integration Test (Size = 5)

		TEST_METHOD(TFI005_IntegrationTest_checkInput_checkShipmentVolume_VolumeIsCorrectSize3)
		{
			struct Map m = populateMap();
			double weight = 500;
			double volume = 5;
			char location[] = "2B";
			int row = -1;
			int col = -1;

			int result1 = checkInput(&row, &col, weight, volume, location, &m);
			int result2 = checkShipmentVolume(volume);

			Assert::IsTrue(result1 == 1 && result2 == 1);
		}

		//TFI006 - Integration Test - Input Validation - Volume Integration Test (Size = 10)

		TEST_METHOD(TFI006_IntegrationTest_checkInput_checkShipmentVolume_VolumeIsNotCorrectSize)
		{
			struct Map m = populateMap();
			double weight = 500;
			double volume = 10;
			char location[] = "2B";
			int row = -1;
			int col = -1;

			int result1 = checkInput(&row, &col, weight, volume, location, &m);
			int result2 = checkShipmentVolume(volume);

			Assert::IsTrue(result1 == -2 && result2 == 0);
		}

		//TFI007 - Integration Test - Best Route Integration Test (Blue Truck is the Best)

		TEST_METHOD(TFI007_IntegrationTest_addDelivery_findBestRoute_Integration)
		{
			struct Map m = populateMap();
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };

			double weight = 500;
			double volume = 1;
			int row = 1;
			int col = 1;
			struct Shipment s = { weight, volume, { row,col } };
			int result1 = addDelivery(arr, &m, &s);
			struct Route result2 = findBestRoute(&arr[0].truckRoute, &s.destination, &m);
			struct Route expect = { {{1,0},{1,1} }, 2 , BLUE };
			Assert::IsTrue(result1 == 1 && result2.numPoints == expect.numPoints);
		}

		//TFI008 - Integration Test - Best Route Integration Test (Green Truck is the Best)

		TEST_METHOD(TFI008_IntegrationTest_addDelivery_findBestRoute_Integration2)
		{
			struct Map m = populateMap();
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };

			double weight = 500;
			double volume = 1;
			int row = 1;
			int col = 1;
			struct Shipment s = { weight, volume, { row,col } };
			int result1 = addDelivery(arr, &m, &s);
			struct Route result2 = findBestRoute(&arr[1].truckRoute, &s.destination, &m);
			struct Route expect = { {{1,0},{1,1} }, 2 , GREEN };
			Assert::IsTrue(result1 == 1 && result2.numPoints == expect.numPoints);
		}

		//TFI009 - Integration Test - Assign Truck Integration Test (Blue truck is the best)

		TEST_METHOD(TFI009_IntegrationTest_addDelivery_assignTruck_Integration)
		{
			struct Map m = populateMap();
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			struct Route r[NUM_TRUCK] = { { {{0,1},{0,2},{0,3},{0,4}},4,BLUE }, { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN }, { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW } };
			double weight = 500;
			double volume = 1;
			int row = 1;
			int col = 1;
			struct Shipment s = { weight, volume, { row,col } };
			int result1 = addDelivery(arr, &m, &s);
			int result2 = assignTruck(arr, r, &s);
			Assert::IsTrue(result1 == 1 && result2 == 10);
		}

		//TFI010 - Integration Test - Truck Usage Integration Test

		TEST_METHOD(TFI010_IntegrationTest_checkAvailable_displayPercentageUsage_Integration)
		{
			struct Map m = populateMap();
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			double weight = 500;
			double volume = 1;
			int row = 1;
			int col = 1;
			struct Shipment s = { weight, volume, { row,col } };

			int result1 = checkAvailableSpaces(&arr[0], &s);
			double result2 = displayPercentageUsage(&arr[0]);
			Assert::IsTrue(result1 == 1 && result2 == 0);
		}

		//TFI011 - Integration Test - Truck Usage Integration Test (No available spaces)

		TEST_METHOD(TFI011_IntegrationTest_checkAvailable_displayPercentageUsage_Integration2)
		{
			struct Map m = populateMap();
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),1200,50},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			double weight = 500;
			double volume = 1;
			int row = 1;
			int col = 1;
			struct Shipment s = { weight, volume, { row,col } };

			int result1 = checkAvailableSpaces(&arr[0], &s);
			double result2 = displayPercentageUsage(&arr[0]);
			Assert::IsTrue(result1 == 0 && result2 == 100);
		}

		//TFI012 - Integration Test - Truck Available Spaces Integration Test 

		TEST_METHOD(TFI012_IntegrationTest_assignTruck_checkAvailableSpaces_Integration)
		{
			struct Map m = populateMap();
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			double weight = 500;
			double volume = 1;
			int row = 1;
			int col = 1;
			struct Shipment s = { weight, volume, { row,col } };

			int result1 = assignTruck(arr, &arr[0].truckRoute, &s);
			int result2 = checkAvailableSpaces(&arr[0], &s);
			Assert::IsTrue(result1 == 10 && result2 == 1);
		}

		//TFI013 - Integration Test - Truck Available Spaces Integration Test (No available spaces)

		TEST_METHOD(TFI013_IntegrationTest_assignTruck_checkAvailableSpaces_Integration2)
		{
			struct Map m = populateMap();
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),1200,50},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			struct Route r[NUM_TRUCK] = { { {{0,1},{0,2},{0,3},{0,4}},4,BLUE },{ {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN },{ {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW } };
			double weight = 500;
			double volume = 1;
			int row = 1;
			int col = 1;
			struct Shipment s = { weight, volume, { row,col } };

			int result1 = assignTruck(arr, r, &s);
			int result2 = checkAvailableSpaces(&arr[0], &s);
			Assert::IsTrue(result1 == 11 && result2 == 0);
		}

		//TFI014 - Integration Test - Assign Truck based on Usage Integration Test

		TEST_METHOD(TFI014_IntegrationTest_assignTruck_displayPercentageUsage_Integration)
		{
			struct Map m = populateMap();
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),600,25},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			double weight = 500;
			double volume = 1;
			int row = 1;
			int col = 1;
			struct Shipment s = { weight, volume, { row,col } };

			double result1 = displayPercentageUsage(&arr[0]);
			int result2 = assignTruck(arr, &arr[0].truckRoute, &s);

			Assert::IsTrue(result1 == 50 && result2 == 10);
		}

		//TFI015 - Integration Test - Assign Truck based on Usage Integration Test 2 (Green Truck is the best)

		TEST_METHOD(TFI015_IntegrationTest_assignTruck_displayPercentageUsage_Integration2)
		{
			struct Map m = populateMap();
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),1200,50},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			struct Route r[NUM_TRUCK] = { { {{0,1},{0,2},{0,3},{0,4}},4,BLUE },{ {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN },{ {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW } };
			double weight = 500;
			double volume = 1;
			int row = 1;
			int col = 1;
			struct Shipment s = { weight, volume, { row,col } };

			double result1 = displayPercentageUsage(&arr[0]);
			int result2 = assignTruck(arr, r, &s);

			Assert::IsTrue(result1 == 100 && result2 == 11);
		}

		//TFI016 - Integration Test - Normal data (No Diversion)
		TEST_METHOD(TFI016_IntegrationTest_NormalDataNoDiversion)
		{
			struct Map m = populateMap();
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			struct Route r[NUM_TRUCK] = { { {{0,1},{0,2},{0,3},{0,4}},4,BLUE },{ {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN },{ {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW } };
			double weight = 500;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;

			int result1 = checkInput(&row, &col, weight, volume, location, &m);

			struct Point dest = { row,col };
			struct Shipment s = { weight, volume, { row,col } };

			int result2 = checkShipmentWeight(weight);
			int result3 = checkShipmentVolume(volume);
			int result4 = assignTruck(arr, r, &s);
			struct Route result5 = findBestRoute(&arr[0].truckRoute, &dest, &m);
			int result6 = checkAvailableSpaces(&arr[0], &s);
			double result7 = displayPercentageUsage(&arr[0]);
			int result8 = addDelivery(arr, &m, &s);

			struct Route expectRoute = { {{1,0},{1,1} }, 2 , BLUE };
			double expectPercentageUsage = ((arr[0].currentWeight / 1200) + (arr[0].currentVolume / 50)) / 2 * 100;

			Assert::IsTrue(result1 == 1 && row == 1 && col == 1 &&
				result2 == 1 && result3 == 1 && result4 == 10 &&
				result5.numPoints == expectRoute.numPoints &&
				result6 == 1 && result7 == expectPercentageUsage && result8 == 1);

		}

		//TFI017 - Integration Test - Normal data (With Diversion)

		TEST_METHOD(TFI017_IntegrationTest_NormalDataWithDiversion)
		{
			struct Map m = populateMap();
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			struct Route r[NUM_TRUCK] = { { {{0,1},{0,2},{0,3},{0,4}},4,BLUE },{ {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN },{ {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW } };
			double weight = 500;
			double volume = 1;
			char location[] = "3E";
			int row = -1;
			int col = -1;

			int result1 = checkInput(&row, &col, weight, volume, location, &m);

			struct Point dest = { row,col };
			struct Shipment s = { weight, volume, { row,col } };

			int result2 = checkShipmentWeight(weight);
			int result3 = checkShipmentVolume(volume);
			int result4 = assignTruck(arr, r, &s);
			struct Route result5 = findBestRoute(&arr[0].truckRoute, &dest, &m);
			int result6 = checkAvailableSpaces(&arr[0], &s);
			double result7 = displayPercentageUsage(&arr[0]);
			int result8 = addDelivery(arr, &m, &s);

			struct Route expectRoute = { {{4,4},{3,4},{2,4}}, 3 , BLUE };
			double expectPercentageUsage = ((arr[0].currentWeight / 1200) + (arr[0].currentVolume / 50)) / 2 * 100;

			Assert::IsTrue(result1 == 1 && row == 2 && col == 4 &&
				result2 == 1 && result3 == 1 && result4 == 10 &&
				result5.numPoints == expectRoute.numPoints &&
				result6 == 1 && result7 == expectPercentageUsage && result8 == 1);

		}

		//TFI018 - Integration Test - Destination is not reach

		TEST_METHOD(TFI018_IntegrationTest_DestinationIsNotReach)
		{
			struct Map m = populateMap();
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			struct Route r[NUM_TRUCK] = { { {{0,1},{0,2},{0,3},{0,4}},4,BLUE },{ {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN },{ {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW } };
			double weight = 500;
			double volume = 1;
			char location[] = "24Y";
			int row = -1;
			int col = -1;

			int result1 = checkInput(&row, &col, weight, volume, location, &m);

			struct Point dest = { row,col };
			struct Shipment s = { weight, volume, { row,col } };

			int result2 = checkShipmentWeight(weight);
			int result3 = checkShipmentVolume(volume);
			int result4 = assignTruck(arr, r, &s);
			struct Route result5 = findBestRoute(&arr[0].truckRoute, &dest, &m);
			int result6 = checkAvailableSpaces(&arr[0], &s);
			double result7 = displayPercentageUsage(&arr[0]);
			int result8 = addDelivery(arr, &m, &s);

			struct Route expectRoute = { {{0,0}}, 0 , BLUE };
			double expectPercentageUsage = ((arr[0].currentWeight / 1200) + (arr[0].currentVolume / 50)) / 2 * 100;

			Assert::IsTrue(result1 == 1 && row == 23 && col == 24 &&
				result2 == 1 && result3 == 1 && result4 == 10 &&
				result5.numPoints == expectRoute.numPoints &&
				result6 == 1 && result7 == expectPercentageUsage && result8 == -2);

		}

	};
}