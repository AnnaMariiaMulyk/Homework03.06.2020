#include <iostream>
#include<fstream>
using namespace std;

class Array
{
	int* arr; // dynamic data
	int size;

public:
	Array()
	{
		arr = nullptr;
		size = 0;
	}
	Array(int size)
	{
		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}

	// конструкто, який приймає initializer_list<T> тим самим надає
	// можливість ініціалізації об'єкта записом Array = { 1, 2, 3 }
	Array(const initializer_list<int>& list)
	{
		size = list.size();
		arr = new int[size];

		int i = 0;
		for (int element : list)
		{
			arr[i++] = element;
		}
	}
	void Print() const
	{
		cout << "Array (size=" << size << "): ";
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << ", ";
		}
	}

	//Домашнє завдання - (), []

	int& operator[](int index) const
	{
		if (index >= 0 && index < size)
			return arr[index];
		else
			cout << "Invalid index!" << endl;
	}
	int operator()(int number)
	{
		if (number > 0)
		{
			for (int i = 0; i < size; i++)
			{
				arr[i] += number;
			}
			return *arr;
		}
		else
			cout << "Invalid number!" << endl;
	}

};
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}
	Date(int day, int year, int month)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	int getDay()
	{
		return day;
	}
	int getMonth()
	{
		return month;
	}
	int getYear()
	{
		return year;
	}
	void setDay(int day)
	{
		if (day > 0)
			this->day = day;
	}
	void setMonth(int month)
	{
		if (month > 0)
			this->month = month;
	}
	void setYear(int year)
	{
		if (year > 0)
			this->year = year;
	}
	void Print()const
	{
		if (day <= 9)
			cout << "0" << day << "\/";
		else
			cout << day << "\/";
		if(month<=9)
			cout << "0" << month << "\/";
		else
			cout << month << "\/";
		cout << year << endl;
	}
	bool operator!=(Date& other)const;
	bool operator==(Date & other)const;
	bool operator>(Date& other)const;
	bool operator<(Date& other)const;
	Date operator+=(int num)
	{
		if (num > 0)
		{
			day += num;
			month += num;
			year += num;
		}
	}
	Date operator-=(int num)
	{
		if (num > 0)
		{
			day -= num;
			month -= num;
			year -= num;
		}
	}
	ofstream& operator<<(ofstream& fout)
	{
		fout << day << endl;
		fout << month << endl;
		fout << year << endl;
		return fout;
	}
	ofstream& operator>>(ofstream& fin)
	{
		fin << day << endl;
		fin << month << endl;
		fin << year << endl;
		return fin;
	}
	

	Date operator++()
	{
		++day;
	}

	Date operator--()
	{
		--day;
	}
	Date operator++(int)
	{
		day++;
	}
	Date operator--()
	{
		day--;
	}
};


bool Date::operator!=(Date& other) const
{
	return (day!=other.day && month!=other.month && year!=other.year);
}
bool Date::operator==(Date& other) const
{
	return (day == other.day && month == other.month && year == other.year);
}

bool Date::operator>(Date& other) const
{
	return (day > other.day && month > other.month && year > other.year);
}
bool Date::operator<(Date& other) const
{
	return (day < other.day && month < other.month && year < other.year);
}

int main()
{
	int static_arr[5] = { 1, 2, 3, 4, 5 };
	int* dynamic_arr = new int[5]{ 5, 4, 3, 2, 1 };

	Array arr1;
	Array arr2 = 3;
	// 3 - parametrized constructor (initializer_list<int>)
	Array arr3 = { 1, 2, 3, 4 };
	arr3.Print();

	system("pause");
	return 0;
}

