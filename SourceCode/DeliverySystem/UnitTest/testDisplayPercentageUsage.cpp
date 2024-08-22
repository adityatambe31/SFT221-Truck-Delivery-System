

#include <iostream>
#include "pch.h"
#include "CppUnitTest.h"
#include "shipmentTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace ShipmentSystemTest
{

	TEST_CLASS(displayPercentageUsage_BlackBoxTestCase)
	{
	public:

		//TFG001 - Black Box Test - Normal usage

		TEST_METHOD(TFG001_BlackBoxTest_NormalUsage)
		{

			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = 500;
			truck1.currentVolume = 20;
			double actual = displayPercentageUsage(&truck1);
			double expect = ((truck1.currentWeight / 1200) + (truck1.currentVolume / 50)) / 2 * 100;
			Assert::IsTrue(expect == actual);

		}

		//TFG002 - Black Box Test - Negative number

		TEST_METHOD(TFG002_BlackBoxTest_NegativeNumber)
		{

			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = -500;
			truck1.currentVolume = -500;
			double actual = displayPercentageUsage(&truck1);
			Assert::IsTrue(actual == -1);

		}

		//TFG003 - Black Box Test - Less than INT_MIN

		TEST_METHOD(TFG003_BlackBoxTest_LessThanINT_MIN)
		{

			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = INT_MIN - 1;
			truck1.currentVolume = INT_MIN - 1;
			double actual = displayPercentageUsage(&truck1);
			Assert::IsTrue(actual == -1);

		}

		//TFG004 - Black Box Test - Equal to INT_MIN

		TEST_METHOD(TFG004_BlackBoxTest_EqualToINT_MIN)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = INT_MIN;
			truck1.currentVolume = INT_MIN;
			double actual = displayPercentageUsage(&truck1);
			Assert::IsTrue(actual == -1);

		}


		//TFG005 - Black Box Test - Larger than INT_MIN

		TEST_METHOD(TFG005_BlackBoxTest_LargerThanINT_MIN)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = INT_MIN + 1;
			truck1.currentVolume = INT_MIN + 1;
			double actual = displayPercentageUsage(&truck1);
			Assert::IsTrue(actual == -1);

		}

		//TFG006 - Black Box Test - Less than INT_MAX

		TEST_METHOD(TFG006_BlackBoxTest_LessThanINT_MAX)
		{

			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = INT_MAX - 1;
			truck1.currentVolume = INT_MAX - 1;
			double actual = displayPercentageUsage(&truck1);
			Assert::IsTrue(actual == -1);

		}

		//TFG007 - Black Box Test - Equal to INT_MAX

		TEST_METHOD(TFG007_BlackBoxTest_EqualToINT_MAX)
		{

			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = INT_MAX;
			truck1.currentVolume = INT_MAX;
			double actual = displayPercentageUsage(&truck1);
			Assert::IsTrue(actual == -1);

		}

		//TFG008 - Black Box Test - Larger than INT_MAX

		TEST_METHOD(TFG008_BlackBoxTest_LargerThanINT_MAX)
		{

			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = INT_MAX + 1;
			truck1.currentVolume = INT_MAX + 1;
			double actual = displayPercentageUsage(&truck1);
			Assert::IsTrue(actual == -1);

		}

		//TFG009 - Black Box Test - Zero usage

		TEST_METHOD(TFG009_BlackBoxTest_ZeroUsage)
		{

			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			double actual = displayPercentageUsage(&truck1);
			Assert::IsTrue(actual == 0);

		}

		//TFG010 - Black Box Test - Full usage

		TEST_METHOD(TFG010_BlackBoxTest_FullUsage)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = 1200;
			truck1.currentVolume = 50;
			double actual = displayPercentageUsage(&truck1);
			Assert::IsTrue(actual == 100);

		}

		//TFG011 - Black Box Test - Full usage of weight only

		TEST_METHOD(TFG011_BlackBoxTest_FullUsageOfWeightOnly)
		{

			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = 1200;
			truck1.currentVolume = 0;
			double actual = displayPercentageUsage(&truck1);
			Assert::IsTrue(actual == 50);

		}

		//TFG012 - Black Box Test - Full usage of volume only

		TEST_METHOD(TFG012_BlackBoxTest_FullUsageOfVolumeOnly)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = 0;
			truck1.currentVolume = 50;
			double actual = displayPercentageUsage(&truck1);
			Assert::IsTrue(actual == 50);

		}
	};

	//==White box Test Cases ===========================================

	TEST_CLASS(displayPercentageUsage_WhiteBoxTestCase)
	{
	public:

		//TFG013 - White Box Test - truck is NULL value

		TEST_METHOD(TFG013_WhiteBoxTest_TruckIsNull)
		{
			Assert::IsTrue(displayPercentageUsage(NULL) == -1);

		}

		//TFG014 - White Box Test - Used weight of truck is less than 0

		TEST_METHOD(TFG014_WhiteBoxTest_TruckUsedWeightIsLessThanZero)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = -1;
			Assert::IsTrue(displayPercentageUsage(&truck1) == -1);
		}

		//TFG015 - White Box Test - Used volume size of truck is less than 0

		TEST_METHOD(TFG015_WhiteBoxTest_TruckUsedVolumeIsLessThanZero)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentVolume = -1;
			Assert::IsTrue(displayPercentageUsage(&truck1) == -1);
		}

		//TFG016 - White Box Test - Used weight of truck is larger than MAX_WEIGHT

		TEST_METHOD(TFG016_WhiteBoxTest_TruckUsedWeightIsLargerThanMAX_WEIGHT)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = MAX_WEIGHT + 1;
			Assert::IsTrue(displayPercentageUsage(&truck1) == -1);
		}

		//TFG017 - White Box Test - Used volume size of truck is larger than MAX_VOLUME

		TEST_METHOD(TFG017_WhiteBoxTest_TruckUsedWeightIsLargerThanMAX_VOLUME)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentVolume = MAX_VOLUME + 1;
			Assert::IsTrue(displayPercentageUsage(&truck1) == -1);
		}

	};
}
