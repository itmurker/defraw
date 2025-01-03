#include <dmsdk/sdk.h>

#define GO_GET(propertyname, propertytype)                                          \
    int GO_Get##propertyname(lua_State *L)                                          \
    {                                                                               \
        dmGameObject::Instance *instance = dmScript::CheckGOInstance(L, 1);         \
        dmVMath::propertytype property = dmGameObject::Get##propertyname(instance); \
        lua_pushnumber(L, property.getX());                                         \
        lua_pushnumber(L, property.getY());                                         \
        lua_pushnumber(L, property.getZ());                                         \
        return 3;                                                                   \
    }

#define GO_SET(propertyname, propertytype)                                         \
    int GO_Set##propertyname(lua_State *L)                                         \
    {                                                                              \
        dmGameObject::Instance *instance = dmScript::CheckGOInstance(L, 1);        \
        lua_Number x = luaL_checknumber(L, 2);                                     \
        lua_Number y = luaL_checknumber(L, 3);                                     \
        lua_Number z = luaL_checknumber(L, 4);                                     \
        dmGameObject::Set##propertyname(instance, dmVMath::propertytype(x, y, z)); \
        return 0;                                                                  \
    }

#define GO_GET_N(propertyname, propertytype, n)                                     \
    int GO_Get##propertyname##n(lua_State *L)                                       \
    {                                                                               \
        dmGameObject::Instance *instance = dmScript::CheckGOInstance(L, 1);         \
        dmVMath::propertytype property = dmGameObject::Get##propertyname(instance); \
        lua_pushnumber(L, property.get##n());                                       \
        return 1;                                                                   \
    }

#define GO_SET_N(propertyname, propertytype, n)                                     \
    int GO_Set##propertyname##n(lua_State *L)                                       \
    {                                                                               \
        dmGameObject::Instance *instance = dmScript::CheckGOInstance(L, 1);         \
        dmVMath::propertytype property = dmGameObject::Get##propertyname(instance); \
        property.set##n(luaL_checknumber(L, 2));                                    \
        dmGameObject::Set##propertyname(instance, property);                        \
        return 0;                                                                   \
    }

GO_GET(Position, Point3)
GO_SET(Position, Point3)
GO_GET_N(Position, Point3, X)
GO_SET_N(Position, Point3, X)
GO_GET_N(Position, Point3, Y)
GO_SET_N(Position, Point3, Y)
GO_GET_N(Position, Point3, Z)
GO_SET_N(Position, Point3, Z)
GO_GET(Scale, Vector3)
GO_SET(Scale, Vector3)
GO_GET_N(Scale, Vector3, X)
GO_SET_N(Scale, Vector3, X)
GO_GET_N(Scale, Vector3, Y)
GO_SET_N(Scale, Vector3, Y)
GO_GET_N(Scale, Vector3, Z)
GO_SET_N(Scale, Vector3, Z)

#undef GO_GET
#undef GO_SET
#undef GO_GET_N
#undef GO_SET_N
