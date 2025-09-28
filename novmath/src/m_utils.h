// Math utilities adapted from Defold Engine
// Original source: /defold/engine/dlib/src/dlib/vmath.h
// Copyright 2020-2025 The Defold Foundation
// Copyright 2014-2020 King
// Copyright 2009-2014 Ragnar Svensson, Christian Murray
// Licensed under the Defold License version 1.0

#ifndef M_UTILS_H
#define M_UTILS_H

#include <cmath>
#include <cstdint>
#include <dmsdk/dlib/vmath.h>

namespace mUtils {

/**
 * Construct a quaternion from an axis index and angle
 * @param axis_index Index of the axis the quaternion should be a rotation
 * around (0=X, 1=Y, 2=Z)
 * @param radians Angle of rotation
 * @return Quaternion describing the rotation
 */
inline dmVMath::Quat QuatFromAngle(uint32_t axis_index, float radians) {
  dmVMath::Quat q(0, 0, 0, 1);
  float half_angle = 0.5f * radians;
  q.setElem(axis_index, std::sin(half_angle));
  q.setW(std::cos(half_angle));
  return q;
}

/**
 * Converts a quaternion into euler angles (r0, r1, r2), based on YZX rotation
 * order. To handle gimbal lock (singularity at r1 ~ +/- 90 degrees), the cut
 * off is at r0 = +/- 88.85 degrees. The provided quaternion is expected to be
 * normalized.
 * @param q0 first imaginary axis (x component)
 * @param q1 second imaginary axis (y component)
 * @param q2 third imaginary axis (z component)
 * @param q3 real part (w component)
 * @return Euler angles in degrees and the same order as the specified rotation
 * order
 */
inline dmVMath::Vector3 QuatToEuler(float q0, float q1, float q2, float q3) {
  const float DEG_FACTOR = 57.295779513f; // 180/PI

  // Early-out when the rotation axis is either X, Y or Z.
  // The reasons we make this distinction is that one-axis rotation is common
  // (and cheaper), especially around Z in 2D games
  uint8_t mask = (q2 != 0.f) << 2 | (q1 != 0.f) << 1 | (q0 != 0.f);
  switch (mask) {
  case 0b000:
    return dmVMath::Vector3(0.0f, 0.0f, 0.0f);
  case 0b001:
  case 0b010:
  case 0b100: {
    dmVMath::Vector3 r(0.0f, 0.0f, 0.0f);
    // the sum of the values yields one value, as the others are 0
    r.setElem(mask >> 1, std::atan2(q0 + q1 + q2, q3) * 2.0f * DEG_FACTOR);
    return r;
  }
  }

  // Implementation based on:
  // * http://en.wikipedia.org/wiki/Conversion_between_quaternions_and_Euler_angles
  // * http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToEuler/
  // * http://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToEuler/Quaternions.pdf
  const float limit =
      0.4999f; // gimbal lock limit, corresponds to 88.85 degrees
  float r0, r1, r2;
  float test = q0 * q1 + q2 * q3;
  if (test > limit) {
    r1 = 2.0f * std::atan2(q0, q3);
    r2 = M_PI_2; // PI/2
    r0 = 0.0f;
  } else if (test < -limit) {
    r1 = -2.0f * std::atan2(q0, q3);
    r2 = -M_PI_2; // -PI/2
    r0 = 0.0f;
  } else {
    float sq0 = q0 * q0;
    float sq1 = q1 * q1;
    float sq2 = q2 * q2;
    r1 = std::atan2(2.0f * q1 * q3 - 2.0f * q0 * q2,
                    1.0f - 2.0f * sq1 - 2.0f * sq2);
    r2 = std::asin(2.0f * test);
    r0 = std::atan2(2.0f * q0 * q3 - 2.0f * q1 * q2,
                    1.0f - 2.0f * sq0 - 2.0f * sq2);
  }
  return dmVMath::Vector3(r0, r1, r2) * DEG_FACTOR;
}

/**
 * Converts euler angles (x, y, z) in degrees into a quaternion
 * @param xyz Vector3 containing rotation angles in degrees (x, y, z)
 * @return Quat describing an equivalent rotation (231 (YZX) rotation sequence).
 */
inline dmVMath::Quat EulerToQuat(dmVMath::Vector3 xyz) {
  const float HALF_RAD_FACTOR =
      0.008726646f; // PI/360 (converts degrees to half-radians)

  // Early-out when the rotation axis is either X, Y or Z.
  // The reasons we make this distinction is that one-axis rotation is common
  // (and cheaper), especially around Z in 2D games
  uint8_t mask =
      (xyz.getZ() != 0.f) << 2 | (xyz.getY() != 0.f) << 1 | (xyz.getX() != 0.f);
  switch (mask) {
  case 0b000:
    return dmVMath::Quat(0.0f, 0.0f, 0.0f, 1.0f);
  case 0b001:
  case 0b010:
  case 0b100: {
    // the sum of the angles yields one angle, as the others are 0
    float ha = (xyz.getX() + xyz.getY() + xyz.getZ()) * HALF_RAD_FACTOR;
    dmVMath::Quat q(0.0f, 0.0f, 0.0f, std::cos(ha));
    q.setElem(mask >> 1, std::sin(ha));
    return q;
  }
  }

  // Implementation based on:
  // http://ntrs.nasa.gov/archive/nasa/casi.ntrs.nasa.gov/19770024290.pdf
  // Rotation sequence: 231 (YZX)
  float t1 = xyz.getY() * HALF_RAD_FACTOR;
  float t2 = xyz.getZ() * HALF_RAD_FACTOR;
  float t3 = xyz.getX() * HALF_RAD_FACTOR;

  float c1 = std::cos(t1);
  float s1 = std::sin(t1);
  float c2 = std::cos(t2);
  float s2 = std::sin(t2);
  float c3 = std::cos(t3);
  float s3 = std::sin(t3);
  float c1_c2 = c1 * c2;
  float s2_s3 = s2 * s3;

  dmVMath::Quat quat;
  quat.setW(-s1 * s2_s3 + c1_c2 * c3);
  quat.setX(s1 * s2 * c3 + s3 * c1_c2);
  quat.setY(s1 * c2 * c3 + s2_s3 * c1);
  quat.setZ(-s1 * s3 * c2 + s2 * c1 * c3);
  return quat;
}

} // namespace mUtils

#endif // M_UTILS_H