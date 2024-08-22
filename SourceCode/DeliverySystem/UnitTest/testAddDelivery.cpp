

#include <iostream>
#include "pch.h"
#include "CppUnitTest.h"
#include "shipmentTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace ShipmentSystemTest
{

	TEST_CLASS(addDelivery_BlackBoxTestCase)
	{
	public:

		//TFB001 - Black Box Test - Normal data

		TEST_METHOD(TFB001_BlackBoxTest_NormalData)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			struct Shipment shipment1 = { 100, 5, { 1,1 } };
			int result = addDelivery(trucks, &baseMap, &shipment1);
			Assert::IsTrue(result == 1);
		}

		//TFB002 - Black Box Test - No truck is available

		TEST_METHOD(TFB002_BlackBoxTest_NoTruckAvailable)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			trucks[0].currentWeight = 1200;
			trucks[1].currentWeight = 1200;
			trucks[2].currentWeight = 1200;
			struct Shipment shipment1 = { 100, 5, { 1,1 } };
			int result = addDelivery(trucks, &baseMap, &shipment1);
			Assert::IsTrue(result == -1);
		}

		//TFB003 - Black Box Test - No truck reach destination

		TEST_METHOD(TFB003_BlackBoxTest_NoTruckReachDestination)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			struct Shipment shipment1 = { 100, 5, { 23,24 } };  //No truck can reach the destination

			int result = addDelivery(trucks, &baseMap, &shipment1);
			Assert::IsTrue(result == -2);
		}

		//TFB004 - Black Box Test - Negative number

		TEST_METHOD(TFB004_BlackBoxTest_NegativeNumber)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),-500,-500},{'G',getGreenRoute(),-500,-500},{'Y',getYellowRoute(),-500,-500} };
			struct Shipment shipment1 = { -500, -500, { 1,1 } };
			int result = addDelivery(trucks, &baseMap, &shipment1);
			Assert::IsTrue(result == -3);
		}

		//TFB005 - Black Box Test - Equal to INT_MIN

		TEST_METHOD(TFB005_BlackBoxTest_EqualToINT_MIN)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),INT_MIN,INT_MIN},{'G',getGreenRoute(),INT_MIN,INT_MIN},{'Y',getYellowRoute(),INT_MIN,INT_MIN} };
			struct Shipment shipment1 = { INT_MIN, INT_MIN, { 1,1 } };
			int result = addDelivery(trucks, &baseMap, &shipment1);
			Assert::IsTrue(result == -3);
		}

		//TFB006 - Black Box Test - Less than INT_MIN

		TEST_METHOD(TFB006_BlackBoxTest_LessThanINT_MIN)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),INT_MIN - 1,INT_MIN - 1},{'G',getGreenRoute(),INT_MIN - 1,INT_MIN - 1},{'Y',getYellowRoute(),INT_MIN - 1,INT_MIN - 1} };
			struct Shipment shipment1 = { INT_MIN - 1, INT_MIN - 1, { 1,1 } };
			int result = addDelivery(trucks, &baseMap, &shipment1);
			Assert::IsTrue(result == -3);
		}

		//TFB007 - Black Box Test - Larger than INT_MIN

		TEST_METHOD(TFB007_BlackBoxTest_LargerThanINT_MIN)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),INT_MIN + 1,INT_MIN + 1},{'G',getGreenRoute(),INT_MIN + 1,INT_MIN + 1},{'Y',getYellowRoute(),INT_MIN + 1,INT_MIN + 1} };
			struct Shipment shipment1 = { INT_MIN + 1, INT_MIN + 1, { 1,1 } };
			int result = addDelivery(trucks, &baseMap, &shipment1);
			Assert::IsTrue(result == -3);
		}

		//TFB008 - Black Box Test - Equal to INT_MAX

		TEST_METHOD(TFB008_BlackBoxTest_EqualToINT_MAX)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),INT_MAX,INT_MAX},{'G',getGreenRoute(),INT_MAX,INT_MAX},{'Y',getYellowRoute(),INT_MAX,INT_MAX} };
			struct Shipment shipment1 = { INT_MAX, INT_MAX, { 1,1 } };
			int result = addDelivery(trucks, &baseMap, &shipment1);
			Assert::IsTrue(result == -3);
		}

		//TFB009 - Black Box Test - Larger than INT_MAX

		TEST_METHOD(TFB009_BlackBoxTest_LargerThanINT_MAX)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),INT_MAX + 1,INT_MAX + 1},{'G',getGreenRoute(),INT_MAX + 1,INT_MAX + 1},{'Y',getYellowRoute(),INT_MAX + 1,INT_MAX + 1} };
			struct Shipment shipment1 = { INT_MAX + 1, INT_MAX + 1, { 1,1 } };
			int result = addDelivery(trucks, &baseMap, &shipment1);
			Assert::IsTrue(result == -3);
		}

		//TFB010 - Black Box Test - Less than INT_MAX

		TEST_METHOD(TFB010_BlackBoxTest_LessThanINT_MAX)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),INT_MAX - 1,INT_MAX - 1},{'G',getGreenRoute(),INT_MAX - 1,INT_MAX - 1},{'Y',getYellowRoute(),INT_MAX - 1,INT_MAX - 1} };
			struct Shipment shipment1 = { INT_MAX - 1, INT_MAX - 1, { 1,1 } };
			int result = addDelivery(trucks, &baseMap, &shipment1);
			Assert::IsTrue(result == -3);
		}

	};

	//==White box Test Cases ===========================================

	TEST_CLASS(addDelivery_WhiteBoxTestCase)
	{
	public:

		//TFB011 - White Box Test - Array of Truck is NULL value

		TEST_METHOD(TFB011_WhiteBoxTest_TruckIsNull)
		{
			struct Map baseMap = populateMap();
			struct Shipment shipment1 = { 100, 5, { 1,1 } };
			int result = addDelivery(NULL, &baseMap, &shipment1);
			Assert::IsTrue(result == -3);
		}

		//TFB012 - White Box Test - Map is NULL value

		TEST_METHOD(TFB012_WhiteBoxTest_MapIsNull)
		{
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			struct Shipment shipment1 = { 100, 5, { 1,1 } };
			int result = addDelivery(trucks, NULL, &shipment1);
			Assert::IsTrue(result == -3);
		}

		//TFB013 - White Box Test - Shipment is NULL value

		TEST_METHOD(TFB013_WhiteBoxTest_ShipmentIsNull)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			int result = addDelivery(trucks, &baseMap, NULL);
			Assert::IsTrue(result == -3);
		}

		//TFB014 - White Box Test - Map size is smaller than 1 x 1

		TEST_METHOD(TFB014_WhiteBoxTest_MapIsSmallerThan1x1)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			struct Shipment shipment1 = { 100, 5, { 1,1 } };
			baseMap.numRows = 0;
			baseMap.numCols = 0;
			int result = addDelivery(trucks, &baseMap, &shipment1);
			Assert::IsTrue(result == -3);
		}

		//TFB015 - White Box Test - Map size is equal to 1x1

		TEST_METHOD(TFB015_WhiteBoxTest_MapIsEqualTo1x1)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			struct Shipment shipment1 = { 100, 5, { 1,1 } };
			baseMap.numRows = 1;
			baseMap.numCols = 1;
			int result = addDelivery(trucks, &baseMap, &shipment1);
			Assert::IsTrue(result == -3);
		}

		//TFB016 - White Box Test - Rows of map is larger than MAP_ROWS

		TEST_METHOD(TFB016_WhiteBoxTest_MapRowIsLargerThanMAP_ROWS)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			struct Shipment shipment1 = { 100, 5, { 1,1 } };
			baseMap.numRows = MAP_ROWS + 1;
			int result = addDelivery(trucks, &baseMap, &shipment1);
			Assert::IsTrue(result == -3);
		}

		//TFB017 - White Box Test - Columns of map is larger than MAP_COLS

		TEST_METHOD(TFB017_WhiteBoxTest_MapColIsLargerThanMAP_COLS)
		{
			struct Map baseMap = populateMap();
			struct Truck trucks[NUM_TRUCK] = { {'B',getBlueRoute(),0,0},{'G',getGreenRoute(),0,0},{'Y',getYellowRoute(),0,0} };
			struct Shipment shipment1 = { 100, 5, { 1,1 } };
			baseMap.numCols = MAP_COLS + 1;
			int result = addDelivery(trucks, &baseMap, &shipment1);
			Assert::IsTrue(result == -3);
		}

	};
}
