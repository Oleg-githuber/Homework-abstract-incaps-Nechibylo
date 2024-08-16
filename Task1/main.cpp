#include <iostream>
#include <fstream>
#include <Windows.h>

class Address
{
private:
	std::string city{};
	std::string street{};
	int house{};
	int flat{};
public:
	Address() = default;

	Address(std::string newCity, std::string newStreet, int newHouse, int newFlat) :
		city{ newCity }, street{ newStreet }, house{ newHouse }, flat{ newFlat }
	{}

	std::string getCity()
	{
		return city;
	}

	std::string getStreet()
	{
		return street;
	}

	int getHouse()
	{
		return house;
	}

	int getFlat()
	{
		return flat;
	}
};

std::string inputFile{ "in.txt" };	// Файл для чтения
std::string outputFile{ "out.txt" };	// Файл для записи

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Чтение из файла
	std::ifstream in(inputFile);
	if (!in.is_open())
	{
		std::cout << "Файл " << inputFile << " не найден!";
	}
	else
	{
		int addressValue{};	// Количество адресов
		// Переменные для записи полей объектов класса
		std::string city{};
		std::string street{};
		int house{};
		int flat{};

		// Чтение из файла
		in >> addressValue;
		//const int arraySize{ addressValue };
		Address* addresses = new Address[addressValue];
		for (int index = 0; index < addressValue; ++index)
		{
			in >> city;
			in >> street;
			in >> house;
			in >> flat;
			addresses[index] = Address{ city, street, house, flat };
		}
		in.close();

		// Запись в файл
		std::ofstream out(outputFile);
		out << addressValue << '\n';
		for (int index = addressValue - 1; index >= 0; --index)
		{
			out << addresses[index].getCity() << ", " << addresses[index].getStreet() << ", " << addresses[index].getHouse() << ", " << addresses[index].getFlat() << '\n';
		}
		out.close();

		delete[] addresses;
	}

	return EXIT_SUCCESS;
}