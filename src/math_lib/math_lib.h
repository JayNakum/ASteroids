#pragma once

#include <cmath>

#include "math_matrices.h"
#include "math_vectors.h"

#define PI 3.14159265358979323846f

namespace math_lib
{
    Vec2 operator*(const Vec2& vec, const Mat<2>& mat);
    Vec3 operator*(const Vec3& vec, const Mat<3>& mat);
    Vec4 operator*(const Vec4& vec, const Mat<4>& mat);

    template<unsigned int DIMS>
    bool operator == (const Mat<DIMS>& matA, const Mat<DIMS>& matB)
    {
        for (unsigned int i = 0; i < DIMS; ++i)
        {
            for (unsigned int j = 0; j < DIMS; ++j)
            {
                if (matA.at(i, j) != matB.at(i, j)) 
                    return false;
            }
        }
        return true;
    }

    template<unsigned int DIMS>
    bool operator != (const Mat<DIMS>& matA, const Mat<DIMS>& matB)
    {
        return !(matA == matB);
    }
}

//namespace math_lib
//{
//    std::ostream& operator<<(std::ostream& out, const Vec2& vec)
//    {
//        out << "(" << vec.x() << ", " << vec.y() << ")";
//        return out;
//    }
//
//    std::ostream& operator<<(std::ostream& out, const Vec3& vec)
//    {
//        out << "(" << vec.x() << ", " << vec.y() << ", " << vec.z() << ")";
//        return out;
//    }
//
//    std::ostream& operator<<(std::ostream& out, const Vec4& vec)
//    {
//        out << "(" << vec.x() << ", " << vec.y() << ", " << vec.z() << ", " << vec.w() << ")";
//        return out;
//    }
//
//    template <unsigned int DIMS>
//    std::ostream& operator<<(std::ostream& out, const Mat<DIMS>& mat)
//    {
//        for (unsigned int i = 0; i < DIMS; ++i)
//        {
//            for (unsigned int j = 0; j < DIMS; ++j)
//            {
//                out << mat.at(i, j) << " ";
//            }
//            out << std::endl;
//        }
//        return out;
//    }
//}
