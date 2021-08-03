class Student{
    int age;
    const int rollNumber;

    public:
    //Initialization list
    Student(int a, int r) : rollNumber(r){
        age = a;
    }

    void display(){
        cout << "Age: " << age << " Roll Number: " << rollNumber << endl;  
    }
};