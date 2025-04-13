#ifndef GO_EXT
#define GO_EXT

#include <dmsdk/sdk.h>

int GO_GetPositionR(lua_State *L);
int GO_SetPositionR(lua_State *L);
int GO_GetPositionT(lua_State *L);
int GO_SetPositionT(lua_State *L);
int GO_GetPositionX(lua_State *L);
int GO_SetPositionX(lua_State *L);
int GO_GetPositionY(lua_State *L);
int GO_SetPositionY(lua_State *L);
int GO_GetPositionZ(lua_State *L);
int GO_SetPositionZ(lua_State *L);
int GO_AnimatePosition(lua_State *L);
int GO_AnimatePositionT(lua_State *L);
int GO_AnimatePositionX(lua_State *L);
int GO_AnimatePositionY(lua_State *L);
int GO_AnimatePositionZ(lua_State *L);

int GO_GetScaleR(lua_State *L);
int GO_SetScaleR(lua_State *L);
int GO_GetScaleT(lua_State *L);
int GO_SetScaleT(lua_State *L);
int GO_GetScaleX(lua_State *L);
int GO_SetScaleX(lua_State *L);
int GO_GetScaleY(lua_State *L);
int GO_SetScaleY(lua_State *L);
int GO_GetScaleZ(lua_State *L);
int GO_SetScaleZ(lua_State *L);
int GO_AnimateScale(lua_State *L);
int GO_AnimateScaleT(lua_State *L);
int GO_AnimateScaleX(lua_State *L);
int GO_AnimateScaleY(lua_State *L);
int GO_AnimateScaleZ(lua_State *L);

int GO_GetEulerR(lua_State *L);
int GO_SetEulerR(lua_State *L);
int GO_GetEulerT(lua_State *L);
int GO_SetEulerT(lua_State *L);
int GO_GetEulerX(lua_State *L);
int GO_SetEulerX(lua_State *L);
int GO_GetEulerY(lua_State *L);
int GO_SetEulerY(lua_State *L);
int GO_GetEulerZ(lua_State *L);
int GO_SetEulerZ(lua_State *L);
int GO_AnimateEuler(lua_State *L);
int GO_AnimateEulerT(lua_State *L);
int GO_AnimateEulerX(lua_State *L);
int GO_AnimateEulerY(lua_State *L);
int GO_AnimateEulerZ(lua_State *L);

int GO_GetWorldPositionR(lua_State *L);
int GO_GetWorldPositionT(lua_State *L);
int GO_GetWorldPositionX(lua_State *L);
int GO_GetWorldPositionY(lua_State *L);
int GO_GetWorldPositionZ(lua_State *L);

int GO_GetWorldScaleR(lua_State *L);
int GO_GetWorldScaleT(lua_State *L);
int GO_GetWorldScaleX(lua_State *L);
int GO_GetWorldScaleY(lua_State *L);
int GO_GetWorldScaleZ(lua_State *L);

int GO_GetWorldEulerR(lua_State *L);
int GO_GetWorldEulerT(lua_State *L);
int GO_GetWorldEulerX(lua_State *L);
int GO_GetWorldEulerY(lua_State *L);
int GO_GetWorldEulerZ(lua_State *L);

#endif