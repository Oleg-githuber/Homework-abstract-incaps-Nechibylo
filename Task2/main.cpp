#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

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

	std::string toString()
	{
		return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(flat);
	}
};

std::string inputFile{ "in.txt" };	// Файл для чтения
std::string outputFile{ "out.txt" };	// Файл для записи

void sortAddresses(Address* addresses, int arraySize);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::ifstream input(inputFile);
	if (!input.is_open())
	{
		std::cout << "Файл " << inputFile << " не найден!" << std::endl;
	}
	else
	{
		int addressValue{};		// Количество адресов
		// Переменные для записи полей класса
		std::string city{};
		std::string street{};
		int house{};
		int flat{};

		// Чтение из файла
		input >> addressValue;
		//const int arraySize{ addressValue };
		Address* addresses = new Address[addressValue];
		for (int index = 0; index < addressValue; ++index)
		{
			input >> city;
			input >> street;
			input >> house;
			input >> flat;
			addresses[index] = Address{ city, street, house, flat };
		}
		input.close();

		// Сортировка адресов
		sortAddresses(addresses, addressValue);

		// Запись отсортированых адресов в новый файл
		std::ofstream output(outputFile);
		output << addressValue << '\n';
		for (int index = addressValue - 1; index >= 0; --index)
		{
			output << addresses[index].toString() << '\n';
		}
		output.close();

		delete[] addresses;
		std::cout << "Адреса отсортированы!" << std::endl;
	}

	std::cout << "Программа завершена!" << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}

// Функция сортировки адресов по алфавиту
void sortAddresses(Address* addresses, int arraySize)
{
	Address* tempAddress = new Address;
	bool isSortingComplete{ false };
	while (!isSortingComplete)
	{
		isSortingComplete = true;
		for (int index{}; index < arraySize - 1; ++index)
		{
			if (addresses[index].toString().compare(addresses[index + 1].toString()) == -1)
			{
				*tempAddress = addresses[index];
				addresses[index] = addresses[index + 1];
				addresses[index + 1] = *tempAddress;
				isSortingComplete = false;
			}
		}
	}
	
	delete tempAddress;
}