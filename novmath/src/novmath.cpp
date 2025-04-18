#include <dmsdk/sdk.h>
#include "novmath.h"
#include "novmath_go.h"

static const luaL_reg go_functions[] = {

    {"get_position_r", GO_GetPositionR},
    {"set_position_r", GO_SetPositionR},
    {"get_position_t", GO_GetPositionT},
    {"set_position_t", GO_SetPositionT},
    {"get_position_x", GO_GetPositionX},
    {"set_position_x", GO_SetPositionX},
    {"get_position_y", GO_GetPositionY},
    {"set_position_y", GO_SetPositionY},
    {"get_position_z", GO_GetPositionZ},
    {"set_position_z", GO_SetPositionZ},
    // {"animate_position", GO_AnimatePosition},
    // {"animate_position_t", GO_AnimatePositionT},
    // {"animate_position_x", GO_AnimatePositionX},
    // {"animate_position_y", GO_AnimatePositionY},
    // {"animate_position_z", GO_AnimatePositionZ},

    {"get_scale_r", GO_GetScaleR},
    {"set_scale_r", GO_SetScaleR},
    {"get_scale_t", GO_GetScaleT},
    {"set_scale_t", GO_SetScaleT},
    {"get_scale_x", GO_GetScaleX},
    {"set_scale_x", GO_SetScaleX},
    {"get_scale_y", GO_GetScaleY},
    {"set_scale_y", GO_SetScaleY},
    {"get_scale_z", GO_GetScaleZ},
    {"set_scale_z", GO_SetScaleZ},
    // {"animate_scale", GO_AnimateScale},
    // {"animate_scale_t", GO_AnimateScaleT},
    // {"animate_scale_x", GO_AnimateScaleX},
    // {"animate_scale_y", GO_AnimateScaleY},
    // {"animate_scale_z", GO_AnimateScaleZ},

    {"get_euler_r", GO_GetEulerR},
    {"set_euler_r", GO_SetEulerR},
    {"get_euler_t", GO_GetEulerT},
    {"set_euler_t", GO_SetEulerT},
    {"get_euler_x", GO_GetEulerX},
    {"set_euler_x", GO_SetEulerX},
    {"get_euler_y", GO_GetEulerY},
    {"set_euler_y", GO_SetEulerY},
    {"get_euler_z", GO_GetEulerZ},
    {"set_euler_z", GO_SetEulerZ},
    // {"animate_euler", GO_AnimateEuler},
    // {"animate_euler_t", GO_AnimateEulerT},
    // {"animate_euler_x", GO_AnimateEulerX},
    // {"animate_euler_y", GO_AnimateEulerY},
    // {"animate_euler_z", GO_AnimateEulerZ},

    {"get_world_position_r", GO_GetWorldPositionR},
    {"get_world_position_t", GO_GetWorldPositionT},
    {"get_world_position_x", GO_GetWorldPositionX},
    {"get_world_position_y", GO_GetWorldPositionY},
    {"get_world_position_z", GO_GetWorldPositionZ},

    {"get_world_scale_r", GO_GetWorldScaleR},
    {"get_world_scale_t", GO_GetWorldScaleT},
    {"get_world_scale_x", GO_GetWorldScaleX},
    {"get_world_scale_y", GO_GetWorldScaleY},
    {"get_world_scale_z", GO_GetWorldScaleZ},

    {"get_world_euler_r", GO_GetWorldEulerR},
    {"get_world_euler_t", GO_GetWorldEulerT},
    {"get_world_euler_x", GO_GetWorldEulerX},
    {"get_world_euler_y", GO_GetWorldEulerY},
    {"get_world_euler_z", GO_GetWorldEulerZ},

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
    luaL_register(params->m_L, "go", go_functions);
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