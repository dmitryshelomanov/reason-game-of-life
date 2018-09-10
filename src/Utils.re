open Config;

let get_calculate_value_with_border = (value: int) =>
  value * (cell_size + 1) + 1

let get_index = (row, column) =>
  row * canvas_width + column;
