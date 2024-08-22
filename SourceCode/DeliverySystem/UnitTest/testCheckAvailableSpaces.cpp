

#include <iostream>
#include "pch.h"
#include "CppUnitTest.h"
#include "shipmentTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace ShipmentSystemTest
{

	TEST_CLASS(checkAvailableSpaces_BlackBoxTestCase)
	{
	public:

		//TFD001 - Black Box Test - Normal data

		TEST_METHOD(TFD001_BlackBoxTest_NormalData)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = 100;
			shipment1.volume = 1;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == 1);
		}

		//TFD002 - Black Box Test - Shipment's weight and volume are negative number

		TEST_METHOD(TFD002_BlackBoxTest_ShipmentWeightAndVolumeAreNegativeNumber)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = -100;
			shipment1.volume = -100;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == -1);
		}

		//TFD003 - Black Box Test - Shipment's weight and volume are less than INT_MIN

		TEST_METHOD(TFD003_BlackBoxTest_ShipmentWeightAndVolumeAreLessThanINT_MIN)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = INT_MIN - 1;
			shipment1.volume = INT_MIN - 1;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == -1);
		}

		//TFD004 - Black Box Test - Shipment's weight and volume are equal to INT_MIN

		TEST_METHOD(TFD004_BlackBoxTest_ShipmentWeightAndVolumeAreEqualToINT_MIN)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = INT_MIN;
			shipment1.volume = INT_MIN;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == -1);
		}

		//TFD005 - Black Box Test - Shipment's weight and volume are larger than INT_MIN

		TEST_METHOD(TFD005_BlackBoxTest_ShipmentWeightAndVolumeAreLargerThanINT_MIN)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = INT_MIN + 1;
			shipment1.volume = INT_MIN + 1;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == -1);
		}

		//TFD006 - Black Box Test - Shipment's weight and volume are larger than INT_MAX

		TEST_METHOD(TFD006_BlackBoxTest_ShipmentWeightAndVolumeAreLargerThanINT_MAX)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = INT_MAX + 1;
			shipment1.volume = INT_MAX + 1;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == -1);
		}

		//TFD007 - Black Box Test - Shipment's weight and volume are less than INT_MAX

		TEST_METHOD(TFD007_BlackBoxTest_ShipmentWeightAndVolumeAreLessThanINT_MAX)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = INT_MAX - 1;
			shipment1.volume = INT_MAX - 1;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == -1);
		}

		//TFD008 - Black Box Test - Shipment's weight and volume are equal to INT_MAX

		TEST_METHOD(TFD008_BlackBoxTest_ShipmentWeightAndVolumeAreEqualToINT_MAX)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = INT_MAX;
			shipment1.volume = INT_MAX;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == -1);
		}

		//TFD009 - Black Box Test - Shipment's weight and volume are 0

		TEST_METHOD(TFD009_BlackBoxTest_ShipmentWeightAndVolumeAreZero)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = 0;
			shipment1.volume = 0;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == -1);
		}

		//TFD010 - Black Box Test - Shipment volume is correct size 1 which is 0.5

		TEST_METHOD(TFD010_BlackBoxTest_ShipmentVolumeIsCorrectSize1)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = 100;
			shipment1.volume = 0.5;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == 1);
		}

		//TFD011 - Black Box Test - Shipment volume is correct size 2 which is 1

		TEST_METHOD(TFD011_BlackBoxTest_ShipmentVolumeIsCorrectSize2)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = 100;
			shipment1.volume = 1;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == 1);
		}

		//TFD012 - Black Box Test - Shipment volume Is correct size 3 which is 5

		TEST_METHOD(TFD012_BlackBoxTest_ShipmentVolumeIsCorrectSize3)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = 100;
			shipment1.volume = 5;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == 1);
		}

		//TFD013 - Black Box Test - Shipment volume is not correct size

		TEST_METHOD(TFD013_BlackBoxTest_ShipmentVolumeIsNotCorrectSize)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = 100;
			shipment1.volume = 10;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == -1);
		}

		//TFD014 - Black Box Test - Shipment weight is equal to MAX_WEIGHT

		TEST_METHOD(TFD014_BlackBoxTest_ShipmentWeightIsEqualtoMAX_WEIGHT)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = 1200;
			shipment1.volume = 1;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == 1);
		}

		//TFD015 - Black Box Test - Shipment weight is larger than MAX_WEIGHT

		TEST_METHOD(TFD015_BlackBoxTest_ShipmentWeightIsLargerthanMAX_WEIGHT)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;
			shipment1.weight = 1600;
			shipment1.volume = 1;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == -1);
		}

		//TFD016 - Black Box Test - Shipment weight is larger than Truck's available spaces

		TEST_METHOD(TFD016_BlackBoxTest_ShipmentWeightIsLargerthanTruckAvailableSpaces)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 500;
			truck1.currentVolume = 0;
			shipment1.weight = 1000;
			shipment1.volume = 1;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == 0);
		}

		//TFD017 - Black Box Test - Shipment volume is larger than truck's available spaces

		TEST_METHOD(TFD017_BlackBoxTest_ShipmentVolumeIsLargerthanTruckAvailableSpaces)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = 0;
			truck1.currentVolume = 49;
			shipment1.weight = 100;
			shipment1.volume = 5;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == 0);
		}
	};

	//==White box Test Cases ===========================================

	TEST_CLASS(checkAvailableSpaces_WhiteBoxTestCase)
	{
	public:


		//TFD018 - White Box Test - truck is NULL value

		TEST_METHOD(TFD018_WhiteBoxTest_TruckIsNull)
		{
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			shipment1.weight = 100;
			shipment1.volume = 1;

			int actual = checkAvailableSpaces(NULL, &shipment1);
			Assert::IsTrue(actual == -1);
		}

		//TFD019 - White Box Test - shipment is NULL value

		TEST_METHOD(TFD019_WhiteBoxTest_ShipmentIsNull)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			truck1.currentWeight = 0;
			truck1.currentVolume = 0;

			int actual = checkAvailableSpaces(&truck1, NULL);
			Assert::IsTrue(actual == -1);
		}

		//TFD020 - White Box Test - Used weight of truck is less than 0

		TEST_METHOD(TFD020_WhiteBoxTest_TrackUsedWeightIsLessThanZero)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = -1;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == -1);
		}

		//TFD021 - White Box Test - Used volume size of truck is less than 0

		TEST_METHOD(TFD021_WhiteBoxTest_TrackUsedVolumeIsLessThanZero)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentVolume = -1;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == -1);
		}

		//TFD022 - White Box Test - Used weight of truck is larger than MAX_WEIGHT

		TEST_METHOD(TFD022_WhiteBoxTest_TrackUsedWeightIsLargerThanMAX_WEIGHT)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			truck1.currentWeight = MAX_WEIGHT + 1;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == -1);
		}

		//TFD023 - White Box Test - Used volume size of truck is larger than MAX_VOLUME

		TEST_METHOD(TFD023_WhiteBoxTest_TrackUsedVolumeIslargerThanMAX_VOLUME)
		{
			struct Truck truck1 = { 'B', getBlueRoute(), 0, 0 };
			struct Shipment shipment1 = { 100, 1, { 1,1 } };
			shipment1.volume = MAX_VOLUME + 1;

			int actual = checkAvailableSpaces(&truck1, &shipment1);
			Assert::IsTrue(actual == -1);
		}


	};
}
