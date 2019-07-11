#include <string>
#include <iostream>

using namespace std;


class MyObject
{

//access modifier : public/private/protected

public :
 
	string name;
	int id;
	bool alive;

	//default constructor
	MyObject(){}

	//Parametrized Constructor
	MyObject(string inName, int inId, bool inAlive){
		name = inName;
		id = inId;
		alive = inAlive;

	}


	//Getters
	string getName(){
		return name;
	}
	int getId(){
		return id;
	}
	bool getAlive(){
		return alive;
	}

	//Setters
	void setName(string newName){
		name=newName;
	}
	void setId(int newId){
		id=newId;
	}
	void setAlive(bool newAlive){
		alive=newAlive;
	}





};

int main(){


	MyObject obj;
	obj.name = "Bob";
	obj.id = 1;
	obj.alive = true;

	cout << "Name:" << obj.name << endl;
	cout << "Id:" << obj.id << endl;
	cout << "Alive:" << obj.alive << endl;

	cout << "-----------------" << endl;

	MyObject obj2("John",2,false);

	cout << "Name:" << obj2.name << endl;
	cout << "Id:" << obj2.id << endl;
	cout << "Alive:" << obj2.alive << endl;

	cout << "-----------------" << endl;
	
	//using setters	
	obj.setName("Bill");
	obj2.setId(3);
	obj2.setAlive(true);
	
	//using getters
	cout << "Name:" << obj.getName() << endl;
	cout << "Id:" << obj2.getId() << endl;
	cout << "Alive:" << obj2.getAlive() << endl;




	return 0;

}


