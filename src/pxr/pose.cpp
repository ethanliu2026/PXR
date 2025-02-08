#define FMT_HEADER_ONLY
#include "fmt/core.h"

#include "pxr/pose.hpp"

pxr::Pose::Pose(float x, float y, float theta) {
    this->x = x;
    this->y = y;
    this->theta = theta;
}

pxr::Pose pxr::Pose::operator+(const pxr::Pose& other) const {
    return pxr::Pose(this->x + other.x, this->y + other.y, this->theta);
}

pxr::Pose pxr::Pose::operator-(const pxr::Pose& other) const {
    return pxr::Pose(this->x - other.x, this->y - other.y, this->theta);
}

float pxr::Pose::operator*(const pxr::Pose& other) const { return this->x * other.x + this->y * other.y; }

pxr::Pose pxr::Pose::operator*(const float& other) const {
    return pxr::Pose(this->x * other, this->y * other, this->theta);
}

pxr::Pose pxr::Pose::operator/(const float& other) const {
    return pxr::Pose(this->x / other, this->y / other, this->theta);
}

pxr::Pose pxr::Pose::lerp(pxr::Pose other, float t) const {
    return pxr::Pose(this->x + (other.x - this->x) * t, this->y + (other.y - this->y) * t, this->theta);
}

float pxr::Pose::distance(pxr::Pose other) const { return std::hypot(this->x - other.x, this->y - other.y); }

float pxr::Pose::angle(pxr::Pose other) const { return std::atan2(other.y - this->y, other.x - this->x); }

pxr::Pose pxr::Pose::rotate(float angle) const {
    return pxr::Pose(this->x * std::cos(angle) - this->y * std::sin(angle),
                        this->x * std::sin(angle) + this->y * std::cos(angle), this->theta);
}

std::string pxr::format_as(const pxr::Pose& pose) {
    // the double brackets become single brackets
    return fmt::format("pxr::Pose {{ x: {}, y: {}, theta: {} }}", pose.x, pose.y, pose.theta);
}
