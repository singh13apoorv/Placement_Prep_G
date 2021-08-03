class Student {
    int age;
    public:
    char *name;

    public:
    Student (int age, char *name){
        this -> age = age;
        this -> name = new char[strlen(name) + 1];
        strcpy(this -> name, name);
    }

    //Own Copy Constructor with deep copy as default copy constructor does shallow copy
    Student(Student const &s){
        this -> age = s.age;
        //Shallow copy as done by the default constructor
        //this -> name = s.name;
        
        //Deep copy
        this -> name = new char[strlen(s.name) + 1];
        strcpy(this -> name, s.name);
    }

    void display(){
        cout << name << " " << age << endl;
    }
};