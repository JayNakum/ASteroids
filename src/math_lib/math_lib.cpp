#include "math_lib.h"

namespace math_lib
{
    Vec2 math_lib::operator*(const Vec2& vec, const Mat<2>& mat)
    {
        math_lib::Vec2 result;
        for (unsigned int j = 0; j < 2; ++j)
        {
            for (unsigned int k = 0; k < 2; ++k)
            {
                result[j] += vec.at(k) * mat.at(k, j);
            }
        }
        return result;
    }

    Vec3 math_lib::operator*(const Vec3& vec, const Mat<3>& mat)
    {
        Vec3 result;
        for (unsigned int j = 0; j < 3; ++j)
        {
            for (unsigned int k = 0; k < 3; ++k)
            {
                result[j] += vec.at(k) * mat.at(k, j);
            }
        }
        return result;
    }

    Vec4 operator*(const Vec4& vec, const Mat<4>& mat)
    {
        Vec4 result;
        for (unsigned int j = 0; j < 4; ++j)
        {
            for (unsigned int k = 0; k < 4; ++k)
            {
                result[j] += vec.at(k) * mat.at(k, j);
            }
        }
        return result;
    }
}

