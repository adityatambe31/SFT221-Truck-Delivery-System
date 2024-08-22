

#include <iostream>
#include "pch.h"
#include "CppUnitTest.h"
#include "shipmentTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace ShipmentSystemTest
{

	TEST_CLASS(checkInput_BlackBoxTestCase)
	{

	public:

		//TFA001 - Black Box Test - Normal data of weight, volume and destination

		TEST_METHOD(TFA001_BlackBoxTest_NormalData)
		{
			struct Map baseMap = populateMap();
			double weight = 500;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);
			Assert::IsTrue(result == 1 && row == 1 && col == 1);
		}

		//TFA002 - Black Box Test - Normal data for exit

		TEST_METHOD(TFA002_BlackBoxTest_NormalDataForExit)
		{
			struct Map baseMap = populateMap();
			double weight = 0;
			double volume = 0;
			char location[] = "x";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == 0);
		}

		//TFA003 - Black Box Test - Weight is negative number

		TEST_METHOD(TFA003_BlackBoxTest_WeightIsNegativeNumber)
		{
			struct Map baseMap = populateMap();
			double weight = -100;
			double volume = 0;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -1);
		}

		//TFA004 - Black Box Test - Equal to INT_MIN

		TEST_METHOD(TFA004_BlackBoxTest_EqualToINT_MIN)
		{
			struct Map baseMap = populateMap();
			double weight = INT_MIN;
			double volume = INT_MIN;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -1);
		}

		//TFA005 - Black Box Test - Less than INT_MIN

		TEST_METHOD(TFA005_BlackBoxTest_LessThanINT_MIN)
		{
			struct Map baseMap = populateMap();
			double weight = INT_MIN - 1;
			double volume = INT_MIN - 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -1);
		}

		//TFA006 - Black Box Test - Larger than INT_MIN

		TEST_METHOD(TFA006_BlackBoxTest_LargerThanINT_MIN)
		{
			struct Map baseMap = populateMap();
			double weight = INT_MIN + 1;
			double volume = INT_MIN + 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -1);
		}

		//TFA007 - Black Box Test - Equal to INT_MAX

		TEST_METHOD(TFA007_BlackBoxTest_EqualToINT_MAX)
		{
			struct Map baseMap = populateMap();
			double weight = INT_MAX;
			double volume = INT_MAX;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -1);
		}

		//TFA008 - Black Box Test - Larger than INT_MAX

		TEST_METHOD(TFA008_BlackBoxTest_LargerThanINT_MAX)
		{
			struct Map baseMap = populateMap();
			double weight = INT_MAX + 1;
			double volume = INT_MAX + 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -1);
		}

		//TFA009 - Black Box Test - Less than INT_MAX

		TEST_METHOD(TFA009_BlackBoxTest_LessThanINT_MAX)
		{
			struct Map baseMap = populateMap();
			double weight = INT_MAX - 1;
			double volume = INT_MAX - 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -1);
		}

		//TFA010 - Black Box Test - Less than weight's max size

		TEST_METHOD(TFA010_BlackBoxTest_LessThanWeightMaxSize)
		{
			struct Map baseMap = populateMap();
			double weight = 1199;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == 1 && row == 1 && col == 1);
		}

		//TFA011 - Black Box Test - Equal to weight's max size

		TEST_METHOD(TFA011_BlackBoxTest_EqualToWeightMaxSize)
		{
			struct Map baseMap = populateMap();
			double weight = 1200;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == 1 && row == 1 && col == 1);
		}

		//TFA012 - Black Box Test - Larger than weight's max size

		TEST_METHOD(TFA012_BlackBoxTest_LargerThanWeightMaxSize)
		{
			struct Map baseMap = populateMap();
			double weight = 1201;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -1);
		}

		//TFA013 - Black Box Test - Less than weight's min size

		TEST_METHOD(TFA013_BlackBoxTest_LessThanWeightMinSize)
		{
			struct Map baseMap = populateMap();
			double weight = 0;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -1);
		}

		//TFA014 - Black Box Test - Larger than weight's min size

		TEST_METHOD(TFA014_BlackBoxTest_LargerThanWeightMinSize)
		{
			struct Map baseMap = populateMap();
			double weight = 2;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == 1 && row == 1 && col == 1);
		}

		//TFA015 - Black Box Test - Equal to weight's min size

		TEST_METHOD(TFA015_BlackBoxTest_EqualToWeightMinSize)
		{
			struct Map baseMap = populateMap();
			double weight = 1;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == 1 && row == 1 && col == 1);
		}

		//TFA016 - Black Box Test - Volume correct size 1 which is equal to 0.5

		TEST_METHOD(TFA016_BlackBoxTest_VolumeCorrectSize1)
		{
			struct Map baseMap = populateMap();
			double weight = 100;
			double volume = 0.5;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == 1 && row == 1 && col == 1);
		}

		//TFA017 - Black Box Test - Volume correct size 2 which is equal to 1

		TEST_METHOD(TFA017_BlackBoxTest_VolumeCorrectSize2)
		{
			struct Map baseMap = populateMap();
			double weight = 100;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result != -2);
		}

		//TFA018 - Black Box Test - Volume correct size 3 which is equal to 5

		TEST_METHOD(TFA018_BlackBoxTest_VolumeCorrectSize3)
		{
			struct Map baseMap = populateMap();
			double weight = 100;
			double volume = 5;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result != -2);
		}

		//TFA019 - Black Box Test - Volume is not correct size

		TEST_METHOD(TFA019_BlackBoxTest_VolumeNotCorrectSize)
		{
			struct Map baseMap = populateMap();
			double weight = 100;
			double volume = 10;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -2);
		}

		//TFA020 - Black Box Test - Destination is building (2 string length)

		TEST_METHOD(TFA020_BlackBoxTest_DestinationIsBuilding_2Length)
		{
			struct Map baseMap = populateMap();
			double weight = 100;
			double volume = 5;
			char location[] = "3C";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == 1 && row == 2 && col == 2);
		}

		//TFA021 - Black Box Test - Destination is building (3 string length)

		TEST_METHOD(TFA021_BlackBoxTest_DestinationIsBuilding_3Length)
		{
			struct Map baseMap = populateMap();
			double weight = 100;
			double volume = 5;
			char location[] = "12L";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == 1 && row == 11 && col == 11);
		}

		//TFA022 - Black Box Test - Destination is not building

		TEST_METHOD(TFA022_BlackBoxTest_DestinationIsNotBuilding)
		{
			struct Map baseMap = populateMap();
			double weight = 100;
			double volume = 5;
			char location[] = "1A";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -3);
		}

		//TFA023 - Black Box Test - Destination is not exists

		TEST_METHOD(TFA023_BlackBoxTest_DestinationIsNotExists)
		{
			struct Map baseMap = populateMap();
			double weight = 100;
			double volume = 5;
			char location[] = "25Z";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -3);
		}

		//TFA024 - Black Box Test - Destination is empty string

		TEST_METHOD(TFA024_BlackBoxTest_DestinationIsEmptyString)
		{
			struct Map baseMap = populateMap();
			double weight = 100;
			double volume = 5;
			char location[] = "";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -3);
		}

		//TFA025 - Black Box Test - Destination is space only

		TEST_METHOD(TFA025_BlackBoxTest_DestinationIsSpaceOnly)
		{
			struct Map baseMap = populateMap();
			double weight = 100;
			double volume = 5;
			char location[] = " ";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -3);
		}

		//TFA026 - Black Box Test - Destination is not correct 1 (1 string length)

		TEST_METHOD(TFA026_BlackBoxTest_DestinationLengthIs1)
		{
			struct Map baseMap = populateMap();
			double weight = 100;
			double volume = 5;
			char location[] = "2";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -3);
		}

		//TFA027 - Black Box Test - Destination is not correct 2 (Over 3 string length)

		TEST_METHOD(TFA027_BlackBoxTest_DestinationLengthIsOver3)
		{
			struct Map baseMap = populateMap();
			double weight = 100;
			double volume = 5;
			char location[] = "277ABC";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);

			Assert::IsTrue(result == -3);
		}
	};

		//==White box Test Cases ===========================================

	TEST_CLASS(checkInput_WhiteBoxTestCase)
	{

	public:

		//TFA028 - White Box Test - Weight is NULL value 

		TEST_METHOD(TFA028_WhiteBoxTest_WeightIsNull)
		{
			struct Map baseMap = populateMap();
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, NULL, volume, location, &baseMap);
			Assert::IsTrue(result == -1);
		}

		//TFA029 - White Box Test - Volume is NULL value

		TEST_METHOD(TFA029_WhiteBoxTest_VolumeIsNull)
		{
			struct Map baseMap = populateMap();
			double weight = 500;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, NULL, location, &baseMap);
			Assert::IsTrue(result == -2);
		}

		//TFA030 - White Box Test - Destination is NULL value

		TEST_METHOD(TFA030_WhiteBoxTest_DestinationIsNull)
		{
			struct Map baseMap = populateMap();
			double weight = 500;
			double volume = 1;
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, NULL, &baseMap);
			Assert::IsTrue(result == -3);
		}

		//TFA031 - White Box Test - Map is NULL value

		TEST_METHOD(TFA031_WhiteBoxTest_MapIsNull)
		{
			double weight = 500;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, NULL);
			Assert::IsTrue(result == -3);
		}

		//TFA032 - White Box Test - Map size is smaller than 1 x 1

		TEST_METHOD(TFA032_WhiteBoxTest_MapIsSmallerThan1x1)
		{
			struct Map baseMap = populateMap();
			double weight = 500;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			baseMap.numRows = 0;
			baseMap.numCols = 0;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);
			Assert::IsTrue(result == -3);
		}

		//TFA033 - White Box Test - Map size is equal to 1x1

		TEST_METHOD(TFA033_WhiteBoxTest_MapIsEqualTo1x1)
		{
			struct Map baseMap = populateMap();
			double weight = 500;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			baseMap.numRows = 1;
			baseMap.numCols = 1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);
			Assert::IsTrue(result == -3);
		}

		//TFA034 - White Box Test - Rows of map is larger than MAP_ROWS

		TEST_METHOD(TFA034_WhiteBoxTest_MapRowIsLargerThanMAP_ROWS)
		{
			struct Map baseMap = populateMap();
			double weight = 500;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			baseMap.numRows = MAP_ROWS + 1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);
			Assert::IsTrue(result == -3);
		}

		//TFA035 - White Box Test - Columns of map is larger than MAP_COLS

		TEST_METHOD(TFA035_WhiteBoxTest_MapColIsLargerThanMAP_COLS)
		{
			struct Map baseMap = populateMap();
			double weight = 500;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			baseMap.numCols = MAP_COLS + 1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);
			Assert::IsTrue(result == -3);
		}

		//TFA036 - White Box Test - Weight is 14.5 since data type of weight is double
		TEST_METHOD(TFA036_WhiteBoxTest_WeightIsDoubleDataType)
		{
			struct Map baseMap = populateMap();
			double weight = 14.5;
			double volume = 1;
			char location[] = "2B";
			int row = -1;
			int col = -1;
			int result = checkInput(&row, &col, weight, volume, location, &baseMap);
			Assert::IsTrue(result == 1 && row == 1 && col == 1);
		}

	};
}
