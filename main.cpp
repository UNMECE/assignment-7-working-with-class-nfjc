#include <iostream>
#include <cmath>
//Electric field class including constructor and deconstrucor.
class Electric_Field {
private:
    double *E;
public:
    Electric_Field() {
        E = new double[3];
        E[0] = 0;
        E[1] = 0;
        E[2] = 0;
    }

    Electric_Field(double x, double y, double z) {
        E = new double[3];
        E[0] = x;
        E[1] = y;
        E[2] = z;
    }
//Destructor. The tilde marks it as one and I added a check so it doesn't deleteE if it has a value.
    ~Electric_Field() {
        if (E != nullptr) {
            delete[] E;
            E = nullptr;
        }
    }
//CAlculates magnitude pretty simply just using the pythagorean theorem.
    double findMag() const {
        double sum = E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
        return std::sqrt(sum);
    }
//Does the same thing as magnitude calculation but without square root.
    double findInnerProduct() const {
        double result = E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
        return result;
    }

    void setX(double x) { E[0] = x; }
    void setY(double y) { E[1] = y; }
    void setZ(double z) { E[2] = z; }

    double getX() const { return E[0]; }
    double getY() const { return E[1]; }
    double getZ() const { return E[2]; }
};
//Privately delcaring #B so that it's only accessible in the class.
class Magnetic_Field {
private:
    double *B;
//Declaring the setters and getters INSIDE the class but public so they can be called outside of the class.
public:
//Construcor sets everything to zero.
    Magnetic_Field() {
        B = new double[3];
        B[0] = 0;
        B[1] = 0;
        B[2] = 0;
    }
//Constructor then assigns given values to each component.
    Magnetic_Field(double x, double y, double z) {
        B = new double[3];
        B[0] = x;
        B[1] = y;
        B[2] = z;
    }
//Same deconstructor but for magnetic field.
    ~Magnetic_Field() {
        if (B != nullptr) {
            delete[] B;
            B = nullptr;
        }
    }
//Same magnitude calculation as before.
    double findMag() const {
        double sum = B[0] * B[0] + B[1] * B[1] + B[2] * B[2];
        return std::sqrt(sum);
    }
//Calculating unit vector using previous magnitude function.
    void calculateUnitVector() const {
        double mag = findMag();
        if (mag != 0) {
            std::cout << "Unit Vector: (" << B[0] / mag << ", "
                      << B[1] / mag << ", " << B[2] / mag << ")" << std::endl;
        }
    }
//Made the setter.
    void setX(double x) { B[0] = x; }
    void setY(double y) { B[1] = y; }
    void setZ(double z) { B[2] = z; }
//Made the getter.
    double getX() const { return B[0]; }
    double getY() const { return B[1]; }
    double getZ() const { return B[2]; }
};

int main() {
//Creating the values fot the electric field in main.
    Electric_Field E_default;
    Electric_Field E_components(1e5, 10.9, 1.7e2);
//Clean output to make my code look pretty.
    std::cout << "Electric Field Magnitude (Default): " << E_default.findMag() << std::endl;
    std::cout << "Electric Field Magnitude (Components): " << E_components.findMag() << std::endl;
    std::cout << "Electric Field Inner Product: " << E_components.findInnerProduct() << std::endl;
//Rinse and repeat same steps for magnetic field then I'm done.
    Magnetic_Field B_default;
    Magnetic_Field B_components(1.5, 2.5, 3.5);

    std::cout << "Magnetic Field Magnitude (Default): " << B_default.findMag() << std::endl;
    std::cout << "Magnetic Field Magnitude (Components): " << B_components.findMag() << std::endl;
    B_components.calculateUnitVector();

    return 0;
}


