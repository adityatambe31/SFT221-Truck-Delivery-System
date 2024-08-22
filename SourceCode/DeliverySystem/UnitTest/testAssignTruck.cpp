

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

	TEST_CLASS(assignTruck_BlackBoxTestCase)
	{
	public:

		//TFC001 - Black Box Test - Normal data if Truck 1 route is the best

		TEST_METHOD(TFC001_BlackBoxTest_NormalDataIfTruck1RouteIsBest)
		{
			struct Shipment s = { 100, 5, { 0,4 } };
			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };

			double lastWeight = arr[0].currentWeight;
			double lastVolume = arr[0].currentVolume;
			r[0] = { {{0,1},{0,2},{0,3},{0,4}},4,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW };
			bool result1 = (assignTruck(arr, r, &s) == 10); //10 is selected first truck
			bool result2 = (arr[0].currentWeight == lastWeight + s.weight);
			bool result3 = (arr[0].currentVolume == lastVolume + s.volume);
			Assert::IsTrue(result1 && result2 && result3);
		}

		//TFC002 - Black Box Test - Normal data if Truck 2 route is the best

		TEST_METHOD(TFC002_BlackBoxTest_NormalDataIfTruck2RouteIsBest)
		{

			struct Shipment s = { 100, 5, { 0,4 } };
			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };

			double lastWeight = arr[1].currentWeight;
			double lastVolume = arr[1].currentVolume;
			r[0] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,BLUE };
			r[1] = { {{0,1},{0,2},{0,3},{0,4}},4,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW };
			bool result1 = (assignTruck(arr, r, &s) == 11); //11 is selected second truck
			bool result2 = (arr[1].currentWeight == lastWeight + s.weight);
			bool result3 = (arr[1].currentVolume == lastVolume + s.volume);
			Assert::IsTrue(result1 && result2 && result3);
		}

		//TFC003 - Black Box Test - Normal data if Truck 3 route is the best

		TEST_METHOD(TFC003_BlackBoxTest_NormalDataIfTruck3RouteIsBest)
		{

			struct Shipment s = { 100, 5, { 0,4 } };
			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };

			double lastWeight = arr[2].currentWeight;
			double lastVolume = arr[2].currentVolume;
			r[0] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,1},{0,2},{0,3},{0,4}},4,YELLOW };
			bool result1 = (assignTruck(arr, r, &s) == 12); //12 is selected third truck
			bool result2 = (arr[2].currentWeight == lastWeight + s.weight);
			bool result3 = (arr[2].currentVolume == lastVolume + s.volume);
			Assert::IsTrue(result1 && result2 && result3);
		}

		//TFC004 - Black Box Test - No truck's route is the best

		TEST_METHOD(TFC004_BlackBoxTest_NormalDataIfNoTruckRouteIsBest)
		{

			struct Shipment s = { 100, 5, { 0,4 } };
			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };

			r[0] = { {},0,BLUE };
			r[1] = { {},0,GREEN };
			r[2] = { {},0,YELLOW };
			bool result1 = (assignTruck(arr, r, &s) == -2); //-2 if destination cannot be reached and not eligible point to divert from the route.
			Assert::IsTrue(result1);
		}

		//TFC005 - Black Box Test - All truck are same route distance and same spaces usage

		TEST_METHOD(TFC005_BlackBoxTest_NormalDataIfAllTruckSameRouteAndSameSpaces)
		{

			struct Shipment s = { 100, 5, { 0,4 } };
			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };

			double lastWeight = arr[0].currentWeight;
			double lastVolume = arr[0].currentVolume;
			r[0] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW };
			bool result1 = (assignTruck(arr, r, &s) == 10);
			bool result2 = (arr[0].currentWeight == lastWeight + s.weight);
			bool result3 = (arr[0].currentVolume == lastVolume + s.volume);
			Assert::IsTrue(result1 && result2 && result3);
		}

		//TFC006 - Black Box Test - Truck 1 has more spaces

		TEST_METHOD(TFC006_BlackBoxTest_NormalDataIfTruck1MoreSpaces)
		{

			struct Shipment s = { 100, 5, { 0,4 } };
			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),100,10},{'Y',getYellowRoute(),200,20} };

			double lastWeight = arr[0].currentWeight;
			double lastVolume = arr[0].currentVolume;
			r[0] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW };
			bool result1 = (assignTruck(arr, r, &s) == 10); //10 is selected first truck
			bool result2 = (arr[0].currentWeight == lastWeight + s.weight);
			bool result3 = (arr[0].currentVolume == lastVolume + s.volume);
			Assert::IsTrue(result1 && result2 && result3);
		}

		//TFC007 - Black Box Test - Truck 2 has more spaces

		TEST_METHOD(TFC007_BlackBoxTest_NormalDataIfTruck2MoreSpaces)
		{

			struct Shipment s = { 100, 5, { 0,4 } };
			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),100,10},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),200,20} };

			double lastWeight = arr[1].currentWeight;
			double lastVolume = arr[1].currentVolume;
			r[0] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW };
			bool result1 = (assignTruck(arr, r, &s) == 11); //11 is selected second truck
			bool result2 = (arr[1].currentWeight == lastWeight + s.weight);
			bool result3 = (arr[1].currentVolume == lastVolume + s.volume);
			Assert::IsTrue(result1 && result2 && result3);
		}

		//TFC008 - Black Box Test - Truck 3 has more spaces

		TEST_METHOD(TFC008_BlackBoxTest_NormalDataIfTruck3MoreSpaces)
		{

			struct Shipment s = { 100, 5, { 0,4 } };
			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),100,10},{'G',getGreenRoute(),200,20},{'Y',getYellowRoute(),0,0} };

			double lastWeight = arr[2].currentWeight;
			double lastVolume = arr[2].currentVolume;
			r[0] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW };
			bool result1 = (assignTruck(arr, r, &s) == 12);
			bool result2 = (arr[2].currentWeight == lastWeight + s.weight);
			bool result3 = (arr[2].currentVolume == lastVolume + s.volume);
			Assert::IsTrue(result1 && result2 && result3);
		}

		//TFC009 - Black Box Test - 2 arr route are the same but truck 3 has more spaces

		TEST_METHOD(TFC009_BlackBoxTest_NormalDataIf2TruckRouteAreSameButTruck3MoreSpaces)
		{

			struct Shipment s = { 100, 5, { 0,4 } };
			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),100,10},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),50,5} };

			double lastWeight = arr[2].currentWeight;
			double lastVolume = arr[2].currentVolume;
			r[0] = { {{0,1},{0,2},{0,3},{0,4}},4,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,1},{0,2},{0,3},{0,4}},4,YELLOW };
			bool result1 = (assignTruck(arr, r, &s) == 12); //12 is selected third truck
			bool result2 = (arr[2].currentWeight == lastWeight + s.weight);
			bool result3 = (arr[2].currentVolume == lastVolume + s.volume);
			Assert::IsTrue(result1 && result2 && result3);
		}

		//TFC010 - Black Box Test - Negative number

		TEST_METHOD(TFC010_BlackBoxTest_WeightIsNegativeNumber)
		{

			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),100,10},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),50,5} };

			double lastWeight = arr[2].currentWeight;
			double lastVolume = arr[2].currentVolume;
			r[0] = { {{0,0},{0,1},{0,2},{0,4}},4,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,4}},4,YELLOW };
			struct Shipment s = { -50, -50, { 0,4 } };
			bool result1 = (assignTruck(arr, r, &s) == -1);  //returned -1
			Assert::IsTrue(result1);

		}

		//TFC011 - Black Box Test - Equal to INT_MIN

		TEST_METHOD(TFC011_BlackBoxTest_EqualToINT_MIN)
		{

			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),100,10},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),50,5} };

			double lastWeight = arr[2].currentWeight;
			double lastVolume = arr[2].currentVolume;
			r[0] = { {{0,0},{0,1},{0,2},{0,4}},4,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,4}},4,YELLOW };
			struct Shipment s = { INT_MIN, INT_MIN, { 0,4 } };
			bool result1 = (assignTruck(arr, r, &s) == -1);  //returned -1
			Assert::IsTrue(result1);
		}

		//TFC012 - Black Box Test - Less than INT_MIN

		TEST_METHOD(TFC012_BlackBoxTest_LessThanINT_MIN)
		{

			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),100,10},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),50,5} };

			double lastWeight = arr[2].currentWeight;
			double lastVolume = arr[2].currentVolume;
			r[0] = { {{0,0},{0,1},{0,2},{0,4}},4,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,4}},4,YELLOW };
			struct Shipment s = { INT_MIN - 1, INT_MIN - 1, { 0,4 } };
			bool result1 = (assignTruck(arr, r, &s) == -1);  //returned -1
			Assert::IsTrue(result1);
		}

		//TFC013 - Black Box Test - Larger than INT_MIN

		TEST_METHOD(TFC013_BlackBoxTest_LargerThanINT_MIN)
		{

			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),100,10},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),50,5} };

			double lastWeight = arr[2].currentWeight;
			double lastVolume = arr[2].currentVolume;
			r[0] = { {{0,0},{0,1},{0,2},{0,4}},4,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,4}},4,YELLOW };
			struct Shipment s = { INT_MIN + 1, INT_MIN + 1, { 0,4 } };
			bool result1 = (assignTruck(arr, r, &s) == -1);  //returned -1
			Assert::IsTrue(result1);
		}

		//TFC014 - Black Box Test - Equal to INT_MAX

		TEST_METHOD(TFC014_BlackBoxTest_EqualToINT_MAX)
		{

			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),100,10},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),50,5} };

			double lastWeight = arr[2].currentWeight;
			double lastVolume = arr[2].currentVolume;
			r[0] = { {{0,0},{0,1},{0,2},{0,4}},4,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,4}},4,YELLOW };
			struct Shipment s = { INT_MAX, INT_MAX, { 0,4 } };
			bool result1 = (assignTruck(arr, r, &s) == -1);  //returned -1
			Assert::IsTrue(result1);
		}

		//TFC015 - Black Box Test - Larger than INT_MAX

		TEST_METHOD(TFC015_BlackBoxTest_LargerThanINT_MAX)
		{

			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),100,10},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),50,5} };

			double lastWeight = arr[2].currentWeight;
			double lastVolume = arr[2].currentVolume;
			r[0] = { {{0,0},{0,1},{0,2},{0,4}},4,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,4}},4,YELLOW };
			struct Shipment s = { INT_MAX + 1, INT_MAX + 1, { 0,4 } };
			bool result1 = (assignTruck(arr, r, &s) == -1);  //returned -1
			Assert::IsTrue(result1);
		}

		//TFC016 - Black Box Test - Less than INT_MAX

		TEST_METHOD(TFC016_BlackBoxTest_LessThanINT_MAX)
		{

			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),100,10},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),50,5} };

			double lastWeight = arr[2].currentWeight;
			double lastVolume = arr[2].currentVolume;
			r[0] = { {{0,0},{0,1},{0,2},{0,4}},4,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,4}},4,YELLOW };
			struct Shipment s = { INT_MAX - 1, INT_MAX - 1, { 0,4 } };
			bool result1 = (assignTruck(arr, r, &s) == -1);  //returned -1
			Assert::IsTrue(result1);
		}
	};

	//==White box Test Cases ===========================================

	TEST_CLASS(assignTruck_WhiteBoxTestCase)
	{
	public:

		//TFC017 - White Box Test - Truck is Null value

		TEST_METHOD(TFC017_WhiteBoxTest_TruckIsNull)
		{
			struct Shipment s = { 100, 5, { 0,4 } };
			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			r[0] = { {{0,0},{0,1},{0,2},{0,4}},4,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW };
			Assert::IsTrue(assignTruck(NULL, r, &s) == -1);

		}

		//TFC018 - White Box Test - Array of best route of 3 arr is NULL value

		TEST_METHOD(TFC018_WhiteBoxTest_RouteIsNull)
		{
			struct Shipment s = { 100, 5, { 0,4 } };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			Assert::IsTrue(assignTruck(arr, NULL, &s) == -1);
		}

		//TFC019 - White Box Test - Shipment data is NULL value

		TEST_METHOD(TFC019_WhiteBoxTest_ShipmentIsNull)
		{
			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			r[0] = { {{0,0},{0,1},{0,2},{0,4}},4,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW };
			Assert::IsTrue(assignTruck(arr, r, NULL) == -1);
		}

		//TFC020 - White Box Test - Shipment's volume size is not correct Size

		TEST_METHOD(TFC020_WhiteBoxTest_ShipmentVolumeIsNotCorrect)
		{
			struct Shipment s = { 100, 10, { 0,4 } };
			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			Assert::IsTrue(assignTruck(arr, r, &s) == -1);
		}

		//TFC021 - White Box Test - Shipment's weight is less than 1

		TEST_METHOD(TFC021_WhiteBoxTest_ShipmentWeightIsLessThan1)
		{
			struct Shipment s = { 0, 5, { 0,4 } };
			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			r[0] = { {{0,0},{0,1},{0,2},{0,4}},4,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW };
			Assert::IsTrue(assignTruck(arr, r, &s) == -1);
		}

		//TFC022 - White Box Test - Shipment's weight is larger than MAX_WEIGHT

		TEST_METHOD(TFC022_WhiteBoxTest_ShipmentWeightIsLargerThanMAX_WEIGHT)
		{
			struct Shipment s = { MAX_WEIGHT + 1, 5, { 0,4 } };
			struct Route r[NUM_TRUCK] = { {{0,0},0,BLUE},{{0,0},0,GREEN},{{0,0},0,YELLOW} };
			struct Truck arr[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			r[0] = { {{0,0},{0,1},{0,2},{0,4}},4,BLUE };
			r[1] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,GREEN };
			r[2] = { {{0,0},{0,1},{0,2},{0,3},{0,4}},5,YELLOW };
			Assert::IsTrue(assignTruck(arr, r, &s) == -1);
		}
	};
}
