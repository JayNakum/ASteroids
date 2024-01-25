#include "math_vectors.h" 

#include <iostream>

namespace math_lib
{
    Vec2::Vec2()
        : m_vec{ 0.0f } {}

    Vec2::Vec2(float v)
        : m_vec{ v } {}

    Vec2::Vec2(float v1, float v2)
        : m_vec{ v1, v2 } {}

    Vec2::Vec2(float vec[2])
        : m_vec{ *vec } {}

    Vec2::Vec2(const Vec2& vec)
        : m_vec{ vec.x(), vec.y() } {}

    float& Vec2::operator[](unsigned int index)
    {
        if (index > 1)
            throw std::out_of_range("Vec2");

        return m_vec[index];
    }
    float Vec2::at(unsigned int index) const
    {
        if (index > 1)
            throw std::out_of_range("Vec4");

        return m_vec[index];
    }

    Vec2 Vec2::operator+(Vec2 vec) const
    {
        return Vec2(m_vec[0] + vec[0], m_vec[1] + vec[1]);
    }

    Vec2 Vec2::operator-() const
    {
        return Vec2(-m_vec[0], -m_vec[1]);
    }

    Vec2 Vec2::operator-(Vec2 vec) const
    {
        return Vec2(m_vec[0] - vec[0], m_vec[1] - vec[1]);
    }

    Vec2 Vec2::operator*(float scaler) const
    {
        return Vec2(m_vec[0] * scaler, m_vec[1] * scaler);
    }

    float* Vec2::operator*()
    {
        return m_vec;
    }

    float Vec2::magnitude() const
    {
        return std::sqrt(m_vec[0] * m_vec[0] + m_vec[1] * m_vec[1]);
    }

    float Vec2::dot(const Vec2& vec) const
    {
        return m_vec[0] * vec.x() + m_vec[1] * vec.y();
    }

    float Vec2::cross(const Vec2& vec) const
    {
        float theta = std::acos(dot(vec) / (magnitude() * vec.magnitude()));
        return magnitude() * vec.magnitude() * std::sin(theta);
    }
}
namespace math_lib
{
    Vec3::Vec3()
        : m_vec{ 0.0f } {}

    Vec3::Vec3(float v)
        : m_vec{ v } {}

    Vec3::Vec3(float v1, float v2, float v3)
        : m_vec{ v1, v2, v3 } {}

    Vec3::Vec3(float vec[3])
        : m_vec{ *vec } {}

    Vec3::Vec3(const Vec3& vec)
        : m_vec{ vec.x(), vec.y(), vec.z() } {}

    float& Vec3::operator[](unsigned int index)
    {
        if (index > 2)
            throw std::out_of_range("Vec3");

        return m_vec[index];
    }
    float Vec3::at(unsigned int index) const
    {
        if (index > 2)
            throw std::out_of_range("Vec4");

        return m_vec[index];
    }

    Vec3 Vec3::operator+(Vec3 vec) const
    {
        return Vec3(m_vec[0] + vec[0], m_vec[1] + vec[1], m_vec[2] + vec[2]);
    }

    Vec3 Vec3::operator-() const
    {
        return Vec3(-m_vec[0], -m_vec[1], -m_vec[2]);
    }

    Vec3 Vec3::operator-(Vec3 vec) const
    {
        return Vec3(m_vec[0] - vec[0], m_vec[1] - vec[1], m_vec[2] - vec[2]);
    }

    Vec3 Vec3::operator*(float scaler) const
    {
        return Vec3(m_vec[0] * scaler, m_vec[1] * scaler, m_vec[2] * scaler);
    }

    float Vec3::magnitude() const
    {
        return std::sqrt(m_vec[0] * m_vec[0] + m_vec[1] * m_vec[1] + m_vec[2] * m_vec[2]);
    }

    float Vec3::dot(const Vec3& vec) const
    {
        return m_vec[0] * vec.x() + m_vec[1] * vec.y() + m_vec[2] * vec.z();
    }

    Vec3 Vec3::cross(const Vec3& vec) const
    {
        return Vec3(y() * vec.z() - z() * vec.y(), z() * vec.x() - x() * vec.z(), x() * vec.y() - y() * vec.x());
    }
}
namespace math_lib
{
    Vec4::Vec4()
        : m_vec{ 0.0f } {}

    Vec4::Vec4(float v)
        : m_vec{ v } {}

    Vec4::Vec4(float v1, float v2, float v3, float v4)
        : m_vec{ v1, v2, v3, v4 } {}

    Vec4::Vec4(float vec[4])
        : m_vec{ *vec } {}

    Vec4::Vec4(const Vec4& vec)
        : m_vec{ vec.x(), vec.y(), vec.z(), vec.w() } {}

    float& Vec4::operator[](unsigned int index)
    {
        if (index > 3)
            throw std::out_of_range("Vec4");

        return m_vec[index];
    }
    float Vec4::at(unsigned int index) const
    {
        if (index > 3)
            throw std::out_of_range("Vec4");

        return m_vec[index];
    }

    Vec4 Vec4::operator+(Vec4 vec) const
    {
        return Vec4(m_vec[0] + vec[0], m_vec[1] + vec[1], m_vec[2] + vec[2], m_vec[3] + vec[3]);
    }

    Vec4 Vec4::operator-() const
    {
        return Vec4(-m_vec[0], -m_vec[1], -m_vec[2], -m_vec[3]);
    }

    Vec4 Vec4::operator-(Vec4 vec) const
    {
        return Vec4(m_vec[0] - vec[0], m_vec[1] - vec[1], m_vec[2] - vec[2], m_vec[3] - vec[3]);
    }

    Vec4 Vec4::operator*(float scaler) const
    {
        return Vec4(m_vec[0] * scaler, m_vec[1] * scaler, m_vec[2] * scaler, m_vec[3] * scaler);
    }

    float Vec4::magnitude() const
    {
        return std::sqrt(m_vec[0] * m_vec[0] + m_vec[1] * m_vec[1] + m_vec[2] * m_vec[2] + m_vec[3] * m_vec[3]);
    }

    float Vec4::dot(const Vec4& vec) const
    {
        return m_vec[0] * vec.x() + m_vec[1] * vec.y() + m_vec[2] * vec.z() + m_vec[3] * vec.w();
    }
}
