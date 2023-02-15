#include <iostream>

using namespace std;

class Plant {
private:
	string plant_type;
public:
	Plant() { this->plant_type = "None"; }
	Plant(string type) { this->plant_type = type; }
	void setPlantType(string type) { this->plant_type = type; }
	string getPlantType() { return this->plant_type; }
};

class Wood : public Plant {
private:
	string wood_type;
public:
	Wood() : Plant("Wood") {
		this->wood_type = "None";
	}
	Wood(string type) : Plant("Wood") {
		this->wood_type = type;
	}
	void setWoodType(string type) { this->wood_type = type; }
	string getWoodType() { return this->wood_type; }
};

class Reed : public Plant {
private:
	string reed_type;
public:
	Reed() : Plant("Reed") {
		this->reed_type = "None";
	}
	Reed(string type) : Plant("Reed") {
		this->reed_type = type;
	}
	void setReedType(string type) { this->reed_type = type; }
	string getReedType() { return this->reed_type; }
};

class Oak : public Wood {
private:
	string oak_type;
public:
	Oak() : Wood("Oak") {
		this->oak_type = "None";
	}
	Oak(string type) : Wood("Oak") {
		this->oak_type = type;
	}
	void setOakType(string type) { this->oak_type = type; }
	string getOakType() { return this->oak_type; }

};

int main() {

	Plant _plant = Plant("Tree");
	Wood _wood = Wood("Redwood");
	Reed _reed = Reed("Mentha Aquatica");
	Oak _oak = Oak("Black oak");

	cout << "Class Plant \t | Plant type: " << _plant.getPlantType() << endl;

	cout << "Class Wood \t | Plant type: " << _wood.getPlantType()
		<< " | Wood type: " << _wood.getWoodType() << endl;

	cout << "Class Reed \t | Plant type: " << _reed.getPlantType()
		<< " | Reed type: " << _reed.getReedType() << endl;

	cout << "Class Oak \t | Plant type: " << _oak.getPlantType()
		<< " | Wood type: " << _oak.getWoodType()
		<< " | Oak type: " << _oak.getOakType() << endl;

	return 1;
}

