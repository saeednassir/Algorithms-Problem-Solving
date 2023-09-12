#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib> 
#include <vector>

//#pragma warning(disable:4996)
//#include <ctime>

//__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;


using namespace std;

namespace MyInputLib
{
	int ReadNumber/*Validation*/(string Message)
	{
		int Number;

		cout << Message << endl;
		cin >> Number;

		while (cin.fail())
		{
			// user didn't input a number

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid Number , Enter a valid one :" << endl;
			cin >> Number;

		}

		return Number;

	}


	/*int ReadNumber(string Message)
	{
		int Number;

		cout << Message << endl;
		cin >> Number;

		return Number;
	}*/


	int ReadNumber/*InRange*/(int From, int To, string Message)
	{
		int Number;

		do
		{
			cout << Message << endl;
			cin >> Number;

		} while (Number < From || Number > To);

		return Number;
	}

	int ReadPositiveNumber(string Message)
	{

		int Number;
		do
		{
			cout << Message << endl;
			cin >> Number;

		} while (Number < 0);

		return Number;
	}
	
	float ReadPositiveNumberFloat(string Message)
	{

		float Number;
	
			cout << Message << endl;
			cin >> Number;

		return Number;
	}

	string ReadString(string Message)
	{
		string Str;

		cout << Message;
		getline(cin >> ws, Str);

		return Str;
	}

	char ReadCharacter(string Message)
	{
		char Character;

		cout << Message << endl;
		cin >> Character;

		return Character;

	}

	void ReadArray(int arr[100], int Length)
	{

		for (int i = 0; i < Length; i++)
		{
			cout << "Elements[" << i + 1 << "] : ";
			cin >> arr[i];

			
		}

	}

	void FillArrayFrom1ToN(int arr[100], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			arr[i] = i + 1;
		}
	}

	bool ReadBoolen(string Message)
	{
		bool Boolen;

		cout << Message << endl ;
		cin >> Boolen;

		return Boolen;

	}

	void InputUserNumbersInArray(int arr[100], int& Length)
	{
		int Number;
		bool Boolen;

		do
		{
			Number = MyInputLib::ReadPositiveNumber("Please enter a number ? ");

			arr[Length] = Number;
			Length++;

			Boolen = MyInputLib::ReadBoolen("Do you want to add more numbers? [0]:No,[1]:yes ? ");

		} while (Boolen == true);

	}

	void ReadVectorNumbers(vector <int>& vNumbers)
	{
		char AginNumber = 'y';

		do
		{

			vNumbers.push_back(MyInputLib::ReadNumber("Please enter a number ? "));

			cout << "Do You want to read more Number ? y/n ? ";
			cin >> AginNumber;

		} while (AginNumber == 'Y' || AginNumber == 'y');


	}

	struct stEmployee
	{
		int Id;
		string Name;
		int Salary;
	};
	void ReadStructVector(vector <stEmployee>& vEmployee)
	{
		char AddMore = 'Y';
		int Count = 0;
		stEmployee TempEmployee;


		while (AddMore == 'Y' || AddMore == 'y')
		{
			
			Count += 1;
			cout << "Employee [" << Count << "] : \n";

			cout << "Enter Id ? ";
			cin >> TempEmployee.Id;

			cout << "Enter Name ? ";
			cin >> TempEmployee.Name;

			cout << "Enter Salary ? ";
			cin >> TempEmployee.Salary;

			vEmployee.push_back(TempEmployee);

			cout << "\nDo You want to read more Employee ? y/n ? ";
			cin >> AddMore;

		}
	}
	void printStructEmployeeVector(vector <stEmployee>& vEmployees)
	{
		int Count = 0;

		for (stEmployee& Employee : vEmployees)
		{
			Count += 1;

			cout << "Employee [" << Count << "] : \n";

			cout << "Id     : " << Employee.Id << endl;
			cout << "Name   : " << Employee.Name << endl;
			cout << "Salary : " << Employee.Salary << endl;

			cout << endl;
		}
	}
	
	
	struct stDate
	{
		short Day;
		short Month;
		short Year;
	};
	stDate ReadFullDate()
	{
		stDate Date;

		Date.Day = MyInputLib::ReadPositiveNumber("Please enter a Day ?");
		Date.Month = MyInputLib::ReadPositiveNumber("Please enter a Month ?");
		Date.Year = MyInputLib::ReadPositiveNumber("Please enter a Year ?");

		return Date;
	}

}

namespace MyMathLib
{
	enum enOddOrEven{ Even = 1 ,Odd = 2 };
	enOddOrEven CheckNumberTypeOddOrEven(int Number)
	{
		if (Number % 2 == 0)
			return enOddOrEven::Even;
		else
			return enOddOrEven::Odd;
	}

	enum enPrimeOrNotPrime { Prime = 1 , NotPrime = 2};
	enPrimeOrNotPrime CheckPrime(int Number)
	{
		//int M = round(Number / 2);
		int M = sqrt(Number);

		for (int Counter = 2; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
				return enPrimeOrNotPrime::NotPrime;

		}

		return enPrimeOrNotPrime::Prime;

	}

	float CalculateHalfNumber(float Number)
	{
		return Number / 2;
	}

	float CalculateSimple(float Number1, float Number2, char OpType)
	{
		switch (OpType)
		{
		case '+':
			return Number1 + Number2;
		case '-':
			return Number1 - Number2;
		case '*':
			return Number1 * Number2;
		case '/':
			return Number1 / Number2;
		default:
			return Number1 + Number2;
		}
	}

	float CalculateRectangleArea(float Height, float Width)
	{
		float Area;
		Area = Height * Width;
		return Area;
	}

	float CalculateRectangleAreaBySideAndDiagonal(float Height, float Diameter)
	{
		float Area;
		Area = Height * sqrt(pow(Diameter, 2) - pow(Height, 2));
		return Area;
	}

	float CircleArea(float Radius)
	{
		float Area;
		const float PI = 3.141592653589793238;
		Area = PI * pow(Radius, 2);
		return Area;
	}

	float CircleAreaByDiameter(float Diameter)
	{
		float Area;
		const float PI = 3.14;
		Area = (PI * pow(Diameter, 2)) / 4;
		return Area;
	}

	float CircleAreaInscribedInSquare(float A)
	{
		float Area;
		const float PI = 3.14;
		Area = (PI * pow(A, 2)) / 4;
		return Area;
	}

	float CircleAreaByCircumference(float L)
	{
		float Area;
		const float PI = 3.14;
		Area = pow(L, 2) / (4 * PI);
		return Area;
	}

	float CircleAreaByITriangle(float A, float B)
	{
		float Area;
		const float PI = 3.14;
		Area = PI * (pow(B, 2) / 4) * ((2 * A - B) / (2 * A + B));
		return Area;
	}

	float CircleAreaByTriangle(float A, float B, float C)
	{
		float Area;
		const float PI = 3.14;
		float P = (A + B + C) / 2;
		float T = (A * B * C) / (4 * sqrt(P * (P - A) * (P - B) * (P - C)));
		Area = PI * pow(T, 2);

		return Area;
	}

	int Factorial(int Number)
	{
		int Factorial = 1;
		for (int Counter = Number; Counter >= 1; Counter--)
		{
			Factorial *= Counter;
		}

		return Factorial;
	}

	int MaxOf2Numbers(int Num1, int Num2)
	{
		if (Num1 > Num2)
			return Num1;
		else
			return Num2;
	}

	int MaxOf3Numbers(int Num1, int Num2, int Num3)
	{
		if (Num1 > Num2)
			if (Num1 > Num3)
				return Num1;
			else
				return Num3;
		else

			if (Num2 > Num3)
				return Num2;
			else
				return Num3;
	}

	int PowerOfM(int Number, int M)
	{
		if (M == 0)
		{
			return 1;
		}
		
		
			int P = 1;

			for (int i = 1; i <= M; i++)
			{
				P *= Number;
			}

			return P;
		
	}

	int PowerRecursions(int Base, int Power)
	{
		if (Power == 0)
			return 1;


		if (Power >= 1)
			return (Base * PowerRecursions(Base, Power - 1));

	}

	float TriangleArea(float Height, float Base)
	{
		float Area ;
		Area = 0.5 * Height * Base;
		return Area;
	}
	
	int MaxNumberInArray(int arr[100], int Length)
	{
		int Max = 0;

		for (int i = 0; i < Length; i++)
		{
			if (arr[i] > Max)
				Max = arr[i];
		}

		return Max;
	}

	int MinNumberInArray(int arr[100], int Length)
	{
		int Min = 0;
		Min = arr[0];

		for (int i = 0; i < Length; i++)
		{

			if (arr[i] < Min)
				Min = arr[i];

		}

		return Min;
	}

	int SumArray(int arr[100], int Length)
	{
		int Sum = 0;

		for (int i = 0; i < Length; i++)
		{
			Sum += arr[i];
		}

		return Sum;

	}

	float AvergeInArray(int Length, int SumArray)
	{
		return (float)SumArray / Length;
	}

	void SumOf2Array(int arr[100], int arr2[100], int arrSum[100], int& Length)
	{
		for (int i = 0; i < Length; i++)
		{
			arrSum[i] = arr[i] + arr2[i];
		}
	}

	int OddCountInArray(int arr[100], int Length)
	{
		int CountOdd = 0;

		for (int i = 0; i < Length; i++)
		{
			if (MyMathLib::CheckNumberTypeOddOrEven(arr[i]) == MyMathLib::Odd)
				CountOdd++;
		}

		return CountOdd;

	}

	int EvenCountInArray(int arr[100], int Length)
	{
		int CountEven = 0;

		for (int i = 0; i < Length; i++)
		{
			if (MyMathLib::CheckNumberTypeOddOrEven(arr[i]) == MyMathLib::Even)
				CountEven++;
		}

		return CountEven;

	}

	int PositiveCountInArray(int arr[100], int Length)
	{
		int PositiveCount = 0;

		for (int i = 0; i < Length; i++)
		{
			if (arr[i] >= 0)
				PositiveCount++;
		}

		return PositiveCount;

	}

	int NegativeCountInArray(int arr[100], int Length)
	{
		int NegativeCount = 0;

		for (int i = 0; i < Length; i++)
		{
			if (arr[i] < 0)
				NegativeCount++;
		}

		return NegativeCount;

	}

	int MyABS(int Number)
	{
		if (Number < 0)
			return Number * -1;
		else
			return Number;
	}

	float GetFractionPart(float Number)
	{
		return Number - (int)Number;
	}

	int MyRound(float Number)
	{
		int IntPart = (int)Number;
		float FractionPart = MyMathLib::GetFractionPart(Number);

		if (abs(FractionPart) >= .5)
		{
			if (Number > 0)
				return ++IntPart;
			else
				return --IntPart;
		}
		else {
			return IntPart;
		}

	}

	float Myfloor(float Number)
	{
		int IntPart = (int)Number;
		float FractionPart = MyMathLib::GetFractionPart(Number);

		if (Number >= 0)
			return IntPart;
		else
		{
			if (abs(FractionPart) >= .1)
				return --IntPart;
			else
				return IntPart;
			
		}

	}

	float MyCeil(float Number)
	{
		int IntPart = (int)Number;
		float FractionPart = MyMathLib::GetFractionPart(Number);

		if (Number >= 0)
		{
			if (abs(FractionPart) >= .1)
				return ++IntPart;
			else
				return IntPart;
		}	
		else
			return IntPart;

	}
	
	int Mysqrt(float Number)
	{
		return pow(Number, 0.5);
	}

	int digital_root(int n)
	{
		/*
		Sum of Digits / Digital Root :

		 16  -->  1 + 6 = 7
		 942  -->  9 + 4 + 2 = 15  -->  1 + 5 = 6
		132189  -->  1 + 3 + 2 + 1 + 8 + 9 = 24  -->  2 + 4 = 6
		493193  -->  4 + 9 + 3 + 1 + 9 + 3 = 29  -->  2 + 9 = 11  -->  1 + 1 = 2

		*/

		int Number = n;
		int Sum = 0;

		while (Number > 0)
		{
			Sum += (Number % 10);
			Number = Number / 10;
		}

		if (Sum >= 10)
			Sum = digital_root(Sum);

		return Sum;
	}
	/*int digital_root(int n)
	{
		return (n - 1) % 9 + 1;
	}*/




}

namespace MyOperationsLib
{

	void PrintArray(int arr[], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			cout << arr[i] << " ";
		}

		cout << endl;
		cout << endl;
	}

	void CopyArray(int arr[100], int arr2[100], int Length)
	{
		for (int i = 0; i < Length; i++)
			arr2[i] = arr[i];
	}

	void CopyOnlyPrimeNumbers(int arr[100], int arr2[100], int Length, int& Length2)
	{
		int Counter = 0;

		for (int i = 0; i < Length; i++)
		{
			if (MyMathLib::CheckPrime(arr[i]) == MyMathLib::Prime)
			{
				arr2[Counter] = arr[i];
				Counter++;
			}

		}

		Length2 = Counter;
	}

	void AddArrayElement(int Number, int arr[100], int& arrLength)
	{
		arrLength++;
		arr[arrLength - 1] = Number;
	}

	void PrintDigits(int Number)
	{

		int Remainder = 0;


		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;

			cout << Remainder << endl;

		}


	}

	int ReverseNumber(int Number)
	{
		int Remainder = 0;
		int Number2 = 0;

		while (Number > 0)
		{
			Remainder = Number % 10;
			Number = Number / 10;

			Number2 = Number2 * 10 + Remainder;
		}

		return Number2;

	}

	bool IsPerfectNumber(int Number)
	{

		int Sum = 0;

		for (int i = 1; i < Number; i++)
		{
			if (Number % i == 0)
				Sum += i;
		}

		return Number == Sum;
	}

	bool ValidateNumberInRange(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	void Swap(int &Num1, int &Num2)
	{
		int Temp;
		Temp = Num1;
		Num1 = Num2;
		Num2 = Temp;

		/*cout << Num1 << endl;
		cout << Num2 << endl;*/
	}

	int CountDigitFrequency(int Number, int DigitNumber)
	{
		int Remainder = 0;
		int Count = 0;

		while (Number > 0)
		{
			Remainder = Number % 10;
			Number /= 10;

			if (Remainder == DigitNumber)
				Count++;
		}

		return Count;
	}

	void PrintAllDigitsFrequency(int Number)
	{


		for (int i = 0; i <= 9; i++)
		{
			int count = MyOperationsLib::CountDigitFrequency(Number, i);
			if (count > 0)
				cout << "Digit " << i << " Frequency is " << count << " Time(s)." << endl;
		}

	}


	string  EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] + EncryptionKey);
		}

		return Text;

	}

	string  DecryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}

		return Text;
	}

	int RandomNumber(int From, int To)
	{
		return rand() % (To - From + 1) + From;
	}

	void FillArrayWithRandomNumbers(int arr[100], int& Length , int From,int To)
	{

		for (int i = 0; i < Length; i++)
			arr[i] = MyOperationsLib::RandomNumber(From, To);

	}

	int RepeatedNumber (int Number, int arr[100], int arrLength)
	{
		int Count = 0;
		for (int i = 0; i <= arrLength - 1; i++)
		{
			if (Number == arr[i])
				Count++;
		}
		return Count;
	}

	void ShuffleArray(int arr[100], int Length)
	{
		// ÎáØ ÇáÇÑÞÇã ÈÔßá ÚÔæÇÆí

		for (int i = 0; i < Length; i++)
		{
			MyOperationsLib::Swap(arr[MyOperationsLib::RandomNumber(1, Length) - 1],
				arr[MyOperationsLib::RandomNumber(1, Length) - 1]);
		}
	}

	void CopyArrayInReverseOrder(int arr[100], int arr2[100], int Length)
	{

		for (int i = 0; i < Length; i++)
			arr2[i] = arr[Length - 1 - i];
		
		
	}

	enum enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };
	char GetRandomCharacter(enCharType CharType)
	{
		switch (CharType)
		{
		case enCharType::SmallLetter:
		{
			return char(MyOperationsLib::RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(MyOperationsLib::RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{
			return char(MyOperationsLib::RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(MyOperationsLib::RandomNumber(48, 57));
			break;
		}
		}
	}
	string GenerateWord(enCharType CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++) // 1 <= 4 ? | 2 <= 4 ...
		{
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}
	string GenerateKey(enCharType CharType, int LengthKey, int LengthWord)
	{
		string Key = "";

		for (int i = 0; i < LengthKey; i++)
		{
			Key = Key + GenerateWord(CharType, LengthWord) + "-";
		}
		return Key;
	}
	void FillArrayString(string arr[100], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			arr[i] = GenerateKey(enCharType::CapitalLetter, 4,4);
		}
	}

	void PrintArrayString(string arr[100], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			cout << "Array [" << i + 1 << "] : ";
			cout << arr[i] << endl;
		}
	}

	int FindNumberPositionInArray(int arr[100], int Length, int CheckNumber)
	{
		for (int i = 0; i < Length; i++)
		{
			if (arr[i] == CheckNumber)
				return i;

		}

		return -1;

	}

	bool IsNumberInArray(int arr[100], int Length, int Number)
	{
		return MyOperationsLib::FindNumberPositionInArray(arr, Length, Number) != -1;
	}

	void CopyDistinactNumbersToArray(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (!MyOperationsLib::IsNumberInArray(arrDestination, arrLength, arrSource[i]))
				MyOperationsLib::AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
		}
	}

	bool IsPalindromeArray(int arr[100], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			if (arr[i] != arr[Length - i - 1])
			{
				return false;
			}
		}

		return true;
	}

	
	void PrintNumbersRecursion(int n, int m)
	{
		// ÛÑÖ ÊÚáã Çá recursion

		if (n <= m)
		{
			cout << m << endl;
			PrintNumbersRecursion(n+1, m);
		}


	}

	void PrintTowDimensionalArray()
	{
		int arr[10][10];

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				arr[i][j] = (i + 1) * (j + 1);

				printf("%0*d ", 2, arr[i][j]);
			}
			cout << endl;
		}
	}

	void PrintVector(vector <int> & vNumbers)
	{
		cout << "Vectors Numbers is : ";
		for (int& Number : vNumbers)
		{
			cout << Number << "  ";
		}

	}

	

}

namespace MyFileLib
{
	void PrintFileContenet(string FileName)
	{
		fstream MyFile;

		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				cout << Line << endl;
			}

			MyFile.close();
		}

	}

	void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent)
	{
		fstream MyFile;

		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				vFileContent.push_back(Line);
			}

			MyFile.close();
		}


	}

	void SaveVectorToFile(string FileName, vector <string> vFileContenet)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out);

		if (MyFile.is_open())
		{
			for (string Line : vFileContenet)
			{
				if (Line != "")
				{
					MyFile << Line << endl;
				}
				
			}

			MyFile.close();
		}

	}

	void DeleteRecordFromFile(string FileName, string Record)
	{ 
		vector <string> vFileContenet;
		LoadDataFromFileToVector(FileName, vFileContenet);

		for (string& Line : vFileContenet)
		{
			if (Line == Record)
			{
				Line = "";
			}
		}

		SaveVectorToFile(FileName, vFileContenet);

	}

	void UpdateRecordFromFile(string FileName, string Record, string UpdateTo)
	{
		vector <string> vFileContenet;
		LoadDataFromFileToVector(FileName, vFileContenet);

		for (string& Line : vFileContenet)
		{
			if (Line == Record)
			{
				Line = UpdateTo;
			}
		}

		SaveVectorToFile(FileName, vFileContenet);

	}


}

namespace MyStringLib 
{
	void PrintFirstLetterOfEachWord(string Str)
	{
		bool isFirstLatter = true;

		for (int i = 0; i < Str.length(); i++)
		{

			if (Str[i] != ' ' && isFirstLatter)
				cout << Str[i] << endl;

			isFirstLatter = (Str[i] == ' ' ? true : false);

		}

	}

	string UpperFirstLetterOfEachWord(string Str)
	{
		bool isFirstLatter = true;


		for (int i = 0; i < Str.length(); i++)
		{

			if (Str[i] != ' ' && isFirstLatter)
				Str[i] = toupper(Str[i]);

			isFirstLatter = (Str[i] == ' ' ? true : false);

		}

		return Str;

	}

	string LowerFirstLetterOfEachWord(string Str)
	{
		bool isFirstLatter = true;


		for (int i = 0; i < Str.length(); i++)
		{

			if (Str[i] != ' ' && isFirstLatter)
				Str[i] = tolower(Str[i]);

			isFirstLatter = (Str[i] == ' ' ? true : false);

		}

		return Str;

	}

	string LowerAllString(string Str)
	{

		for (int i = 0; i < Str.length(); i++)
		{
			Str[i] = tolower(Str[i]);
		}

		return Str;

	}

	string UpperAllString(string Str)
	{

		for (int i = 0; i < Str.length(); i++)
		{
			Str[i] = toupper(Str[i]);
		}

		return Str;

	}

	char InvertCharacter(char Character)
	{
		return isupper(Character) ? tolower(Character) : toupper(Character);
	}

	string InvertAllStrngLettersCase(string Str)
	{
		for (int i = 0; i < Str.length(); i++)
		{
			Str[i] = MyStringLib::InvertCharacter(Str[i]);
		}

		return Str;
	}


	int CountCapitalLetters(string Str)
	{
		int CapitalCounter = 0;

		for (int i = 0; i < Str.length(); i++)
		{
			if (isupper(Str[i]))
				CapitalCounter++;
		}

		return CapitalCounter;
	}

	int CountSmallLetters(string Str)
	{
		int SmallCounter = 0;

		for (int i = 0; i < Str.length(); i++)
		{
			if (islower(Str[i]))
				SmallCounter++;
		}

		return SmallCounter;
	}


	enum enWhatToCount { SmallLatters = 0, CapitalLatters = 1, All = 2, Digit = 3, Punct = 4 };
	int CountLatters(string Str, enWhatToCount WhatToCount = enWhatToCount::All)
	{

		if (WhatToCount == enWhatToCount::All)
			return Str.length();



		int Count = 0;

		for (int i = 0; i < Str.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLatters && isupper(Str[i]))
				Count++;

			if (WhatToCount == enWhatToCount::SmallLatters && islower(Str[i]))
				Count++;

			if (WhatToCount == enWhatToCount::Digit && isdigit(Str[i]))
				Count++;

			if (WhatToCount == enWhatToCount::Punct && ispunct(Str[i]))
				Count++;

		}

		return Count;
	}
	
	short CountLetter(string Str, char Character)
	{
		short Counter = 0;

		for (int i = 0; i < Str.length(); i++)
		{
			if (Str[i] == Character)
				Counter++;
		}

		return Counter;
	}

	short CountLetter(string Str, char Character, bool MatchCase = true)
	{

		short Counter = 0;

		for (int i = 0; i < Str.length(); i++)
		{
			if (MatchCase)
			{
				if (Str[i] == Character)
					Counter++;
			}
			else
			{
				if (tolower(Str[i]) == tolower(Character))
					Counter++;
			}

		}

		return Counter;
	}

	bool IsVowels(char Character)
	{
		Character = tolower(Character);

		return ((Character == 'a') || (Character == 'e') || (Character == 'i') || (Character == 'o') || (Character == 'u'));

	}

	short CountVowelsInString(string Str)
	{
		short Count = 0;

		for (short i = 0; i < Str.length(); i++)
		{
			if (MyStringLib::IsVowels(Str[i]))
				Count++;
		}

		return Count;
	}

	void PrintVowels(string Str)
	{


		for (short i = 0; i < Str.length(); i++)
		{
			if (MyStringLib::IsVowels(Str[i]))
				cout << Str[i] << "   ";
		}

	}

	void PrintEachWordInString(string Str)
	{
		string delim = " "; // delimiter.

		cout << "Your string word are : " << endl;

		short pos = 0;
		string sWord; // define a string variable. 


		// use find() funcation to get the position of the delimiter.  
		while ((pos = Str.find(delim)) != string::npos)
		{
			sWord = Str.substr(0, pos); // store the word

			if (sWord != "")
				cout << sWord << endl;

			Str.erase(0, pos + delim.length()); // erase() until positon and move to next word. 


		}

		if (Str != "")
			cout << Str << endl; // its print last word of string.

	}

	short CountWords(string Str)
	{
		string delim = " "; // delimiter.
		short pos = 0;
		string sWord; // define a string variable. 
		short Counter = 0;

		// use find() funcation to get the position of the delimiter.  
		while ((pos = Str.find(delim)) != string::npos)
		{
			sWord = Str.substr(0, pos); // store the word

			if (sWord != "")
				Counter++;

			Str.erase(0, pos + delim.length()); // erase() until positon and move to next word. 


		}

		if (Str != "")
			Counter++; // it counts the last word of the string.

		return Counter;

	}

	vector<string> SplitString(string Str, string Delim)
	{
		short pos = 0;
		string sword;

		vector<string> vString;

		while ((pos = Str.find(Delim)) != string::npos)
		{
			sword = Str.substr(0, pos);

			if (sword != "")
				vString.push_back(sword);

			Str.erase(0, pos + Delim.length());

		}

		if (Str != "")
			vString.push_back(Str);

		return vString;

	}


	string TrimLeft(string Str)
	{

		for (int i = 0; i < Str.length(); i++)
		{
			if (Str[i] != ' ')
			{
				return Str.substr(i, Str.length() - 1);
			}
		}
		return "";
	}
	string TrimRight(string Str)
	{

		for (int i = Str.length() - 1; i >= 0; i--)
		{
			if (Str[i] != ' ')
			{
				return Str.substr(0, i + 1);
			}
		}

		return "";
	}
	string Trim(string Str)
	{
		return TrimLeft(TrimRight(Str));
	}

	string JoinString(vector<string> vString, string Delim)
	{
		string Str = "";

		for (string& S : vString)
		{
			Str += (S + Delim);
		}

		return Str.substr(0, Str.length() - Delim.length());
	}
	string JoinString(string arr[100], int Length, string Delim)
	{
		string Str = "";

		for (int i = 0; i < Length; i++)
		{
			Str += arr[i] + Delim;
		}

		return Str.substr(0, Str.length() - Delim.length());
	}

	string ReverseWordsInString(string Str)
	{
		string Text = "";
		vector<string> vString;

		vString = MyStringLib::SplitString(Str, " ");

		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;
			Text += *iter + " ";
		}

		Text = Text.substr(0, Text.length() - 1); // remove last space.

		return Text;

	}

	string ReplaceWordInStringUsingBuiltInFuncation(string Str, string StringToReplace, string sReplaceTo)
	{
		short Pos = Str.find(StringToReplace);

		while (Pos != string::npos)
		{
			Str = Str.replace(Pos, StringToReplace.length(), sReplaceTo);
			Pos = Str.find(StringToReplace); //find text.
		}

		return Str;
	}
	string ReplaceWordInStringUseSplit(string Str, string StringToReplace, string sToReplace, bool MatchCase = true)
	{
		vector<string> vString;
		vString = MyStringLib::SplitString(Str, " ");

		string UpperStringToReplace = MyStringLib::UpperAllString(StringToReplace);


		for (string& S : vString)
		{
			if (MatchCase)
			{
				if (S == StringToReplace)
					S = sToReplace;
			}
			else
			{
				if (MyStringLib::UpperAllString(S) == UpperStringToReplace)
					S = sToReplace;
			}

		}

		return MyStringLib::JoinString(vString, " ");

	}



}

namespace MyDateTimeLib 
{
	void PrintDateTime()
	{
		time_t t = time(0);

		char* dt = ctime(&t);

		cout << "Local date and time is : " << dt << "\n";

		tm* gmtm = gmtime(&t);
		dt = asctime(gmtm);
		cout << "UTC date and time is : " << dt << "\n";
	}

	void PrintDateTimeStructure()
	{
		time_t t = time(0);

		tm* now = localtime(&t);

		cout << "Year : " << now->tm_year + 1900 << endl;
		cout << "Month : " << now->tm_mon + 1 << endl;
		cout << "Day : " << now->tm_mday << endl;
		cout << "Hour : " << now->tm_hour << endl;
		cout << "Min : " << now->tm_min << endl;
		cout << "Secoaned : " << now->tm_sec << endl;
		cout << "Week Day (Days since sunday) : " << now->tm_wday << endl;
		cout << "year Day (Days since january 1st) : " << now->tm_yday << endl;
		cout << "Hour of daylight savings time : " << now->tm_isdst << endl;


	}

	bool IsLeapYear(int Year)
	{
		/* if (Year % 400 == 0)
		 {
			 return true;
		 }
		 else if (Year % 4 == 0 && Year % 100 != 0)
		 {
			 return true;
		 }
		 else
		 {
			 return false;

		 }*/


		return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0)) ? true : false;

	}
	int NumberOfDaysInYear(int Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	int NumberOfHoursInYear(int Year)
	{
		return NumberOfDaysInYear(Year) * 24;
	}
	int NumberOfMinutesInYear(int Year)
	{
		return NumberOfHoursInYear(Year) * 60;
	}
	int NumberOfSecondsInYear(int Year)
	{
		return NumberOfMinutesInYear(Year) * 60;
	}

	int NumberOfDaysInMonth(int Year, int Month)
	{
		if (Month < 1 || Month > 12)
			return 0;

		if (Month == 2)
		{
			return IsLeapYear(Year) ? 29 : 28;
		}

		short arr31Days[7] = { 1,3,5,7,8,10,12 };

		for (int i = 0; i < 7; i++)
		{
			if (arr31Days[i] == Month)
				return 31;
		}

		// if you reach here then it's 30 days.
		return 30;

	}
	int NumberOfHoursInMonth(int Year, int Month)
	{
		return NumberOfDaysInMonth(Year, Month) * 24;
	}
	int NumberOfMinutesInMonth(int Year, int Month)
	{
		return NumberOfHoursInMonth(Year, Month) * 60;
	}
	int NumberOfSecoundsInMonth(int Year, int Month)
	{
		return NumberOfMinutesInMonth(Year, Month) * 60;
	}

	struct stDate
	{
		short Day;
		short Month;
		short Year;
	};

	short DayOfWeekOrder(short Year, short Month, short Day)
	{
		short a = (14 - Month) / 12;
		short Y = Year - a;
		short M = Month + (12 * a) - 2;

		// Gregorian :
		// 0:Sun, 1:Mon, 2:Tue...etc 

		return (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;

	}
	short DayOfWeekOrder(stDate Date)
	{
		return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);
	}

	string ConvertOrderToDaysName(short DayOfWeekOrder)
	{
		string arrDays[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

		return arrDays[DayOfWeekOrder];
	}

	string MonthShortName(short Month)
	{
		//string arrMonth[12] = {"January","Februay","March","April","May","June","July","August","September","October","November","December"};
		string arrMonth[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return arrMonth[Month - 1];
	}
	void PrintMonthCalendar(short Month, short Year)
	{
		// Index of the day from 0 to 6
		short Curent = DayOfWeekOrder(Year, Month, 1);
		short NumOfDays = NumberOfDaysInMonth(Year, Month);

		printf("\n _______________%s_______________\n\n", MonthShortName(Month).c_str());

		// Print the columns 
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// print appropriate spaces
		short i;
		for (i = 0; i < Curent; i++)
			printf("     ");

		for (short j = 1; j <= NumOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}


		}
		cout << "\n\n_________________________________\n";

	}
	void PrintYearCalendar(short Year)
	{
		printf("\n_________________________________\n\n");
		printf("        Calender - %d          \n", Year);
		printf("_________________________________\n");

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}

	}

	short NumberOfDaysFromTheBeginingOfTheYear(short Year, short Month, short Day)
	{
		short TotalDay = 0;

		for (short i = 1; i <= Month - 1; i++)
		{
			TotalDay += NumberOfDaysInMonth(Year, i);
		}

		TotalDay += Day;

		return TotalDay;
	}

	stDate GetDateFromDayOrderInYear(short DaysOrderInYear, short Year)
	{
		stDate Date;
		short RemainingDays = DaysOrderInYear;
		short MonthDays = 0;

		Date.Year = Year;
		Date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Year, Date.Month);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}

		}

		return Date;
	}

	bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);

	}
	bool IsDate1EqualDate2(stDate Date1, stDate Date2)
	{
		return (Date1.Year == Date2.Year) ? (Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) : true : false;
	}
	bool IsDate1AfterDate2(stDate Date1, stDate Date2)
	{
		/* Íáí
		return (Date1.Year > Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month > Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day > Date2.Day : false)) : false);
		*/

		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));

	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };
	enDateCompare CompareDates(stDate Date1, stDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		/*if (IsDate1AfterDate2(Date1, Date2))
			return enDateCompare::After;*/

			//this is faster
		return enDateCompare::After;

	}
	
	bool IsLastDayInMonth(stDate Date)
	{
		return (Date.Day == NumberOfDaysInMonth(Date.Year, Date.Month));
	}
	bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}
	stDate IncreaseDateByOneDay(stDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}

		return Date;
	}

	
	stDate GetSystemDate()
	{
		stDate Date;

		time_t t = time(0);
		tm* now = localtime(&t);

		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;

		return Date;

	}


	stDate IncreaseDateByXDay(stDate Date, int X)
	{
		for (int i = 0; i < X; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}
	stDate IncreaseDateByOneWeek(stDate Date)
	{
		return IncreaseDateByXDay(Date, 7);
	}
	stDate IncreaseDateByXWeeks(stDate Date, int X)
	{
		for (int i = 0; i < X; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}

		return Date;
	}
	stDate IncreaseDateByOneMonth(stDate Date)
	{

		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		/*last check day in date should not exceed max days in thecurrent month
			 example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should
			 be 28/2/2022*/

		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	stDate IncreaseDateByXMonths(stDate Date, int X)
	{
		for (int i = 0; i < X; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}

		return Date;
	}
	stDate IncreaseDateByOneYear(stDate Date)
	{
		Date.Year++;
		return Date;
	}
	stDate IncreaseDateByXYears(stDate Date, int X)
	{
		for (int i = 0; i < X; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}

		return Date;
	}
	stDate IncreaseDateByXYearsFaster(stDate Date, int X)
	{
		Date.Year += X;

		return Date;
	}
	stDate IncreaseDateByOneDecade(stDate Date)
	{
		Date.Year += 10;
		return Date;
	}
	stDate IncreaseDateByXDecade(stDate Date, int X)
	{
		for (int i = 0; i < X; i++)
		{
			Date = IncreaseDateByOneDecade(Date);
		}

		return Date;
	}
	stDate IncreaseDateByXDecadeFaster(stDate Date, int X)
	{

		Date.Year += X * 10;

		return Date;
	}
	stDate IncreaseDateByOneCentury(stDate Date)
	{
		Date.Year += 100;
		return Date;
	}
	stDate IncreaseDateByOneMillennium(stDate Date)
	{
		Date.Year += 1000;
		return Date;
	}


	stDate DecreaseDateByOneDay(stDate Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Day = 31;
				Date.Month = 12;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInMonth(Date.Year, Date.Month);

			}
		}
		else
		{
			Date.Day--;
		}

		return Date;
	}
	stDate DecreaseDateByXDays(stDate Date, short Days)
	{
		for (short i = 0; i < Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	stDate DecreaseDateByOneWeek(stDate Date)
	{
		return DecreaseDateByXDays(Date, 7);
	}
	stDate DecreaseDateByXWeeks(stDate Date, short Weeks)
	{
		for (short i = 0; i < Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}

		return Date;
	}
	stDate DecreaseDateByOneMonth(stDate Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}


		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Year, Date.Month);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;

	}
	stDate DecreaseDateByXMonths(stDate Date, short Months)
	{
		for (short i = 0; i < Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}

		return Date;
	}
	stDate DecreaseDateByOneYear(stDate Date)
	{
		Date.Year--;
		return Date;
	}
	stDate DecreaseDateByXYears(stDate Date, short Years)
	{
		for (short i = 0; i < Years; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}

		return Date;
	}
	stDate DecreaseDateByXYearsFaster(stDate Date, short Years)
	{
		Date.Year -= Years;
		return Date;
	}
	stDate DecreaseDateByOneDecade(stDate Date)
	{
		Date.Year -= 10;
		return Date;
	}
	stDate DecreaseDateByXDecades(stDate Date, short Decades)
	{
		for (short i = 0; i < Decades; i++)
		{
			Date = DecreaseDateByOneDecade(Date);
		}

		return Date;
	}
	stDate DecreaseDateByXDecadesFaster(stDate Date, short Decades)
	{
		Date.Year -= Decades * 10;
		return Date;
	}
	stDate DecreaseDateByOneCentury(stDate Date)
	{
		Date.Year -= 100;
		return Date;
	}
	stDate DecreaseDateByOneMillennium(stDate Date)
	{
		Date.Year -= 1000;
		return Date;
	}

	int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days : Days;
	}


	bool IsEndOfWeek(stDate Date)
	{
		return (DayOfWeekOrder(Date) == 6);
	}
	bool IsWeekend(stDate Date)
	{
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}
	bool IsBusinessDay(stDate Date)
	{
		//BusinessDay are  Sun,Mon,Tue,Wed and The

		/*short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex >= 5 && DayIndex <= 4);*/

		//shorter method is to invert the IsWeekEnd: this will save updating code.
		return (!IsWeekend(Date));

	}
	short DaysUntilTheEndOfWeek(stDate Date)
	{
		/* Íáí
		short Counter = 0;

		while (!IsEndOfWeek(Date))
		{
			Date = IncreaseDateByOneDay(Date);
			Counter++;
		}

		return Counter;*/

		return 6 - DayOfWeekOrder(Date);

	}
	short DaysUntilTheEndOfMonth(stDate Date)
	{
		/*Íáí
		short Counter = 0;

		while (!IsLastDayInMonth(Date))
		{
			Date = IncreaseDateByOneDay(Date);
			Counter++;
		}

		return Counter;*/

		stDate EndMonthDate;

		EndMonthDate.Day = NumberOfDaysInMonth(Date.Year, Date.Month);
		EndMonthDate.Month = Date.Month;
		EndMonthDate.Year = Date.Year;

		return GetDifferenceInDays(Date, EndMonthDate);
	}
	bool IsLastDayInYear(stDate Date)
	{
		return (Date.Day == 31 && Date.Month == 12);
	}
	short DaysUntilTheEndOfYear(stDate Date)
	{
		/*Íáí
	   short Counter = 0;

	   while (!IsLastDayInYear(Date))
	   {
		   Date = IncreaseDateByOneDay(Date);
		   Counter++;
	   }

	   return Counter;*/

		stDate EndMonthDate;

		EndMonthDate.Day = 31;
		EndMonthDate.Month = 12;
		EndMonthDate.Year = Date.Year;

		return GetDifferenceInDays(Date, EndMonthDate);

	}

	short CalculateActucalVacationDays(stDate DateFrom, stDate DateTo)
	{
		short DaysCount = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{

			if (!IsWeekend(DateFrom))
				DaysCount++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DaysCount;
	}

	stDate CalculateVacationReturnDate(stDate DateFrom, short VactionDays)
	{
		//Íáí
	   /*short VD = VactionDays;


	   while (VD > 0)
	   {
		   if (!IsWeekend(DateFrom))
			   VD--;

		   DateFrom = IncreaseDateByOneDay(DateFrom);
	   }

	   while (IsWeekend(DateFrom))
	   {
		   DateFrom = IncreaseDateByOneDay(DateFrom);
	   }

	   return DateFrom;*/



		short WeekEndCounter = 0;

		//in case the data  is weekend keep adding one day util you reach business day
		//we get rid of all weekends before the first business day
		while (IsWeekend(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//here we increase the vacation dates to add all weekends to it.

		for (short i = 1; i <= VactionDays + WeekEndCounter; i++)
		{

			if (IsWeekend(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//in case the return date is week end keep adding one day util you reach business day
		while (IsWeekend(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}
	
	struct stPeriod {

		stDate StartTime;
		stDate EndTime;

	};
	bool IsOverlapPeriod(stPeriod Period1, stPeriod Period2)
	{
		if (
			CompareDates(Period2.EndTime, Period1.StartTime) == enDateCompare::Before
			||
			CompareDates(Period2.StartTime, Period1.EndTime) == enDateCompare::After
			)
			return false;
		else
			return true;

	}

	bool IsDateInPeriod(stDate Date, stPeriod Period)
	{
		return !(CompareDates(Date, Period.StartTime) == enDateCompare::Before

			||
			CompareDates(Date, Period.EndTime) == enDateCompare::After);
	}

	stDate StringToDate(string date)
	{
		stDate Date;
		vector<string> vString;

		vString = MyStringLib::SplitString(date, "/");

		Date.Day = stoi(vString[0]);
		Date.Month = stoi(vString[1]);
		Date.Year = stoi(vString[2]);

		return Date;
	}
	string DateToString(stDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}


	string FormatDate(stDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDateString = "";

		FormattedDateString = MyStringLib::ReplaceWordInStringUsingBuiltInFuncation(DateFormat, "dd", to_string(Date.Day));
		FormattedDateString = MyStringLib::ReplaceWordInStringUsingBuiltInFuncation(FormattedDateString, "mm", to_string(Date.Month));
		FormattedDateString = MyStringLib::ReplaceWordInStringUsingBuiltInFuncation(FormattedDateString, "yyyy", to_string(Date.Year));

		return FormattedDateString;
	}

	
}

namespace SinglyLinkedList
{
	template<class T> class Node
	{

	public:

		T Data;
		Node* Next;

	};

	void InsertAtBiginning(Node<int>*& Head, int Value)
	{
		Node<int>* new_node = new Node<int>();

		new_node->Data = Value;
		new_node->Next = Head;

		Head = new_node;

	}

	void PrintList(Node<int>* Head)
	{
		cout << "\n";
		while (Head != NULL)
		{
			cout << Head->Data << " ";
			Head = Head->Next;

		}

	}

	Node<int>* Find(Node<int>* Head, int Value)
	{
		while (Head != NULL)
		{
			if (Head->Data == Value)
				return Head;

			Head = Head->Next;
		}

		return NULL;
	}

	void InsertAfter(Node<int>* Prev_node, int Value)
	{
		if (Prev_node == NULL)
		{
			cout << "\nthe given previous node cannot be NULL\n";
			return;
		}

		Node<int>* new_node = new Node<int>();

		new_node->Data = Value;
		new_node->Next = Prev_node->Next;

		Prev_node->Next = new_node;

	}

	void InsertAtEnd(Node<int>*& Head, int Value)
	{
		Node<int>* new_node = new Node<int>();

		new_node->Data = Value;
		new_node->Next = NULL;

		if (Head == NULL)
		{
			Head = new_node;
			return;
		}

		Node<int>* LastNode = Head;

		while (LastNode->Next != NULL)
		{
			LastNode = LastNode->Next;
		}

		LastNode->Next = new_node;
	}

	void DeleteNode(Node<int>*& head, int Value) {

		Node<int>* Current = head, * Prev = head;

		if (head == NULL)
		{
			return;
		}

		if (Current->Data == Value) {
			head = Current->Next;
			delete Current;//free from memory
			return;
		}

		// Find the key to be deleted
		while (Current != NULL && Current->Data != Value) {
			Prev = Current;
			Current = Current->Next;
		}

		// If the value is not present
		if (Current == NULL) return;

		// Remove the node
		Prev->Next = Current->Next;
		delete Current;//free from memory

	}

	void DeleteFirstNode(Node<int>*& head)
	{
		Node<int>* FirstNode = head;

		if (head == NULL)return;

		head = FirstNode->Next;
		delete FirstNode;
		return;
	}

	void DeleteLastNode(Node<int>*& head)
	{
		Node<int>* Current = head, * Prev = head;

		if (Current == NULL)return;


		if (Current->Next == NULL)
		{
			head = NULL;
			delete Current;
			return;
		}

		while (Current != NULL && Current->Next != NULL)
		{
			Prev = Current;
			Current = Current->Next;
		}

		Prev->Next = NULL;
		delete Current;

	}


}

namespace DoublyLinkedList
{
	class Node
	{
	public:
		int value;
		Node* next;
		Node* prev;
	};

	void InsertAtBeginning(Node*& head, int value) {


		/*
			1-Create a new node with the desired value.
			2-Set the next pointer of the new node to the current head of the list.
			3-Set the previous pointer of the current head to the new node.
			4-Set the new node as the new head of the list.
		*/

		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = head;
		newNode->prev = NULL;

		if (head != NULL) {
			head->prev = newNode;
		}
		head = newNode;
	}

	void PrintNodeDetails(Node* head)
	{

		if (head->prev != NULL)
			cout << head->prev->value;
		else
			cout << "NULL";

		cout << " <--> " << head->value << " <--> ";

		if (head->next != NULL)
			cout << head->next->value << "\n";
		else
			cout << "NULL";

	}

	void PrintListDetails(Node* head)

	{
		cout << "\n\n";
		while (head != NULL) {
			PrintNodeDetails(head);
			head = head->next;
		}
	}

	void PrintList(Node* head)

	{
		cout << "NULL <--> ";
		while (head != NULL) {
			cout << head->value << " <--> ";
			head = head->next;
		}
		cout << "NULL";

	}

	Node* Find(Node* Head, int Value)
	{
		while (Head != NULL)
		{
			if (Head->value == Value)
				return Head;

			Head = Head->next;
		}

		return NULL;

	}

	void InsertAfter(Node* current, int value) {


		/*  1 - Create a new node with the desired value.
			 2-Set the next pointer of the new node to the next node of the current node.
			 3-Set the previous pointer of the new node to the current node.
			 4-Set the next pointer of the current node to the new node.
			 5-Set the previous pointer of the next node to the new node(if it exists).
		*/

		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = current->next;
		newNode->prev = current;

		if (current->next != NULL) {
			current->next->prev = newNode;
		}
		current->next = newNode;
	}

	void InsertAtEnd(Node* head, int value) {

		/*
			1-Create a new node with the desired value.
			2-Traverse the list to find the last node.
			3-Set the next pointer of the last node to the new node.
			4-Set the previous pointer of the new node to the last node.
		*/

		Node* newNode = new Node();
		newNode->value = value;
		newNode->next = NULL;
		if (head == NULL) {
			newNode->prev = NULL;
			head = newNode;
		}
		else {
			Node* current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newNode;
			newNode->prev = current;
		}
	}

	void DeleteNode(Node*& head, Node*& NodeToDelete) {


		/*
			1-Set the next pointer of the previous node to the next pointer of the current node.
			2-Set the previous pointer of the next node to the previous pointer of the current node.
			3-Delete the current node.
		*/
		if (head == NULL || NodeToDelete == NULL) {
			return;
		}
		if (head == NodeToDelete) {
			head = NodeToDelete->next;
		}
		if (NodeToDelete->next != NULL) {
			NodeToDelete->next->prev = NodeToDelete->prev;
		}
		if (NodeToDelete->prev != NULL) {
			NodeToDelete->prev->next = NodeToDelete->next;
		}
		delete NodeToDelete;
	}

	void DeleteFirstNode(Node*& head) {

		/*
			1-Store a reference to the head node in a temporary variable.
			2-Update the head pointer to point to the next node in the list.
			3-Set the previous pointer of the new head to NULL.
			4-Delete the temporary reference to the old head node.
		*/

		if (head == NULL) {
			return;
		}
		Node* temp = head;
		head = head->next;
		if (head != NULL) {
			head->prev = NULL;
		}
		delete temp;
	}

	void DeleteLastNode(Node*& head) {

		/*
			1-Traverse the list to find the last node.
			2-Set the next pointer of the second-to-last node to NULL.
			3-Delete the last node.
		*/

		if (head == NULL) {
			return;
		}
		if (head->next == NULL) {
			delete head;
			head = NULL;
			return;
		}
		Node* current = head;
		while (current->next->next != NULL) {
			current = current->next;
		}
		Node* temp = current->next;
		current->next = NULL;
		delete temp;
	}



}