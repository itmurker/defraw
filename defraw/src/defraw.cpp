#include "defraw.h"
#include "goraw.h"
#include <dmsdk/sdk.h>

static const luaL_reg go_functions[] = {
    {"get_position", GO_GetPosition},
    {"set_position", GO_SetPosition},
    {"get_position_t", GO_GetPositionT},
    {"set_position_t", GO_SetPositionT},
    {"get_position_x", GO_GetPositionX},
    {"set_position_x", GO_SetPositionX},
    {"get_position_y", GO_GetPositionY},
    {"set_position_y", GO_SetPositionY},
    {"get_position_z", GO_GetPositionZ},
    {"set_position_z", GO_SetPositionZ},
    {"get_scale", GO_GetScale},
    {"set_scale", GO_SetScale},
    {"get_scale_t", GO_GetScaleT},
    {"set_scale_t", GO_SetScaleT},
    {"get_scale_x", GO_GetScaleX},
    {"set_scale_x", GO_SetScaleX},
    {"get_scale_y", GO_GetScaleY},
    {"set_scale_y", GO_SetScaleY},
    {"get_scale_z", GO_GetScaleZ},
    {"set_scale_z", GO_SetScaleZ},
    // {"get_euler", GO_GetEuler},
    // {"set_euler", GO_SetEuler},
    // {"get_euler_x", GO_GetEulerX},
    // {"set_euler_x", GO_SetEulerX},
    // {"get_euler_y", GO_GetEulerY},
    // {"set_euler_y", GO_SetEulerY},
    // {"get_euler_z", GO_GetEulerZ},
    // {"set_euler_z", GO_SetEulerZ},
    {0, 0}};

dmExtension::Result APP_INITIALIZE(dmExtension::AppParams *params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result APP_FINALIZE(dmExtension::AppParams *params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result INITIALIZE(dmExtension::Params *params)
{
    luaL_register(params->m_L, "goraw", go_functions);
    lua_pop(params->m_L, 1);
    dmLogInfo("Registered '%s' Extension", EXTENSION_NAME_STRING);
    return dmExtension::RESULT_OK;
}

dmExtension::Result UPDATE(dmExtension::Params *params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result FINALIZE(dmExtension::Params *params)
{
    return dmExtension::RESULT_OK;
}

DECLARE_DEFOLD_EXTENSION