#include<iostream>
using namespace std;

class sally{
	
public:
	int num;
	sally(int);
	sally();
	sally operator+(sally);

};

sally::sally(){}
sally::sally(int a){
	num=a;
}
sally sally::operator+(sally a){
	sally brandnew;
	brandnew.num=num+a.num;
	return brandnew;
}

int main(){
	sally a(5);;
	sally b(3);
	sally c;
	c=a+b;
	cout<<c.num<<endl;

}