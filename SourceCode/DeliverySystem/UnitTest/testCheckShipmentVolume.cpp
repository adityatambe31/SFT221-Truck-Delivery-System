

#include <iostream>
#include "pch.h"
#include "CppUnitTest.h"
#include "shipmentTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace ShipmentSystemTest
{

	TEST_CLASS(checkShipmentVolume_BlackBoxTestCase)
	{
	public:

		//TFE001 - Black Box Test - Volume is correct size 1 which is 0.5

		TEST_METHOD(TFE001_BlackBoxTest_VolumeCorrectSize1)
		{

			double volume = 0.5;
			int result = checkShipmentVolume(volume);
			Assert::IsTrue(result == 1);

		}

		//TFE002 - Black Box Test - Volume is correct size 2 which is 1

		TEST_METHOD(TFE002_BlackBoxTest_VolumeCorrectSize2)
		{

			double volume = 1;
			int result = checkShipmentVolume(volume);
			Assert::IsTrue(result == 1);

		}

		//TFE003 - Black Box Test - Volume is correct size 3 which is 5

		TEST_METHOD(TFE003_BlackBoxTest_VolumeCorrectSize3)
		{

			double volume = 5;
			int result = checkShipmentVolume(volume);
			Assert::IsTrue(result == 1);

		}

		//TFE004 - Black Box Test - Volume is not correct size

		TEST_METHOD(TFE004_BlackBoxTest_VolumeNotCorrectSize)
		{

			double volume = 10;
			int result = checkShipmentVolume(volume);
			Assert::IsTrue(result == 0);

		}


		//TFE005 - Black Box Test - Negative number

		TEST_METHOD(TFE005_BlackBoxTest_NegativeNumber)
		{

			double volume = -500;
			int result = checkShipmentVolume(volume);
			Assert::IsTrue(result == 0);
		}

		//TFE006 - Black Box Test - Equal to INT_MIN

		TEST_METHOD(TFE006_BlackBoxTest_EqualToINT_MIN)
		{

			double volume = INT_MIN;
			int result = checkShipmentVolume(volume);
			Assert::IsTrue(result == 0);

		}

		//TFE007 - Black Box Test - Less than INT_MIN

		TEST_METHOD(TFE007_BlackBoxTest_LessThanINT_MIN)
		{

			double volume = INT_MIN - 1;
			int result = checkShipmentVolume(volume);
			Assert::IsTrue(result == 0);
		}

		//TFE008 - Black Box Test - Larger than INT_MIN

		TEST_METHOD(TFE008_BlackBoxTest_LargerThanINT_MIN)
		{

			double volume = INT_MIN + 1;
			int result = checkShipmentVolume(volume);
			Assert::IsTrue(result == 0);
		}

		//TFE009 - Black Box Test - Equal to INT_MAX

		TEST_METHOD(TFE009_BlackBoxTest_EqualToINT_MAX)
		{

			double volume = INT_MAX;
			int result = checkShipmentVolume(volume);
			Assert::IsTrue(result == 0);
		}

		//TFE010 - Black Box Test - Larger than INT_MAX

		TEST_METHOD(TFE010_BlackBoxTest_LargerThanINT_MAX)
		{

			double volume = INT_MAX + 1;
			int result = checkShipmentVolume(volume);
			Assert::IsTrue(result == 0);
		}

		//TFE011 - Black Box Test - Less than INT_MAX

		TEST_METHOD(TFE011_BlackBoxTest_LessThanINT_MAX)
		{

			double volume = INT_MAX - 1;
			int result = checkShipmentVolume(volume);
			Assert::IsTrue(result == 0);
		}
	};

	//==White box Test Cases ===========================================

	TEST_CLASS(checkShipmentVolume_WhiteBoxTestCase)
	{
	public:


		//TFE012 - White Box Test - Volume is NULL value

		TEST_METHOD(TFE012_WhiteBoxTest_VolumeIsNull)
		{
			int result = checkShipmentVolume(NULL);
			Assert::IsTrue(result == 0);
		}

		//TFE013 - White Box Test - Volume with extra zero numbers

		TEST_METHOD(TFE013_WhiteBoxTest_VolumeHasManyZero)
		{
			int result = checkShipmentVolume(0.50000);
			Assert::IsTrue(result == 1);
		}

		//TFE014 - White Box Test - Volume is correct size in floating number format

		TEST_METHOD(TFE014_WhiteBoxTest_VolumeIsCorrectSzieAndFlotingNumberFormat)
		{
			int result = checkShipmentVolume(1.0);
			Assert::IsTrue(result == 1);
		}


	};
}