#include <ios>
#include <ostream>
#include <string>
#include <vector>

#include "point.hh"
#include "vector.hh"

int main()
{
    /** THESE TESTS ARE NOT EXHAUSTIVE, YOU ARE STRONGLY INVITED TO DO YOUR
     * OWN **/

    std::cout << std::boolalpha;
    std::cout << "int * int : " << Mul<int, int> << "\n";
    std::cout << "int * float: " << Mul<int, float> << "\n";
    std::cout << "float * int: " << Mul<float, int> << "\n";
    std::cout << "std::string * int: " << Mul<std::string, int> << "\n";
    std::cout << std::endl;

    auto my_vec = MyVector<int>{ { 1, 2, 3 } };
    my_vec *= 3;
    std::cout << my_vec * 3;
    std::cout << my_vec.reduce(0) << std::endl;

    auto my_vec2 = MyVector<Point>{ { Point{ 1, 2 }, Point{ 2, 3 } } };
    my_vec2 *= 3; // {3, 6} {6, 9}
    std::cout << my_vec2;
    // std::cout << my_vec2.reduce(Point{ 0, 0 })
    // << std::endl;  // This should not compile

    auto my_vec3 = MyVector<std::string>{ { "a", "b", "c" } };
    // my_vec3 *= 3; // This should not compile
    std::cout << my_vec3 << std::endl;
    std::cout << my_vec3.reduce("") << std::endl;

    return 0;
}
