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

std::string inputFile{ "in.txt" };	// ���� ��� ������
std::string outputFile{ "out.txt" };	// ���� ��� ������

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ������ �� �����
	std::ifstream in(inputFile);
	if (!in.is_open())
	{
		std::cout << "���� " << inputFile << " �� ������!";
	}
	else
	{
		int addressValue{};	// ���������� �������
		// ���������� ��� ������ ����� �������� ������
		std::string city{};
		std::string street{};
		int house{};
		int flat{};

		// ������ �� �����
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

		// ������ � ����
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