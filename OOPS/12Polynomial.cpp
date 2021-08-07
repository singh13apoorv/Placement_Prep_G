#include <bits/stdc++.h>
using namespace std;

class Polynomial {
    public:
    int *degCoeff;// Name of your array (Don't change this)
    int capacity;
    
    // Complete the class
    
    Polynomial(){
        degCoeff = new int[5];
        capacity = 5;
        
        for (int i = 0; i < 5; i++){
            degCoeff[i] = 0;
        }
    }
    
    Polynomial(Polynomial const &p2){
        this -> capacity = p2.capacity;
        int *degc = new int[p2.capacity];
        
        for (int i = 0; i < p2.capacity; i++){
            degc[i] = p2.degCoeff[i];
        }
        
        degCoeff = degc;
    }
    
    void setCoefficient(int degree, int coefficient){
        if (degree < capacity){
            this -> degCoeff[degree] = coefficient;
        }
        else {
            int *degc = new int[degree + 1];
            for (int i = 0; i <= degree; i++){
                degc[i] = 0;
            }
            for (int i = 0; i < capacity; i++){
                degc[i] = degCoeff[i];
            }
            degc[degree] = coefficient;
            this -> capacity = degree + 1;
            
            delete [] degCoeff;
            degCoeff = degc;
        }
    }
    
    void operator=(Polynomial const &p2){
        this -> capacity = p2.capacity;
        int *degc = new int[p2.capacity];
        
        for (int i = 0; i < p2.capacity; i++){
            degc[i] = p2.degCoeff[i];
        }
        
        degCoeff = degc;
    }
    
    Polynomial operator+(Polynomial const &p2){
        Polynomial p3;
        
        if (this -> capacity <= p2.capacity){
            int i = 0;
            while (i < this -> capacity){
                p3.setCoefficient(i, this -> degCoeff[i] + p2.degCoeff[i]);
                i++;
            }
            
            while (i < p2.capacity){
                p3.setCoefficient(i, p2.degCoeff[i]);
                i++;
            }
            return p3;
        }
        
        int j = 0;
        
        while (j < p2.capacity){
            p3.setCoefficient(j, this -> degCoeff[j] + p2.degCoeff[j]);
            j++;
        }
        
        while (j < this -> capacity){
            p3.setCoefficient(j, this -> degCoeff[j]);
            j++;
        }
        return p3;
    }
    
    Polynomial operator-(Polynomial const &p2){
        Polynomial p3;
        
        if (this -> capacity <= p2.capacity){
            int i = 0;
            while (i < this -> capacity){
                p3.setCoefficient(i, this -> degCoeff[i] - p2.degCoeff[i]);
                i++;
            }
            
            while (i < p2.capacity){
                p3.setCoefficient(i, -p2.degCoeff[i]);
                i++;
            }
            return p3;
        }
        
        int j = 0;
        
        while (j < p2.capacity){
            p3.setCoefficient(j, this -> degCoeff[j] - p2.degCoeff[j]);
            j++;
        }
        
        while (j < this -> capacity){
            p3.setCoefficient(j, this -> degCoeff[j]);
            j++;
        }
        return p3;
    }
    
    Polynomial operator*(Polynomial const &p2){
        Polynomial p3;
        
        for (int i = 0; i < (this -> capacity + p2.capacity); i++){
            p3.setCoefficient(i, 0);
        }
        
        for (int i = 0; i < this -> capacity; i++){
            for (int j = 0; j < p2.capacity; j++){
                p3.setCoefficient(i + j, p3.degCoeff[i + j] + (this -> degCoeff[i] * p2.degCoeff[j]));
            }
        }
        return p3;
    }
    
    void print(){
        for (int i = 0; i < this -> capacity; i++){
            if (this -> degCoeff[i] != 0){
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}