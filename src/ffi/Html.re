[@bs.val]
external document : Dom.document = "";

[@bs.return null_to_opt] [@bs.send]
external getElementById : (Dom.document, string) => option('a) = "";

[@bs.val]
external requestAnimationFrame : (unit => unit) => unit = "";
