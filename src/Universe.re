open Canvas;
open Config;
open Utils;
open Cell;

let cells: ref(array(life)) = ref([||]);

let set_initial_cells = () =>
  for (idx in 0 to canvas_height * canvas_width) {
    let life_status = Js_math.random() > 0.5 ? Alive : Dead;

    Js_array.push(life_status, cells^);
  };

let set_cell = value => value->Js_array.push(cells^);

let drawTable = (~ctx: context) => {
  let jsCtx = context2dToJsObj(ctx);
  let get_pos_for_grid = value =>
    value |> get_calculate_value_with_border |> float_of_int;

  for (row in 0 to canvas_height) {
    let pos_y = get_pos_for_grid(row);
    let pos_x = get_pos_for_grid(canvas_width);

    jsCtx##moveTo(0.0, pos_y);
    jsCtx##lineTo(pos_x, pos_y);
  };

  for (col in 0 to canvas_width) {
    let pos_x = get_pos_for_grid(col);
    let pos_y = get_pos_for_grid(canvas_height);

    jsCtx##moveTo(pos_x, 0.0);
    jsCtx##lineTo(pos_x, pos_y);
  };

  jsCtx##stroke();
};

let draw_cells = (~ctx: context) => {
  let jsCtx = context2dToJsObj(ctx);
  let next_generation = Array.copy(cells^);

  for (row in 0 to canvas_height - 1) {
    for (col in 0 to canvas_width - 1) {
      let idx = get_index(row, col);
      let organism = cells^[idx];

      switch (organism) {
      | Dead => {}
      | Alive =>
        jsCtx##fillRect(
          get_calculate_value_with_border(col),
          get_calculate_value_with_border(row),
          cell_size,
          cell_size,
        )
      };

      let neighbord_count = get_neighbord_count(~cells=cells^, ~row, ~col);
      let next_cell =
        switch (organism, neighbord_count) {
        | (Alive, x) when x < 2 => Dead
        | (Alive, x) when x > 3 => Dead
        | (Alive, 2 | 3) => Alive
        | (Dead, 3) => Alive
        | (otherwise, _) => otherwise
        };

      next_generation[idx] = next_cell;
    };
  };

  cells := next_generation;
  jsCtx##stroke();
};
