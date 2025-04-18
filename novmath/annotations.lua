---@meta

---@class go
go = {}

---@param url url
---@return number
---@return number
---@return number
function go.get_position_r(url) end

---@param url url
---@param x number
---@param y number
---@param z number
function go.set_position_r(url, x, y, z) end

---@param url url
---@param t_out { x: number, y: number, z: number }
function go.get_position_t(url, t_out) end

---@param url url
---@param t_in { x: number, y: number, z: number }
function go.set_position_t(url, t_in) end

---@param url url
---@return number
function go.get_position_x(url) end

---@param url url
---@param x number
function go.set_position_x(url, x) end

---@param url url
---@return number
function go.get_position_y(url) end

---@param url url
---@param y number
function go.set_position_y(url, y) end

---@param url url
---@return number
function go.get_position_z(url) end

---@param url url
---@param z number
function go.set_position_z(url, z) end

---@param url url
---@return number
---@return number
---@return number
function go.get_scale_r(url) end

---@param url url
---@param x number
---@param y number
---@param z number
function go.set_scale_r(url, x, y, z) end

---@param url url
---@param t_out { x: number, y: number, z: number }
function go.get_scale_t(url, t_out) end

---@param url url
---@param t_in { x: number, y: number, z: number }
function go.set_scale_t(url, t_in) end

---@param url url
---@return number
function go.get_scale_x(url) end

---@param url url
---@param x number
function go.set_scale_x(url, x) end

---@param url url
---@return number
function go.get_scale_y(url) end

---@param url url
---@param y number
function go.set_scale_y(url, y) end

---@param url url
---@return number
function go.get_scale_z(url) end

---@param url url
---@param z number
function go.set_scale_z(url, z) end

---@param url url
---@return number
---@return number
---@return number
function go.get_euler_r(url) end

---@param url url
---@param x number
---@param y number
---@param z number
function go.set_euler_r(url, x, y, z) end

---@param url url
---@param t_out { x: number, y: number, z: number }
function go.get_euler_t(url, t_out) end

---@param url url
---@param t_in { x: number, y: number, z: number }
function go.set_euler_t(url, t_in) end

---@param url url
---@return number
function go.get_euler_x(url) end

---@param url url
---@param x number
function go.set_euler_x(url, x) end

---@param url url
---@return number
function go.get_euler_y(url) end

---@param url url
---@param y number
function go.set_euler_y(url, y) end

---@param url url
---@return number
function go.get_euler_z(url) end

---@param url url
---@param z number
function go.set_euler_z(url, z) end

---@param url url
---@return number
---@return number
---@return number
function go.get_world_position_r(url) end

---@param url url
---@param t_out { x: number, y: number, z: number }
function go.get_world_position_t(url, t_out) end

---@param url url
---@return number
function go.get_world_position_x(url) end

---@param url url
---@return number
function go.get_world_position_y(url) end

---@param url url
---@return number
function go.get_world_position_z(url) end

---@param url url
---@return number
---@return number
---@return number
function go.get_world_scale_r(url) end

---@param url url
---@param t_out { x: number, y: number, z: number }
function go.get_world_scale_t(url, t_out) end

---@param url url
---@return number
function go.get_world_scale_x(url) end

---@param url url
---@return number
function go.get_world_scale_y(url) end

---@param url url
---@return number
function go.get_world_scale_z(url) end

---@param url url
---@return number
---@return number
---@return number
function go.get_world_euler_r(url) end

---@param url url
---@param t_out { x: number, y: number, z: number }
function go.get_world_euler_t(url, t_out) end

---@param url url
---@return number
function go.get_world_euler_x(url) end

---@param url url
---@return number
function go.get_world_euler_y(url) end

---@param url url
---@return number
function go.get_world_euler_z(url) end
