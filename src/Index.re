open Html;
open Canvas;
open Config;
open Utils;
open Universe;

let canvas_wrapper = getElementById(document, canvas_id);
let canvas: canvas =
  switch (canvas_wrapper) {
  | Some(element) => element
  | None => failwith("canvas id: " ++ canvas_id ++ " not found")
  };

let ctx = getContext(canvas, `use2d);
let canvasJs = canvasElementToJsObj(canvas);
let ctxJS = context2dToJsObj(ctx);

canvasJs##width #= get_calculate_value_with_border(canvas_width);
canvasJs##height #= get_calculate_value_with_border(canvas_height);

drawTable(~ctx);

set_initial_cells();

let rec render_loop = () => {
  ctxJS##clearRect(0, 0, canvasJs##width, canvasJs##height);

  draw_cells(~ctx);

  requestAnimationFrame(render_loop);
};

requestAnimationFrame(render_loop);