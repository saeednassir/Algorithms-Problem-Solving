#pragma once

#include <iostream>
#include <string>

#include "clsDate.h";
#include "clsUtil.h";
#include "clsString.h";

using namespace std;


class clsInputValidate
{

public:

	template<typename T> static bool IsNumberBetween(T Number, T From, T To)
	{
		return (Number >= From && Number <= To);
	}

	/*+static bool IsNumberBetween(short Number, short From, short To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return (Number >= From && Number <= To);
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return (Number >= From && Number <= To);
	}

	*/


	template<typename T> static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		T Number = 0;


		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	/*static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		int Number = 0;


		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		short Number = 0;


		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		double Number = 0.0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
			cin >> Number;
		}

		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		float Number = 0.0;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
			cin >> Number;
		}

		return Number;
	}*/


	template <typename T> static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, enter again:\n")
	{
		T Number = ReadNumber<T>();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber<T>();
		}
		return Number;
	}

	/*static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, enter again:\n")
	{
		short Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static double ReadFloatNumberBetween(float From, float To, string ErrorMessage = "Number is not within range, enter again:\n")
	{
		float Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}*/



	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		if (From.IsDateAfterDate2(To))
			clsUtil::Swap(From, To);

		return (Date.IsDateAfterDate2(From) || Date.IsDateEqualDate2(From))
			&& (Date.IsDateBeforeDate2(To) || Date.IsDateEqualDate2(To));
	}

	static bool IsValidDate(clsDate Date)
	{
		return Date.IsValid();
	}

	static string ReadString()
	{
		string Str = "";

		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, Str);

		return Str;
	}

	static char ReadCharacter()
	{
		char Character;
		cin >> Character;

		return Character;
	}


};

