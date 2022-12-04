#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ostream>
#include <string>
#include <cmath>
#include "string"
#include <vector>

using namespace std;

class VectorDouble{
private:
    double *vector;
    int size;
    double codeError;
    int countElemetsThisClass = 0;
public:
    VectorDouble(): vector(NULL), size(0), codeError(0){
      ++countElemetsThisClass;
    }

    VectorDouble(int sizeV);
    VectorDouble(int sizeV, double initData);

    VectorDouble & operator ++();
    VectorDouble & operator --();
    VectorDouble & operator ^(const VectorDouble &other);
    VectorDouble & operator -(const VectorDouble &other);
    VectorDouble & operator +(const VectorDouble &other);
    VectorDouble & operator *(double number);
    VectorDouble & operator /(double number);
    VectorDouble & operator %(double number);
    double & operator [](int i);
    VectorDouble & operator =(const VectorDouble &other);
    VectorDouble & operator +=(double number);
    VectorDouble & operator -=(double number);
    VectorDouble & operator *=(double number);
    VectorDouble & operator /=(double number);
    VectorDouble & operator %=(double number);
    bool operator !() const;
    bool operator >(const VectorDouble &other);
    bool operator <(const VectorDouble &other);
    bool operator >=(const VectorDouble &other);
    bool operator <=(const VectorDouble &other);
    bool operator ==(const VectorDouble &other);
    bool operator !=(const VectorDouble &other);


    friend istream& operator>> (istream& is, VectorDouble& vec);
    friend ostream& operator<< (ostream& os, VectorDouble& vec);

    ~VectorDouble(){
      cout << "Delete vector from mem\n";
      --this->countElemetsThisClass;
      delete [] vector;
    }

};

VectorDouble::VectorDouble(int sizeV){
    vector = new double[abs(sizeV)];
    size = sizeV;
    ++this->countElemetsThisClass;
    for (int i = 0; i < abs(sizeV); i++) vector[i] = 0.0;
};

VectorDouble::VectorDouble(int sizeV, double initData): VectorDouble::VectorDouble(sizeV){
    for (int i = 0; i < abs(sizeV); i++) vector[i] = initData;
};

VectorDouble& VectorDouble::operator ++(){
  for (int i = 0; i < abs(this->size); i++){ this->vector[i] += 1.0; }
  return *this;
};

VectorDouble& VectorDouble::operator --(){
  for (int i = 0; i < abs(this->size); i++){ --this->vector[i]; }
  return *this;
};

VectorDouble& VectorDouble::operator ^(const VectorDouble &other){
  int size = this->size;
  double *temp = new double[size];
  for (int i = 0; i < size; i++){
    if (i + 1 == size)
    temp[size - 1] = (this->vector[0] * other.vector[1]) - (this->vector[1] * other.vector[0]);
    else
    temp[i] = (this->vector[i + 1 == size ? 0 : i+1] * other.vector[i + 2 == size ? 1 : i + 2]) - (this->vector[i + 2 == size ? 1 : i + 2] * other.vector[i + 1 == size ? 0 : i + 1]);
  }
  for (int i = 0; i < size; i++){
    this->vector[i] = temp[i];
  }
  return *this;
};

VectorDouble & VectorDouble::operator +(const VectorDouble &other){
  int size = abs(this->size);
  for (int i = 0; i < size; i++){
    this->vector[i] = this->vector[i] + other.vector[i];
  }
  return *this;
};

VectorDouble & VectorDouble::operator -(const VectorDouble &other){
  int size = abs(this->size);
  for (int i = 0; i < size; i++){
    this->vector[i] = this->vector[i] - other.vector[i];
  }
  return *this;
};

double & VectorDouble::operator [](int i){
    if(i > this->size){
      this->codeError = -2.0;
      cout << "Error code = ";
      return this->codeError;
    }else {
      return this->vector[i];
    }
};

VectorDouble & VectorDouble::operator *(double number){
  int size = abs(this->size);
  for (int i = 0; i < size; i++){
    this->vector[i] = this->vector[i] * number;
  }
  return *this;
};

VectorDouble & VectorDouble::operator /(double number){
  int size = abs(this->size);
  for (int i = 0; i < size; i++){
    this->vector[i] = this->vector[i] / number;
  }
  return *this;
};

VectorDouble & VectorDouble::operator %(double number){
  int size = abs(this->size);
  for (int i = 0; i < size; i++){
    this->vector[i] = double((short)this->vector[i] % (short)number);
  }
  return *this;
};

VectorDouble & VectorDouble::operator =(const VectorDouble &other){
  for (int i = 0; i < this->size; i++) this->vector[i] = other.vector[i];
  return *this;
}

VectorDouble & VectorDouble::operator +=(double number){
  for (int i = 0; i < abs(this->size); i++){
    this->vector[i] = this->vector[i] +  number;
  }
  return *this;
};

VectorDouble & VectorDouble::operator -=(double number){
  for (int i = 0; i < abs(this->size); i++){
    this->vector[i] -= number;
  }
  return *this;
};

VectorDouble & VectorDouble::operator *=(double number){
  for (int i = 0; i < abs(this->size); i++){
    this->vector[i] *= number;
  }
  return *this;
};

VectorDouble & VectorDouble::operator /=(double number){
  for (int i = 0; i < abs(this->size); i++){
    this->vector[i] /= number;
  }
  return *this;
};

VectorDouble & VectorDouble::operator %=(double number){
  for (int i = 0; i < abs(this->size); i++){
    this->vector[i] = double((short)this->vector[i] % (short)number);
  }
  return *this;
};

bool VectorDouble::operator!() const{ return this->size != 0; };

bool VectorDouble::operator>(const VectorDouble &other){
  int size = abs(other.size) < abs(this->size) ? abs(other.size) : abs(this->size);
  bool *temp = new bool[size];
  cout << "\nComparison a > b\n";
  for (int i = 0; i < size; i++){
    temp[i] = this->vector[i] > other.vector[i];
    cout << this->vector[i] << " > " << other.vector[i] << " = " << temp[i] << endl;
  }
  return *temp;
};

bool VectorDouble::operator<(const VectorDouble &other){
  int size = abs(other.size) < abs(this->size) ? abs(other.size) : abs(this->size);
  bool *temp = new bool[size];
  cout << "\nComparison a < b\n";
  for (int i = 0; i < size; i++){
    temp[i] = this->vector[i] < other.vector[i];
    cout << this->vector[i] << " < " << other.vector[i] << " = " << temp[i] << endl;
  }
  return *temp;
};

bool VectorDouble::operator>=(const VectorDouble &other){
  int size = abs(other.size) < abs(this->size) ? abs(other.size) : abs(this->size);
  bool *temp = new bool[size];
  cout << "\nComparison a >= b\n";
  for (int i = 0; i < size; i++){
    temp[i] = this->vector[i] >= other.vector[i];
    cout << this->vector[i] << " >= " << other.vector[i] << " = " << temp[i] << endl;
  }
  return *temp;
};

bool VectorDouble::operator<=(const VectorDouble &other){
  int size = abs(other.size) < abs(this->size) ? abs(other.size) : abs(this->size);
  bool *temp = new bool[size];
  cout << "\nComparison a <= b\n";
  for (int i = 0; i < size; i++){
    temp[i] = this->vector[i] <= other.vector[i];
    cout << this->vector[i] << " <= " << other.vector[i] << " = " << temp[i] << endl;
  }
  return *temp;
};

bool VectorDouble::operator==(const VectorDouble &other){
  int size = abs(other.size) < abs(this->size) ? abs(other.size) : abs(this->size);
  bool *temp = new bool[size];
  cout << "\nComparison a == b\n";
  for (int i = 0; i < size; i++){
    temp[i] = this->vector[i] == other.vector[i];
    cout << this->vector[i] << " == " << other.vector[i] << " = " << temp[i] << endl;
  }
  return *temp;
};

bool VectorDouble::operator!=(const VectorDouble &other){
  int size = abs(other.size) < abs(this->size) ? abs(other.size) : abs(this->size);
  bool *temp = new bool[size];
  cout << "\nComparison a != b\n";
  for (int i = 0; i < size; i++){
    temp[i] = this->vector[i] != other.vector[i];
    cout << this->vector[i] << " != " << other.vector[i] << " = " << temp[i] << endl;
  }
  return *temp;
};

istream& operator>> (istream& is, VectorDouble& vec) {
  for (int i = 0; i < vec.size; i++) {
    cout << "Input elemet vector - " << i + 1 << " :";
    is >> vec.vector[i];
  }
  return is;
}

ostream& operator<< (ostream& os, VectorDouble& vec) {
  for (int i = 0; i < vec.size; i++) {
    os << "Element " << i + 1 << " = " << vec.vector[i] << endl;
  }
  return os;
}

void testMethodForVectorClass(){
  VectorDouble
  *a = new VectorDouble(4),
  *b = new VectorDouble(4, 10.2),
  *c = new VectorDouble(4),
  *d = new VectorDouble(4);

  cout << "\nInput Vector A - \n"; cin >> *a;
  cout << "\nInput Vector C - \n"; cin >> *c;
  *d = *a * 3 + *b * 4 - *c * 3;
  cout << "\nd = [\n" << *d << "]\n";
  *d = *a * -3 + *b * 6 + *c * 6;
  cout << "\nd = [\n" << *d << "]\n";
 *d = *b - *a ^ *c;
  cout << "\nd = [\n" << *d << "]\n";

  *a != *b;
  *c == *a;
  *a > *c;
  *b < *d;

  cout << "\na *= 3\n";
  *a *= 2;
  cout << "\na = [\n" << *a << "]\n";

  cout << "\nb /= 4\n";
  *b /= 4;
  cout << "\nb = [\n" << *b << "]\n";

  cout << "\nd %= 2\n";
  cout << "\nd (before)= [\n" << *d << "]\n";
  *d %= 2;
  cout << "\nd (after)= [\n" << *d << "]\n";

  cout << "\na++\n";
  cout << "\na (before)= [\n" << *a << "]\n";
  ++*a;
  cout << "\na (after)= [\n" << *a << "]\n";

  cout << "\na[2] = " << a->operator[](1) << "\n";
  cout << "\na[5] = " << a->operator[](5) << "\n";


  a->~VectorDouble();
  b->~VectorDouble();
}

class Domen{
public:
  string ip;
  string name;

  Domen(): ip("0"), name("0"){};
  Domen(string ipA, string domen){
    this->ip = ipA;
    this->name = domen;
  };
  friend istream& operator>> (istream& is2, Domen& vec);
  friend ostream& operator<< (ostream& os2, Domen& vec);
};

std::istream& operator>> (std::istream& is2, Domen& vec) {
  cout << "Input IPv4 and domen for this ip : ";
  is2 >> vec.name >> vec.ip;
  return is2;
}

ostream &operator<< (ostream& os2, Domen& vec) {
  os2 << "IPv4 = " << vec.ip << "\nDomen = " << vec.name << endl;
  return os2;
}

class CAssoc{
private:
  Domen res;
  Domen *arr;
  int size;
  int state=0;
public:
  CAssoc(): state(0){};

  CAssoc(int size, Domen* list): CAssoc(){
    arr = new Domen[size];
    this->size = size;
    for (int i = 0; i < 3; i++){
       this->arr[i] = list[i];
    }
  };

  string & operator[](char* data){
    for (int i = 0; i < this->size; i++){
      if (this->arr[i].ip == data){
        return this->arr[i].name;
      }
    }
    for (int i = 0; i < this->size; i++){
      if (this->arr[i].name == data){
        return this->arr[i].ip;
      }
    }
    state = -1;
    string r = "\nItem with (IP or URL) not found \n";
    return r;
  };

  Domen & operator[](int index){
    if (index > this->size){
      state = -1;
      cout << "Item with index '"<< index <<"' not found \n";
    } else {
      return this->arr[index];
    }
  };

  int & operator()(string ip, string url){
    for (int i = 0; i < this->size; i++){
      if (this->arr[i].ip == ip){
        if (this->arr[i].name == url){
          cout << "Ok -> \n" << this->arr[i];
        }
        else {
          cout << "There is a match with the IP, but there is no address with this IP, there are such address\n";
          cout << this->arr[i];
        }
      }
      else {
        cout << "\nNothing was found for this query ( IP = "<< ip << " and URL = " << url << " )\n";
        this->state = 404;
      }
    }
    return this->state;
  }
};

void testDNSclass(){
  Domen dns[3] = {{"127.56.0.23", "google.com"}, 
                  {"78.0.856.255", "yahoo.com.ua"}, 
                  {"256.255.0.0", "you.com.us"}};
  CAssoc temp(3, dns);
  cout << "All DNS in table\n";
  for (int i = 0; i < 3; i++){
    cout << temp[i] << endl;
  }

  cout << "Request for URL (Test operator [])\n";
  cout << "URL = google.com\n IP = " << temp["google.com"];

  cout << "Request for IP (Test operator [])\n";
  cout << " IP = 78.0.856.255" << "URL = " << temp["78.0.856.255"];


  temp("256.255.0.0", "you.com.us");

  cout << "\nErrors test\n\n";

  cout << "Request for URL (Test operator [])\n";
  cout << "URL = goo5gle.com5\n IP = "; temp["goog5le.com5"];

  cout << "\n\nRequest for IP (Test operator [])\n";
  cout << " IP = 0" << "\nURL = "; temp["0"];


  temp("256.255.0.0", "0");
  temp("0", "0");
}

char task;
int switcher() {
	cout << "input nuber task from 1 to 2 (or 'q' for exit from app): ";
	cin >> task;
	switch (task)
	{
	case '1':
        //FOR LINUX
		system("clear");
        // FOR WINDOWS
        testMethodForVectorClass();
        //system("cls");
		break;
    case '2':
        system("clear");
        testDNSclass();
        break;
	default:
		return -1;
		break;
    }
    return 0;
}

int main()
{
    while (true) {
		if (switcher() == -1) break;
    }

}
