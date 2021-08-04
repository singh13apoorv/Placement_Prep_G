class Fractions{
    private:
    int numerator;
    int denominator;

    public:
    Fractions(int numerator, int denominator){
        this->numerator = numerator;
        this->denominator = denominator;
    }

    void print(){
        cout << numerator << " / " << denominator << endl;
    }

    void simplify(){
        int gcd = 1;
        int j = min(numerator, denominator);

        for (int i = 1; i <= j; i++){
            if (numerator % i == 0 && denominator % i == 0){
                gcd = i;
            }
        }

        numerator /= gcd;
        denominator /= gcd;
    }

    //Operator overloading
    Fractions operator+(Fractions const &f2) const {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = (x * numerator) + (y * f2.numerator);

        Fractions fnew(num, lcm);

        fnew.simplify();

        return fnew;
    }

    Fractions operator*(Fractions const &f2) const {
        int num = numerator * f2.numerator;
        int deno = denominator * f2.denominator;

        Fractions fnew(num, deno);

        fnew.simplify();

        return fnew;
    }

    bool operator==(Fractions const &f2) const {
        return (numerator == f2.numerator && denominator == f2.denominator);
    }

    //Preincrement operator
    Fractions& operator++(){
        numerator += denominator;
        simplify();

        return *this;
    }

    //Post-increament operator
    Fractions operator++(int){
        Fractions fnew(numerator, denominator);
        numerator += denominator;
        simplify();
        fnew.simplify();
        return fnew;
    }

    Fractions& operator+=(Fractions const &f2){
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = (x * numerator) + (y * f2.numerator);

        numerator = num;
        denominator = lcm;
        simplify();
        return *this;
    }
};