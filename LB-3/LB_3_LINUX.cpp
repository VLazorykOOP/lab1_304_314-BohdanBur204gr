#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "string"
#include <typeinfo>
#include <fstream>
#include <time.h>
#include <vector>

using namespace std;

//task 1
template <typename T>
class Rectangle{
private:
    T Width;
    T Height;
    string Color;
public:
    Rectangle(T w, T h){
        this->Width = w;
        this->Height = h;
        this->Color = "none";
    };

    Rectangle(T w, T h, string c) :Rectangle(w, h){
        this->Color = c;
    };


    int square(){
        return this->Width * this->Height;
    };

    int perimeter(){
        return (this->Width * 2) + (this->Height * 2);
    };

    int set_rows(T w, T h, string c)
    {
        typeid(h).name() == typeid(T).name() ? cout << "Height - OK, " << "SET Height = " << h << endl : cout << "Height - not valued (return -1)\n";
        typeid(w).name() == typeid(T).name() ? cout << "Width - OK, " << "SET Width = " << w << endl : cout << "Width - not valued (return -1)\n";
        typeid(c).name() == typeid(string).name() ? cout << "Color - OK, " << "SET Color = " << c << endl : cout << "Color - not valued (return -1)\n";

        if (typeid(h).name() == typeid(T).name()) this->Height = h;
        if (typeid(w).name() == typeid(T).name()) this->Width = w;
        if (typeid(c).name() == typeid(string).name()) this->Color = c;

        return 1;
    };

    T print_data(){
        cout << "Height = " << this->Height << endl ;
        cout << "Width = " << this->Width << endl ;
        cout << "Color = " << this->Color << endl;
        return -1;
    }

    T return_Width() {return this->Width;}
    T return_Heigth() {return this->Height;}
    string return_color() {return this->Color;}
};

void testClassOne(){
    cout << "Testing class Rectangle" << endl;

    Rectangle<float> r(12.25, 25.35, "red");
    cout << "\nData in rows\n" << r.print_data() << endl << endl;
    cout << "Square = " << r.square() << endl;
    cout << "Perimeter = " << r.perimeter() << endl;
    cout << "Return Width: " << r.return_Width() << endl;
    cout << "Return Heigth: " << r.return_Heigth() << endl;
    cout << "Return Color: " << r.return_color() << endl << endl;
    r.set_rows(15, 120, "blue");
    cout << "\n---------\nData in rows before use set function\n" << r.print_data() << endl << endl;
    cout << "Square before use set function: Square = " << r.square() << endl;
    cout << "Perimeter before use set function: Perimeter = " << r.perimeter() << endl;
    cout << "Return Width before use set function, Width: " << r.return_Width() << endl;
    cout << "Return Heigth before use set function, Heigth: " << r.return_Heigth() << endl;
    cout << "Return Color before use set function, Color: " << r.return_color() << endl << endl;
}

// task 2
class vec{
private:
    double *vectorDouble;
    int stateVector;
    int sizeVector;
    double defaultData = 0.0;
public:
    vec(): vectorDouble(NULL), stateVector(0), sizeVector(0){}

    vec(int sizeVec){
        if (sizeVec<=0){
            vec();
            stateVector = -1;
            cout << "size vector = 0 or < 0\n";
        }
        else{
            sizeVector = sizeVec;
            vectorDouble = new double[sizeVector];
            for (int i = 0; i < sizeVec; i++) vectorDouble[i] = defaultData;
        }
    };

    vec(int sizeVec, double initNumber): vec(sizeVec){
        if (vectorDouble != NULL){
            sizeVector = sizeVec;
            for (int i = 0; i < sizeVec; i++) vectorDouble[i] =  initNumber;
        }
    };

    vec(const vec &copy){
        sizeVector = copy.sizeVector;
        vectorDouble = new double[sizeVector];
        for (int i = 0; i < sizeVector; i++) vectorDouble[i] = copy.vectorDouble[i];
        stateVector = 0;
    };

    vec operator=(const vec &operatorAssign){
        if (sizeVector != operatorAssign.sizeVector) {
            if (vectorDouble) delete[] vectorDouble;

            sizeVector = operatorAssign.sizeVector;
            vectorDouble = new double[sizeVector];
            for (int i = 0; i < sizeVector-1; i++) vectorDouble[i] = operatorAssign.vectorDouble[i];
            stateVector = 0;
        }
        return *this;
    };

    void printData() {
        cout << "vector --> [ ";
        for (int i = 0; i < sizeVector; i++) cout << vectorDouble[i] << ", ";
        cout << "]\n";
    }

    double getVE(int idElement){ return vectorDouble[idElement]; };

    void setVE(int idElement, double value) {
        vectorDouble[idElement] = value;
        cout << "Element under id - " << idElement << " changed on '" << value << "'\n\n";
    }

    void setVEd(int idElement) {
        vectorDouble[idElement] = defaultData;
        cout << "\nElement under id - " << idElement << " reset to default value\n";
    }


    void sumVecONnumber(double number){
        for (int i = 0; i < sizeVector; i++) vectorDouble[i] += number;
    }

    void minVecONnumber(double number){
        for (int i = 0; i < sizeVector; i++) vectorDouble[i] -= number;
    }

    void divVecONnumber(double number){
        for (int i = 0; i < sizeVector; i++) {
            vectorDouble[i] == 0.0 ? vectorDouble[i] = 0 : vectorDouble[i] /= number;
        }
    }

    void multVecONnumber(double number){
        for (int i = 0; i < sizeVector; i++) {
            vectorDouble[i] == 0.0 ? vectorDouble[i] = 0 : vectorDouble[i] *= number;
        }
    }

    void comparionVector(double number, int param){
        switch(param){
            case 1:
                // <
                cout << "\nComparion Vector with param <\n";
                cout << "vector --> [ ";
                for (int i = 0; i < sizeVector; i++){
                    vectorDouble[i] < number ? cout << "true, " : cout << "false, ";
                }
                cout << " ]\n";
                break;
            case 2:
                // >
                cout << "\nComparion Vector with param >\n";
                cout << "vector --> [ ";
                for (int i = 0; i < sizeVector; i++){
                    vectorDouble[i] > number ? cout << "true, " : cout << "false, ";
                }
                cout << " ]\n";
                break;
            case 3:
                // ==
                cout << "\nComparion Vector with param ==\n";
                cout << "vector --> [ ";
                for (int i = 0; i < sizeVector; i++){
                    vectorDouble[i] == number ? cout << "true, " : cout << "false, ";
                }
                cout << " ]\n";
                break;
        }
    }


    ~vec(){
        cout << "Delete vector from mem\n";
        delete [] vectorDouble;
    };
};

void testClassTwo(){
    vec *vect = new vec(5, 10.3),
    *onePvec = new vec(5),
    *zeroVec = new vec();
    cout << "Testing class Vec" << endl;
    cout << "\n----------------------------------\n";

    cout << "\nConstructors test" << endl;
    cout << "None params\n";
    zeroVec->printData();
    cout << "\nOne param\n";
    onePvec->printData();
    cout << "\nTwo param\n";
    vect->printData();

    cout << "\n----------------------------------\n";
    cout << "Copy constructor test\n";
    cout << "\nOrigin vector\n";
    vect->printData();
    cout << "\nCoped vector from stek on dynamic mem\n";
    vec *copyVec = new vec(*vect);
    copyVec->printData();

    cout << "\n----------------------------------\n";
    cout << "Test destructor\n";
    cout << "Deleting ZeroVector\n";
    zeroVec->~vec();

    cout << "\n----------------------------------\n";
    cout << "Test arithmetic\n";

    cout << "\nOrigin vector\n";
    vect->printData();

    cout << "\nSUM on 5.6\n";
    copyVec->sumVecONnumber(5.6);
    copyVec->printData();

    cout << "\nMultiplication on 3.9\n";
    copyVec = new vec(*vect);
    copyVec->multVecONnumber(3.6);
    copyVec->printData();

    cout << "\nDevide on 2.2\n";
    copyVec = new vec(*vect);
    copyVec->divVecONnumber(2.2);
    copyVec->printData();

    cout << "\nMinus 2,89\n";
    copyVec = new vec(*vect);
    copyVec->minVecONnumber(2.89);
    copyVec->printData();

    cout << "\n----------------------------------\n";
    cout << "Test comparison\n";

    cout << "\nReset def data from vector with one param\n";
    for (int i = 0; i < 5; i++){
        double temp;
        cout << "Input reset value on index - " << i << " : ";
        cin >> temp;
        onePvec->setVE(i, temp);
    }

    double temp;
    cout << "\nInput number for comparison vector: ";
    cin >> temp;

    onePvec->printData();
    onePvec->comparionVector(temp, 1);
    onePvec->comparionVector(temp, 2);
    onePvec->comparionVector(temp, 3);

    cout << "\n----------------------------------\n";
    onePvec->~vec();
    copyVec->~vec();
    vect->~vec();
}

class Matrix{
private:
    int width;
    int height;
    int state;
    double defData;
    double *matrix;
public:
    Matrix(): width(4), height(3), state(0), defData(0.0), matrix(NULL) {
        matrix = new double[width*height];
        for (int i = 0; i < width*height; i++) matrix[i] = defData;
    };

    Matrix(int widthX): defData(0.0){
       matrix = new double[widthX * widthX];
       width = widthX;
       height = widthX;
       for (int i = 0; i < widthX * widthX; i++) matrix[i] = defData;
    };

    Matrix(int widthX, int heightY, double value){
        int sizeM = widthX*heightY;
        width = widthX;
        height = heightY;
        matrix = new double[sizeM];
        cout << "\nTotal elements in matrix " << sizeM << endl;
        for (int i = 0; i < sizeM; i++) {matrix[i] = value;}
    };

    Matrix(const Matrix &copy){
        width = copy.width;
        height = copy.height;
        matrix = new double[width*height];
        for (int i = 0; i < width*height; i++) matrix[i] = copy.matrix[i];
        state = 0;
    };

    Matrix operator=(const Matrix &opAssign){
        if (width*height != opAssign.height * opAssign.width) {
            if (matrix) delete[] matrix;

            width = opAssign.width;
            height = opAssign.height;
            matrix = new double[width*height];
            for (int i = 0; i < (width*height)-1; i++) matrix[i] = opAssign.matrix[i];
            state = 0;
        }
        return *this;
    };

    void printData() {
        cout << "matrix --> [\n";
        for (int i = 0; i < width*height; i++) {
            if (((i+1) % width) == 0) cout <<  matrix[i] << " ]\n" ;
            else if (((i+1) % width) == 1) cout << "[ " << matrix[i] << ", ";
            else cout << matrix[i] << ", ";
        }
        cout << " ]";
    }

    double get_element_matrix(int x, int y){
        cout << "Item by address ( i - " << x << ",j - " << y << " ) = " << matrix[(x-1)*(y-1)] << endl;
        return matrix[(x-1)*(y-1)];
    }

    void sumMatrixONnumber(double number){
        for (int i = 0; i < width*height; i++) matrix[i] += number;
    }

    void minMatrixONnumber(double number){
        for (int i = 0; i < width*height; i++) matrix[i] -= number;
    }

    void divMatrixONnumber(double number){
        for (int i = 0; i < width*height; i++) {
            matrix[i] == 0.0 ? matrix[i] = 0 : matrix[i] /= number;
        }
    }

    void multMatrixONnumber(double number){
        for (int i = 0; i < width*height; i++) {
            matrix[i] == 0.0 ? matrix[i] = 0 : matrix[i] *= number;
        }
    }

    int get_width(){ return width; }
    int get_height() {return height; }

    void comparionMatrix(double number, int param){
        switch(param){
            case 1:
                // <
                cout << "\nComparion Vector with param <\n";

                cout << "matrix --> [\n";
                for (int i = 0; i < width*height; i++) {
                    bool temp = matrix[i] < number ? true : false;

                    if (((i+1) % width) == 0) cout << temp << " ]\n" ;
                    else if (((i+1) % width) == 1) cout << "[ " << temp << ", ";
                    else cout << temp << ", ";
                }
                cout << " ]";
                break;
            case 2:
                // >
                cout << "\nComparion Vector with param >\n";
                cout << "matrix --> [\n";
                for (int i = 0; i < width*height; i++) {
                    bool temp = matrix[i] > number ? true : false;

                    if (((i+1) % width) == 0) cout <<  temp << " ]\n" ;
                    else if (((i+1) % width) == 1) cout << "[ " << temp << ", ";
                    else cout << temp << ", ";
                }
                cout << " ]";
                break;
            case 3:
                // ==
                cout << "\nComparion Vector with param ==\n";
                cout << "matrix --> [\n";
                for (int i = 0; i < width*height; i++) {
                    bool temp = matrix[i] == number ? true : false;

                    if (((i+1) % width) == 0) cout <<  temp << " ]\n" ;
                    else if (((i+1) % width) == 1) cout << "[ " << temp << ", ";
                    else cout << temp << ", ";
                }
                cout << " ]";
                break;
        }
    }

    ~Matrix(){
        cout << "Delete matrix from mem\n";
        delete [] matrix;
    };
};

void testClassThree(){
    Matrix *threeM1 = new Matrix(2, 5, 8.9),
    *oneM2 = new Matrix(2),
    *zeroM3 = new Matrix();

    cout << "Testing class Matrix" << endl;
    cout << "\n----------------------------------\n";

    cout << "\nConstructors test" << endl;
    cout << "None params\n";
    zeroM3->printData();
    cout << "\nOne param\n";
    oneM2->printData();
    cout << "\nThree param\n";
    threeM1->printData();

    cout << "\n----------------------------------\n";
    cout << "Copy constructor test\n";
    cout << "\nOrigin matrix\n";
    threeM1->printData();
    cout << "\nCoped vector from stek on dynamic mem\n";
    Matrix *copyM4 = new Matrix(*threeM1);
    copyM4->printData();

    cout << "\n----------------------------------\n";
    cout << "Test destructor\n";
    cout << "Deleting ZeroVector\n";
    zeroM3->~Matrix();

    cout << "\n----------------------------------\n";
    cout << "Test arithmetic\n";

    cout << "\nOrigin vector\n";
    threeM1->printData();

    cout << "\nSUM on 5.6\n";
    copyM4->sumMatrixONnumber(5.6);
    copyM4->printData();

    cout << "\nMultiplication on 3.9\n";
    copyM4 = new Matrix(*threeM1);
    copyM4->multMatrixONnumber(3.6);
    copyM4->printData();

    cout << "\nDevide on 2.2\n";
    copyM4 = new Matrix(*threeM1);
    copyM4->divMatrixONnumber(2.2);
    copyM4->printData();

    cout << "\nMinus 2,89\n";
    copyM4 = new Matrix(*threeM1);
    copyM4->minMatrixONnumber(2.89);
    copyM4->printData();


    cout << "\n----------------------------------\n";
    cout << "Test comparison\n";

    double temp;
    cout << "\nInput number for comparison matrix: ";
    cin >> temp;

    copyM4->printData();
    copyM4->comparionMatrix(temp, 1);
    copyM4->comparionMatrix(temp, 2);
    copyM4->comparionMatrix(temp, 3);

    cout << "\n----------------------------------\n";

    cout << "Get any element form matrix\n";
    cout << "Size first matrix with third params: " << threeM1->get_width() << " x " << threeM1->get_height() << " |\nTotal elements - " << threeM1->get_width() * threeM1->get_height() << endl;
    int x,y;
    cout << "Input coordinates element in matrix: ";
    cin >> x >> y;
    cout << "\n----------------------------------\n";
    threeM1->printData();
    cout << "\n----------------------------------\n";
    threeM1->get_element_matrix(x,y);
    cout << "\n----------------------------------\n";
    threeM1->~Matrix();
    copyM4->~Matrix();
    oneM2->~Matrix();
    cout << "\n----------------------------------\n";
}

char task;
int switcher() {
	cout << "input nuber task from 1 to 4 (or 'q' for exit from app): ";
	cin >> task;
	switch (task)
	{
	case '1':
        //FOR LINUX
		system("clear");
        // FOR WINDOWS
        //system("cls");
         testClassOne();
		break;
    case '2':
        system("clear");
        testClassTwo();
        break;
    case '3':
        system("clear");
        testClassThree();
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
