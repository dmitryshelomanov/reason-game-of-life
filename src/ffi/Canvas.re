type canvas;
type context;

[@bs.send]
external getContext : (
  canvas,
  [@bs.string] [
    | [@bs.as "2d"] `use2d
  ]
) => context = "";

external canvasElementToJsObj : canvas => Js.t({..}) = "%identity";

external context2dToJsObj : context => Js.t({..}) = "%identity";
