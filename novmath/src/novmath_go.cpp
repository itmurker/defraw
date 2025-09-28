#include "dmsdk/dlib/vmath.h"
#include "dmsdk/gameobject/gameobject.h"
#include "m_utils.h"
#include <dmsdk/sdk.h>

static inline dmVMath::Vector3 CheckV3R(lua_State *L, int index) {
  lua_Number x = luaL_checknumber(L, index);
  lua_Number y = luaL_checknumber(L, index + 1);
  lua_Number z = luaL_checknumber(L, index + 2);
  return dmVMath::Vector3(x, y, z);
}

static inline int PushV3R(lua_State *L, const dmVMath::Vector3 &v) {
  lua_pushnumber(L, v.getX());
  lua_pushnumber(L, v.getY());
  lua_pushnumber(L, v.getZ());
  return 3;
}

static inline dmVMath::Vector3 CheckV3T(lua_State *L, int index) {
  lua_getfield(L, index, "x");
  lua_getfield(L, index, "y");
  lua_getfield(L, index, "z");

  lua_Number x = luaL_checknumber(L, -3);
  lua_Number y = luaL_checknumber(L, -2);
  lua_Number z = luaL_checknumber(L, -1);

  lua_pop(L, 3);
  return dmVMath::Vector3(x, y, z);
}

static inline int PushV3T(lua_State *L, int index, const dmVMath::Vector3 &v) {
  lua_pushnumber(L, v.getX());
  lua_setfield(L, index, "x");
  lua_pushnumber(L, v.getY());
  lua_setfield(L, index, "y");
  lua_pushnumber(L, v.getZ());
  lua_setfield(L, index, "z");
  return 0;
}

static inline dmVMath::Vector3 QuatToEuler(dmVMath::Quat q) {
  return mUtils::QuatToEuler(q.getX(), q.getY(), q.getZ(), q.getW());
}

#define GO_GET_POSITION(instance)                                              \
  dmVMath::Vector3(dmGameObject::GetPosition(instance))
#define GO_SET_POSITION(instance, position)                                    \
  dmGameObject::SetPosition(instance, dmVMath::Point3(position))
#define GO_GET_SCALE(instance) dmGameObject::GetScale(instance)
#define GO_SET_SCALE(instance, scale) dmGameObject::SetScale(instance, scale)
#define GO_GET_EULER(instance) QuatToEuler(dmGameObject::GetRotation(instance))
#define GO_SET_EULER(instance, rotation)                                       \
  dmGameObject::SetRotation(instance, mUtils::EulerToQuat(rotation))

#define GO_GET_WORLD_POSITION(instance)                                        \
  dmVMath::Vector3(dmGameObject::GetWorldPosition(instance))
#define GO_GET_WORLD_SCALE(instance) dmGameObject::GetWorldScale(instance)
#define GO_GET_WORLD_EULER(instance)                                           \
  QuatToEuler(dmGameObject::GetWorldRotation(instance))

#define GO_GET_PROP_R(propertyname, get_prop)                                  \
  int GO_Get##propertyname##R(lua_State *L) {                                  \
    dmGameObject::Instance *instance = dmScript::CheckGOInstance(L, 1);        \
    dmVMath::Vector3 value = get_prop(instance);                               \
    return PushV3R(L, value);                                                  \
  }

#define GO_SET_PROP_R(propertyname, set_prop)                                  \
  int GO_Set##propertyname##R(lua_State *L) {                                  \
    dmGameObject::Instance *instance = dmScript::CheckGOInstance(L, 1);        \
    dmVMath::Vector3 value = CheckV3R(L, 2);                                   \
    set_prop(instance, value);                                                 \
    return 0;                                                                  \
  }

#define GO_GET_PROP_T(propertyname, get_prop)                                  \
  int GO_Get##propertyname##T(lua_State *L) {                                  \
    dmGameObject::Instance *instance = dmScript::CheckGOInstance(L, 1);        \
    dmVMath::Vector3 value = get_prop(instance);                               \
    return PushV3T(L, 2, value);                                               \
  }

#define GO_SET_PROP_T(propertyname, set_prop)                                  \
  int GO_Set##propertyname##T(lua_State *L) {                                  \
    dmGameObject::Instance *instance = dmScript::CheckGOInstance(L, 1);        \
    dmVMath::Vector3 value = CheckV3T(L, 2);                                   \
    set_prop(instance, value);                                                 \
    return 0;                                                                  \
  }

#define GO_GET_PROP_N(propertyname, n, get_prop)                               \
  int GO_Get##propertyname##n(lua_State *L) {                                  \
    dmGameObject::Instance *instance = dmScript::CheckGOInstance(L, 1);        \
    lua_Number value = get_prop(instance).get##n();                            \
    lua_pushnumber(L, value);                                                  \
    return 1;                                                                  \
  }

#define GO_SET_PROP_N(propertyname, n, get_prop, set_prop)                     \
  int GO_Set##propertyname##n(lua_State *L) {                                  \
    dmGameObject::Instance *instance = dmScript::CheckGOInstance(L, 1);        \
    lua_Number value = luaL_checknumber(L, 2);                                 \
    dmVMath::Vector3 temp = get_prop(instance);                                \
    temp.set##n(value);                                                        \
    set_prop(instance, temp);                                                  \
    return 0;                                                                  \
  }

GO_GET_PROP_R(Position, GO_GET_POSITION)
GO_SET_PROP_R(Position, GO_SET_POSITION)
GO_GET_PROP_T(Position, GO_GET_POSITION)
GO_SET_PROP_T(Position, GO_SET_POSITION)
GO_GET_PROP_N(Position, X, GO_GET_POSITION)
GO_SET_PROP_N(Position, X, GO_GET_POSITION, GO_SET_POSITION)
GO_GET_PROP_N(Position, Y, GO_GET_POSITION)
GO_SET_PROP_N(Position, Y, GO_GET_POSITION, GO_SET_POSITION)
GO_GET_PROP_N(Position, Z, GO_GET_POSITION)
GO_SET_PROP_N(Position, Z, GO_GET_POSITION, GO_SET_POSITION)

GO_GET_PROP_R(Scale, GO_GET_SCALE)
GO_SET_PROP_R(Scale, GO_SET_SCALE)
GO_GET_PROP_T(Scale, GO_GET_SCALE)
GO_SET_PROP_T(Scale, GO_SET_SCALE)
GO_GET_PROP_N(Scale, X, GO_GET_SCALE)
GO_SET_PROP_N(Scale, X, GO_GET_SCALE, GO_SET_SCALE)
GO_GET_PROP_N(Scale, Y, GO_GET_SCALE)
GO_SET_PROP_N(Scale, Y, GO_GET_SCALE, GO_SET_SCALE)
GO_GET_PROP_N(Scale, Z, GO_GET_SCALE)
GO_SET_PROP_N(Scale, Z, GO_GET_SCALE, GO_SET_SCALE)

GO_GET_PROP_R(Euler, GO_GET_EULER)
GO_SET_PROP_R(Euler, GO_SET_EULER)
GO_GET_PROP_T(Euler, GO_GET_EULER)
GO_SET_PROP_T(Euler, GO_SET_EULER)
GO_GET_PROP_N(Euler, X, GO_GET_EULER)
GO_SET_PROP_N(Euler, X, GO_GET_EULER, GO_SET_EULER)
GO_GET_PROP_N(Euler, Y, GO_GET_EULER)
GO_SET_PROP_N(Euler, Y, GO_GET_EULER, GO_SET_EULER)
GO_GET_PROP_N(Euler, Z, GO_GET_EULER)
GO_SET_PROP_N(Euler, Z, GO_GET_EULER, GO_SET_EULER)

GO_GET_PROP_R(WorldPosition, GO_GET_WORLD_POSITION)
GO_GET_PROP_T(WorldPosition, GO_GET_WORLD_POSITION)
GO_GET_PROP_N(WorldPosition, X, GO_GET_WORLD_POSITION)
GO_GET_PROP_N(WorldPosition, Y, GO_GET_WORLD_POSITION)
GO_GET_PROP_N(WorldPosition, Z, GO_GET_WORLD_POSITION)

GO_GET_PROP_R(WorldScale, GO_GET_WORLD_SCALE)
GO_GET_PROP_T(WorldScale, GO_GET_WORLD_SCALE)
GO_GET_PROP_N(WorldScale, X, GO_GET_WORLD_SCALE)
GO_GET_PROP_N(WorldScale, Y, GO_GET_WORLD_SCALE)
GO_GET_PROP_N(WorldScale, Z, GO_GET_WORLD_SCALE)

GO_GET_PROP_R(WorldEuler, GO_GET_WORLD_EULER)
GO_GET_PROP_T(WorldEuler, GO_GET_WORLD_EULER)
GO_GET_PROP_N(WorldEuler, X, GO_GET_WORLD_EULER)
GO_GET_PROP_N(WorldEuler, Y, GO_GET_WORLD_EULER)
GO_GET_PROP_N(WorldEuler, Z, GO_GET_WORLD_EULER)

#undef GO_GET_POSITION
#undef GO_SET_POSITION
#undef GO_GET_SCALE
#undef GO_SET_SCALE
#undef GO_GET_EULER
#undef GO_SET_EULER

#undef GO_GET_WORLD_POSITION
#undef GO_GET_WORLD_SCALE
#undef GO_GET_WORLD_EULER

#undef GO_PROP_R
#undef GO_PROP_T
#undef GO_PROP_N