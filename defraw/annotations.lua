---@meta

---@alias v3 { x: number, y: number, z: number}

---@class goraw
goraw = {}

---@param url url
---@return number
---@return number
---@return number
function goraw.get_position(url) end

---@param url url
---@param x number
---@param y number
---@param z number
function goraw.set_position(url, x, y, z) end

---@param url url
---@param t_out v3
function goraw.get_position_t(url, t_out) end

---@param url url
---@param t_in v3
function goraw.set_position_t(url, t_in) end

---@param url url
---@return number
function goraw.get_position_x(url) end

---@param url url
---@param x number
function goraw.set_position_x(url, x) end

---@param url url
---@return number
function goraw.get_position_y(url) end

---@param url url
---@param y number
function goraw.set_position_y(url, y) end

---@param url url
---@return number
function goraw.get_position_z(url) end

---@param url url
---@param z number
function goraw.set_position_z(url, z) end

---@param url url
---@return number
---@return number
---@return number
function goraw.get_scale(url) end

---@param url url
---@param x number
---@param y number
---@param z number
function goraw.set_scale(url, x, y, z) end

---@param url url
---@param t_out v3
function goraw.get_scale_t(url, t_out) end

---@param url url
---@param t_in v3
function goraw.set_scale_t(url, t_in) end

---@param url url
---@return number
function goraw.get_scale_x(url) end

---@param url url
---@param x number
function goraw.set_scale_x(url, x) end

---@param url url
---@return number
function goraw.get_scale_y(url) end

---@param url url
---@param y number
function goraw.set_scale_y(url, y) end

---@param url url
---@return number
function goraw.get_scale_z(url) end

---@param url url
---@param z number
function goraw.set_scale_z(url, z) end
