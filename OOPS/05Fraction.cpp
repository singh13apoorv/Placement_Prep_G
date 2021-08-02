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

    void add(Fractions const &f2){
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;
        int num = (x * numerator) + (y * f2.numerator);

        numerator = num;
        denominator = lcm;

        simplify();
    }

    void multiply(Fractions const &f2){
        int num = numerator * f2.numerator;
        int deno = denominator * f2.denominator;

        numerator = num;
        denominator = deno;

        simplify();
    }
};