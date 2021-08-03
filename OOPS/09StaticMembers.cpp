class Student{
    static int totalStudents; //Now this property belongs to a class

    public:
    int rollNumber;
    int age;

    Student(){
        totalStudents++;
    }

    static int getTotalStudents(){
        return totalStudents;
    }
};

int Student :: totalStudents = 0; //Initializing static data members