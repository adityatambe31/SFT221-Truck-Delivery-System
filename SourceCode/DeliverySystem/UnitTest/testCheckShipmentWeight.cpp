

#include <iostream>
#include "pch.h"
#include "CppUnitTest.h"
#include "shipmentTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace ShipmentSystemTest
{

	TEST_CLASS(checkShipmentWeight_BlackBoxTestCase)
	{
	public:

		//TFF001 - Black Box Test - Normal data

		TEST_METHOD(TFF001_BlackBoxTest_NormalData)
		{
			double weight = 500;
			int result = checkShipmentWeight(weight);
			Assert::IsTrue(result == 1);

		}

		//TFF002 - Black Box Test - Weight is negative number

		TEST_METHOD(TFF002_BlackBoxTest_WeightIsNegativeNumber)
		{

			double weight = -100;
			int result = checkShipmentWeight(weight);
			Assert::IsTrue(result == 0);

		}

		//TFF003 - Black Box Test - Equal to INT_MIN

		TEST_METHOD(TFF003_BlackBoxTest_EqualToINT_MIN)
		{

			struct Map baseMap = populateMap();
			double weight = INT_MIN;
			int result = checkShipmentWeight(weight);
			Assert::IsTrue(result == 0);

		}

		//TFF004 - Black Box Test - Less than INT_MIN

		TEST_METHOD(TFF004_BlackBoxTest_LessThanINT_MIN)
		{


			struct Map baseMap = populateMap();
			double weight = INT_MIN - 1;
			int result = checkShipmentWeight(weight);
			Assert::IsTrue(result == 0);
		}

		//TFF005 - Black Box Test - Larger than INT_MIN

		TEST_METHOD(TFF005_BlackBoxTest_LargerThanINT_MIN)
		{


			struct Map baseMap = populateMap();
			double weight = INT_MIN + 1;
			int result = checkShipmentWeight(weight);
			Assert::IsTrue(result == 0);
		}

		//TFF006 - Black Box Test - Equal to INT_MAX

		TEST_METHOD(TFF006_BlackBoxTest_EqualToINT_MAX)
		{
			struct Map baseMap = populateMap();
			double weight = INT_MAX;
			int result = checkShipmentWeight(weight);
			Assert::IsTrue(result == 0);
		}

		//TFF007 - Black Box Test - Larger than INT_MAX

		TEST_METHOD(TFF007_BlackBoxTest_LargerThanINT_MAX)
		{

			struct Map baseMap = populateMap();
			double weight = INT_MAX + 1;
			int result = checkShipmentWeight(weight);
			Assert::IsTrue(result == 0);
		}

		//TFF008 - Black Box Test - Less than INT_MAX

		TEST_METHOD(TFF008_BlackBoxTest_LessThanINT_MAX)
		{

			struct Map baseMap = populateMap();
			double weight = INT_MAX - 1;
			int result = checkShipmentWeight(weight);
			Assert::IsTrue(result == 0);
		}

		//TFF009 - Black Box Test - Less than weight max size

		TEST_METHOD(TFF009_BlackBoxTest_LessThanWeightMaxSize)
		{

			struct Map baseMap = populateMap();
			double weight = 1199;
			int result = checkShipmentWeight(weight);
			Assert::IsTrue(result == 1);

		}

		//TFF010 - Black Box Test - Equal to weight max size

		TEST_METHOD(TFF010_BlackBoxTest_EqualToWeightMaxSize)
		{

			struct Map baseMap = populateMap();
			double weight = 1200;
			int result = checkShipmentWeight(weight);
			Assert::IsTrue(result == 1);

		}

		//TFF011 - Black Box Test - Larger than weight max size

		TEST_METHOD(TFF011_BlackBoxTest_LargerThanWeightMaxSize)
		{


			struct Map baseMap = populateMap();
			double weight = 1201;
			int result = checkShipmentWeight(weight);
			Assert::IsTrue(result == 0);

		}

		//TFF012 - Black Box Test - Less than weight min size

		TEST_METHOD(TFF012_BlackBoxTest_LessThanWeightMinSize)
		{


			struct Map baseMap = populateMap();
			double weight = 0;
			int result = checkShipmentWeight(weight);
			Assert::IsTrue(result == 0);

		}

		//TFF013 - Black Box Test - Larger than weight min size

		TEST_METHOD(TFF013_BlackBoxTest_LargerThanWeightMinSize)
		{

			struct Map baseMap = populateMap();
			double weight = 2;
			int result = checkShipmentWeight(weight);
			Assert::IsTrue(result == 1);
		}

		//TFF014 - Black Box Test - Equal to weight min size

		TEST_METHOD(TFF014_BlackBoxTest_EqualToWeightMinSize)
		{


			struct Map baseMap = populateMap();
			double weight = 1;
			int result = checkShipmentWeight(weight);
			Assert::IsTrue(result == 1);
		}

	};
	
	//==White box Test Cases ===========================================

	TEST_CLASS(checkShipmentWeight_WhiteBoxTestCase)
	{
	public:

		//TFF015 - White Box Test - Weight is NULL value

		TEST_METHOD(TFF015_WhiteBoxTest_WeightIsNull)
		{
			int result = checkShipmentWeight(NULL);
			Assert::IsTrue(result == 0);
		}

		//TFF016 - White Box Test - Weight is flating number with extra zero

		TEST_METHOD(TFF016_WhiteBoxTest_WeightIsFloatingNumberWithManyZero)
		{
			int result = checkShipmentWeight(13.5000);
			Assert::IsTrue(result == 1);
		}

		//TFF017 - White Box Test - Weight is correct data in floting number format

		TEST_METHOD(TFF017_WhiteBoxTest_WeightIsCorrectFloatingNumber)
		{
			int result = checkShipmentWeight(1.0);
			Assert::IsTrue(result == 1);
		}


	};
}