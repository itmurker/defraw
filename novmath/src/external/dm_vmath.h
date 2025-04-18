// dm_vmath.h

#ifndef DM_VMATH_H
#define DM_VMATH_H

#include <dmsdk/sdk.h>

namespace dmVMath
{
    Quat QuatFromAngle(uint32_t axis_index, float radians);
    Vector3 QuatToEuler(float q0, float q1, float q2, float q3);
    Quat EulerToQuat(Vector3 xyz);
}

#endif // DM_VMATH_H
