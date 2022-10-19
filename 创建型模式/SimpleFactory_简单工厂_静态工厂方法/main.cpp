#include <iostream>

using namespace std;

enum E_CAR_TYPE
{
    E_CAR_TYPE_BENZ = 1, // 奔驰
    E_CAR_TYPE_BMW  = 2, // 宝马
};

class Car
{
public:
    virtual void CreateCar(void) = 0;
};

class BenzCar : public Car // 奔驰车
{
public:
    BenzCar()
    {
        cout << "BenzCar::Benz()" << endl;
    }

    virtual void CreateCar(void)
    {
        cout << "BenzCar::CreateBenz Car" << endl;
    }
};

class BmwCar : public Car // 宝马车
{
public:
    BmwCar()
    {
        cout << "BmwCar::Bmw()" << endl;
    }

    virtual void CreateCar(void)
    {
        cout << "BmwCar::CreateBmw Car" << endl;
    }
};

class Factory
{
public:
    Car *CreateSpecifiCar(E_CAR_TYPE eType)
    {
        Car *pCar = NULL;
        switch(eType)
	{
	    case E_CAR_TYPE_BENZ: // 奔驰
	    {
	        pCar = new BenzCar();
	        break;
	    }
	    case E_CAR_TYPE_BMW:  // 宝马
	    {
	        pCar = new BmwCar();
		break;
	    }
	    default:
	        break;
	}
	return pCar;
    }
};

int main(int argc, char *argv[])
{
    Factory mFactory;
    Car *mpCarOne = mFactory.CreateSpecifiCar(E_CAR_TYPE_BENZ);    
    Car *mpCarTwo = mFactory.CreateSpecifiCar(E_CAR_TYPE_BMW); 

    mpCarOne->CreateCar();
    mpCarTwo->CreateCar();

    delete mpCarOne;
    delete mpCarTwo;

    return 0;
}
