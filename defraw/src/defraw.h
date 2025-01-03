// https://github.com/Lerg/extension-directories/blob/f1e8388fff484e588d36c1ce4e2d22663e2c676d/directories/src/extension.h#L1-L28

#ifndef DEFRAW_EXTENSION_H
#define DEFRAW_EXTENSION_H

// The name of the extension affects C++/ObjC exported symbols, Lua module name and Java package name.
#define EXTENSION_NAME defraw

// Convert extension name to C const string.
#define STRINGIFY(s) #s
#define STRINGIFY_EXPANDED(s) STRINGIFY(s)
#define EXTENSION_NAME_STRING STRINGIFY_EXPANDED(EXTENSION_NAME)

// Each extension must have unique exported symbols. Construct function names based on the extension name.
#define FUNCTION_NAME(extension_name, function_name) Extension_##extension_name##_##function_name
#define FUNCTION_NAME_EXPANDED(extension_name, function_name) FUNCTION_NAME(extension_name, function_name)

#define APP_INITIALIZE FUNCTION_NAME_EXPANDED(EXTENSION_NAME, AppInitialize)
#define APP_FINALIZE FUNCTION_NAME_EXPANDED(EXTENSION_NAME, AppFinalize)
#define INITIALIZE FUNCTION_NAME_EXPANDED(EXTENSION_NAME, Initialize)
#define UPDATE FUNCTION_NAME_EXPANDED(EXTENSION_NAME, Update)
#define FINALIZE FUNCTION_NAME_EXPANDED(EXTENSION_NAME, Finalize)

#define DECLARE_DEFOLD_EXTENSION DM_DECLARE_EXTENSION(EXTENSION_NAME, EXTENSION_NAME_STRING, APP_INITIALIZE, APP_FINALIZE, INITIALIZE, UPDATE, 0, FINALIZE)

#endif