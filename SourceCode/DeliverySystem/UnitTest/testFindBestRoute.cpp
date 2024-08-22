

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

	TEST_CLASS(findBestRoute_BlackBoxTestCase)
	{
	public:

		//TFH001 - Black Box Test - Normal data (No Diversion)

		TEST_METHOD(TFH001_BlackBoxTest_NormalDataNoDiversion)
		{

			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { 1,1 };
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{1,0},{1,1} }, 2 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			bool result2 = true;
			for (int i = 0; i < actual.numPoints && result1; i++) {
				if (actual.points[i].row != expect.points[i].row || actual.points[i].col != expect.points[i].col) {
					result2 = false;
					break;
				}
			}
			Assert::IsTrue(result1 && result2);
		}

		//TFH002 - Black Box Test - Normal data (With Diversion)

		TEST_METHOD(TFH002_BlackBoxTest_NormalDataWithDiversion)
		{

			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { 2,4 };
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{4,4},{3,4},{2,4}}, 3 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			bool result2 = true;
			for (int i = 0; i < actual.numPoints && result1; i++) {
				if (actual.points[i].row != expect.points[i].row || actual.points[i].col != expect.points[i].col) {
					result2 = false;
					break;
				}
			}
			Assert::IsTrue(result1 && result2);
		}

		//TFH003 - Black Box Test - Destination is not reach

		TEST_METHOD(TFH003_BlackBoxTest_DestinationIsNotReach)
		{

			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { 23,24 };
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			bool result2 = true;
			for (int i = 0; i < actual.numPoints && result1; i++) {
				if (actual.points[i].row != expect.points[i].row || actual.points[i].col != expect.points[i].col) {
					result2 = false;
					break;
				}
			}
			Assert::IsTrue(result1 && result2);
		}



		//TFH004 - Black Box Test - Negative number

		TEST_METHOD(TFH004_BlackBoxTest_NegativeNumber)
		{

			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { -50,-50 };
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			Assert::IsTrue(result1);  //Empty route due to incorrect data

		}

		//TFH005 - Black Box Test - Less than INT_MIN

		TEST_METHOD(TFH005_BlackBoxTest_EqualToINT_MIN)
		{

			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { INT_MIN,INT_MIN };
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			Assert::IsTrue(result1);  //Empty route due to incorrect data

		}

		//TFH006 - Black Box Test - Equal to INT_MIN

		TEST_METHOD(TFH006_BlackBoxTest_LessThanINT_MIN)
		{

			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { INT_MIN - 1,INT_MIN - 1 };
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			Assert::IsTrue(result1);  //Empty route due to incorrect data 
		}

		//TFH007 - Black Box Test - Larger than INT_MIN

		TEST_METHOD(TFH007_BlackBoxTest_LargerThanINT_MIN)
		{

			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { INT_MIN + 1,INT_MIN + 1 };
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			Assert::IsTrue(result1);  //Empty route due to incorrect data
		}

		//TFH008 - Black Box Test - Less than INT_MAX

		TEST_METHOD(TFH008_BlackBoxTest_EqualToINT_MAX)
		{

			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { INT_MAX,INT_MAX };
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			Assert::IsTrue(result1);  //Empty route due to incorrect data
		}

		//TFH009 - Black Box Test - Equal to INT_MAX

		TEST_METHOD(TFH009_BlackBoxTest_LargerThanINT_MAX)
		{

			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { INT_MAX + 1,INT_MAX + 1 };
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			Assert::IsTrue(result1);  //Empty route due to incorrect data
		}

		//TFH010 - Black Box Test - Larger than INT_MAX

		TEST_METHOD(TFH010_BlackBoxTest_LessThanINT_MAX)
		{

			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { INT_MAX - 1,INT_MAX - 1 };
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			Assert::IsTrue(result1);  //Empty route due to incorrect data
		}

	};

		//==White box Test Cases ===========================================

	TEST_CLASS(findBestRoute_WhiteBoxTestCase)
	{
	public:


		//TFH011 - White Box Test - Route is NULL value

		TEST_METHOD(TFH011_WhiteBoxTest_RouteIsNull)
		{
			struct Map m = populateMap();
			struct Point dest = { 1,1 };
			struct Route actual = findBestRoute(NULL, &dest, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			Assert::IsTrue(result1);
		}

		//TFH012 - White Box Test - Destination is NULL value

		TEST_METHOD(TFH012_WhiteBoxTest_DestinationIsNull)
		{
			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Route actual = findBestRoute(&r, NULL, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			Assert::IsTrue(result1);
		}

		//TFH013 - White Box Test - Destination is not in the map

		TEST_METHOD(TFH013_WhiteBoxTest_DestinationIsNotInMap)
		{
			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { 30,30 };
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			Assert::IsTrue(result1);
		}

		//TFH014 - White Box Test - Map size is smaller than 1 x 1

		TEST_METHOD(TFH014_WhiteBoxTest_MapIsSmallerThan1x1)
		{
			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { 1,1 };
			m.numRows = 0;
			m.numCols = 0;
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			Assert::IsTrue(result1);
		}

		//TFH015 - White Box Test - Map size is equal to 1x1

		TEST_METHOD(TFH015_WhiteBoxTest_MapIsEqualTo1x1)
		{
			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { 1,1 };
			m.numRows = 1;
			m.numCols = 1;
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			Assert::IsTrue(result1);
		}

		//TFH016 - White Box Test - Rows of map is larger than MAP_ROWS

		TEST_METHOD(TFH016_WhiteBoxTest_MapRowIsLargerThanMAP_ROWS)
		{
			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { 1,1 };
			m.numRows = MAP_ROWS + 1;
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			Assert::IsTrue(result1);
		}

		//TFH017 - White Box Test - Columns of map is larger than MAP_COLS

		TEST_METHOD(TFH017_WhiteBoxTest_MapColIsLargerThanMAP_COLS)
		{
			struct Map m = populateMap();
			struct Route r = getBlueRoute();
			struct Point dest = { 1,1 };
			m.numCols = MAP_COLS + 1;
			struct Route actual = findBestRoute(&r, &dest, &m);
			struct Route expect = { {{0,0}}, 0 , BLUE };
			bool result1 = (actual.numPoints == expect.numPoints);
			Assert::IsTrue(result1);
		}

	};
}
