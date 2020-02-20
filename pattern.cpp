#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include "boost_1_72_0/boost/any.hpp"

using namespace std;

// Factory
class Warrior
{
public:
	virtual void info() = 0;
	virtual ~Warrior() {}
};

class Infantryman: public Warrior
{
public:
	void info() override {cout << "Infantryman" << endl;}
};

class Archer: public Warrior
{
public:
	void info() override {cout << "Archer" << endl;};
};

class Horseman: public Warrior
{
public:
	void info() override {cout << "Horseman" << endl;}
};

//###############################################################//

class Factory
{
public:
	virtual Warrior* createWarrior() = 0;
	virtual ~Factory() {}
};

class InfantryFactory : public Factory
{
private:
public:
	Warrior* createWarrior() override {
		return new Infantryman;
	}
};

class ArchersFactory: public Factory
{
public:
	Warrior* createWarrior() {
		return new Archer;
	}
};

class CavalryFactory: public Factory
{
public:
	Warrior* createWarrior() {
		return new Horseman;
	}
};


/*Builder*/
class BInfantryman
{
public:
	void info() {cout << "Infantryman" << endl;}
};

class BArcher
{
public:
	void info() {cout << "Archer" << endl;}
};

class BCatapult
{
public:
	void info() {cout << "Catapult" << endl;}
};

class BElephant
{
public:
	void info() {cout << "Elephant" << endl;}
};

class Army
{
private:
	
public:
	vector<BInfantryman>	vi;
	vector<BArcher>			va;
	vector<BCatapult>		vc;
	vector<BElephant>		ve;

	void info(){
		int i;
		for(i=0; i<vi.size(); ++i)  vi[i].info();
		for(i=0; i<vi.size(); ++i)  va[i].info();
		for(i=0; i<vi.size(); ++i)  vc[i].info();
		for(i=0; i<vi.size(); ++i)  ve[i].info();
	}
};

{
class ArmyBuilder
protected:
	Army* p;
public:
	ArmyBuilder() : p(nullptr) {}
	virtual ~ArmyBuilder() {}
	virtual void createArmy() {}
	virtual void buildInfantryman() {}
	virtual void buildArcher() {}
	virtual void buildCatapult() {}
	virtual void buildElephant() {} 
	virtual Army* getArmy() { return p; }
};

// Римская армия имеет все типы боевых единиц кроме боевых слонов
class RomanArmyBuilder: public ArmyBuilder
{
public:
	void createArmy() 		override { p = new Army;}
	void buildInfantryman()	override { p->vi.push_back( BInfantryman()); }
	void buildArcher()		override { p->va.push_back( BArcher()); }
	void buildCatapult()	override { p->vc.push_back( BCatapult()); }
};

// Армия Карфагена имеет все типы боевых единиц кроме катапульт
class CarthaginianArmyBuilder: public ArmyBuilder
{
public:
	void createArmy()		override { p = new Army; }
	void buildInfantryman()	override { p->vi.push_back( BInfantryman()); }
	void buildArcher()		override { p->va.push_back( BArcher()); }
	void buildElephant()	override { p->ve.push_back( BElephant()); }
};

// Класс-распорядитель, поэтапно создающий армию той или иной стороны.
// Именно здесь определен алгоритм построения армии.
class Director
{
public:
	Army* createArmy( ArmyBuilder & builder )
	{
		builder.createArmy();
		builder.buildInfantryman();
		builder.buildArcher();
		builder.buildCatapult();
		builder.buildElephant();
		return( builder.getArmy());
	}
};


//Template method
class BaseHW
{
private:
	virtual void send_impl() = 0;
public:
	BaseHW() {cout << "contruct BaseHW" << endl;}
	virtual ~BaseHW() {cout << "dictuct BaseHW" << endl;}
	void send() {
		cout << "send from base" << endl;
		send_impl();
	}
};

class ChildHW : public BaseHW
{
private:
	void send_impl() override {
		cout << "send_impl from ChildHW" << endl;
	}

public:
	ChildHW() {cout << "contruct ChildHW" << endl;}
	~ChildHW() {cout << "dictuct ChildHW" << endl;}
};





int main() {
	// Factory
	/*
	InfantryFactory* infanry_factory = new InfantryFactory;
	ArchersFactory* archers_factory = new ArchersFactory;
	CavalryFactory* cavalry_factory = new CavalryFactory;

	vector<Warrior*> v;
	v.push_back(infanry_factory->createWarrior());
	v.push_back(archers_factory->createWarrior());
	v.push_back(cavalry_factory->createWarrior());

	for(int i=0; i<v.size(); i++)
		v[i]->info();
	*/
	
	/*Builder*/

	Director dir;
	RomanArmyBuilder ra_builder;
	CarthaginianArmyBuilder ca_builder;

	Army * ra = dir.createArmy(ra_builder);
	Army * ca = dir.createArmy(ca_builder);
	cout << "Roman army:" << endl;
	ra->info();
	cout << "\nCarthaginian army:" << endl;
	ca->info();


	// template method
	// ChildHW test;
	// test.send();

	return 0;
}

// insertion sorting
//####################
// int arr[] = {10,9,8,7,6,5,4,3,2,1};
// int size = sizeof(arr)/sizeof(int);
// int upper_bound = 1;
// int sorted_count = 1;
// for (size_t i = upper_bound; i < size; i++)
// {
// 	for (size_t j = i; j && arr[j] < arr[j-1]; j--)
// 	{
// 		int var = arr[j];
// 		arr[j] = arr[j-1];
// 		arr[j-1] = var;
// 	}
// }

// buble sort
//##########################################################
// int arr[] = {10,9,8,7,6,5,4,3,2,1};
// int size = sizeof(arr)/sizeof(int);
// cout << "array size: " << sizeof(arr)/sizeof(int) << endl;
// for (size_t i = 0; i < size-1; i++)
// {
// 	int dec = (i+1);
// 	for (size_t j = 0; j < size - dec; j++)
// 	{
// 		if (arr[j] > arr[j+1])
// 		{
// 			int var = arr[j];
// 			arr[j] = arr[j+1];
// 			arr[j+1] = var;
// 		}
		
// 	}
	
// }
	

/*
// Singleton
class Singleton
{
public:
	static Singleton& get() {
		static Singleton s_Instance;
		return s_Instance;
	}

	Singleton(Singleton const &) = delete;
	Singleton& operator=(Singleton const&) = delete;

private:
	Singleton(){};
	
public:
	void func() {cout << "Singleton say hello" << endl;}
};


// Pointer to implementation
// Expression Template
// visitor
// Attorney-Client

// Strategy

struct test
{
	test() {
		cout << "construct test" << endl;
		sum = 0;
	}
	void operator() () {cout << "operator" << endl;}
	int sum;
};
*/