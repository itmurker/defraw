#ifndef GORAW
#define GORAW

#include <dmsdk/sdk.h>

int GO_GetPosition(lua_State *L);
int GO_SetPosition(lua_State *L);
int GO_GetPositionT(lua_State *L);
int GO_SetPositionT(lua_State *L);
int GO_GetPositionX(lua_State *L);
int GO_SetPositionX(lua_State *L);
int GO_GetPositionY(lua_State *L);
int GO_SetPositionY(lua_State *L);
int GO_GetPositionZ(lua_State *L);
int GO_SetPositionZ(lua_State *L);

int GO_GetScale(lua_State *L);
int GO_SetScale(lua_State *L);
int GO_GetScaleT(lua_State *L);
int GO_SetScaleT(lua_State *L);
int GO_GetScaleX(lua_State *L);
int GO_SetScaleX(lua_State *L);
int GO_GetScaleY(lua_State *L);
int GO_SetScaleY(lua_State *L);
int GO_GetScaleZ(lua_State *L);
int GO_SetScaleZ(lua_State *L);

int GO_GetEuler(lua_State *L);
int GO_SetEuler(lua_State *L);
int GO_GetEulerX(lua_State *L);
int GO_SetEulerX(lua_State *L);
int GO_GetEulerY(lua_State *L);
int GO_SetEulerY(lua_State *L);
int GO_GetEulerZ(lua_State *L);
int GO_SetEulerZ(lua_State *L);

#endif