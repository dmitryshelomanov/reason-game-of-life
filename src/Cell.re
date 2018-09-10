open Config;
open Utils;

type life =
  | Dead
  | Alive;

let get_count_by_life = (organism: life) =>
  switch (organism) {
  | Dead => 0
  | Alive => 1
  };

let get_neighbord_count = (~cells: array(life), ~row: int, ~col: int) => {
  let counter = ref(0);
  let delta_row = [|canvas_height - 1, 0, 1|];
  let delta_col = [|canvas_width - 1, 0, 1|];

  for (dr in 0 to 2) {
    for (dc in 0 to 2) {
      if (delta_row[dr] === 0 && delta_col[dc] === 0) {
        ();
      } else {
        let idx =
          get_index(
            (row + delta_row[dr]) mod canvas_height,
            (col + delta_col[dc]) mod canvas_width,
          );

        counter := (cells[idx] |> get_count_by_life) + counter^;
      };
    };
  };

  counter^;
};
