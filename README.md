# NOVMATH

## Features

### Game Object Transformations

The extension provides comprehensive functions for manipulating game object transforms:

#### Position

- `get_position_r(url)`: Returns x, y, z position components
- `set_position_r(url, x, y, z)`: Sets position using individual components
- `get_position_t(url, t_out)`: Gets position into a table
- `set_position_t(url, t_in)`: Sets position from a table
- Individual component getters/setters for x, y, z

#### Scale

- `get_scale_r(url)`: Returns x, y, z scale components
- `set_scale_r(url, x, y, z)`: Sets scale using individual components
- `get_scale_t(url, t_out)`: Gets scale into a table
- `set_scale_t(url, t_in)`: Sets scale from a table
- Individual component getters/setters for x, y, z

#### Rotation (Euler Angles)

- `get_euler_r(url)`: Returns x, y, z rotation components
- `set_euler_r(url, x, y, z)`: Sets rotation using individual components
- `get_euler_t(url, t_out)`: Gets rotation into a table
- `set_euler_t(url, t_in)`: Sets rotation from a table
- Individual component getters/setters for x, y, z

### World Space Transformations

The extension also provides world space variants of all transform operations:

- World position getters
- World scale getters
- World rotation (euler) getters

## Usage

### Basic Usage

```lua
-- Get position components
local x, y, z = go.get_position_r("/game_object")

-- Set position using components
go.set_position_r("/game_object", 10, 20, 30)

-- Get position into a table
local pos = {x = 0, y = 0, z = 0}
go.get_position_t("/game_object", pos)
```

### Type Safety

The extension includes Lua type annotations for better IDE support and type checking.

## Installation

```bash
https://github.com/itmurker/novmath/archive/refs/tags/0.1.zip
```

## License

MIT License
